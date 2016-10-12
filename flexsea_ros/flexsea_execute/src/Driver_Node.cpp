#include "Driver_Node.h"
#include "main.h"

// Class Functions source ---------------------

// Initialization
Driver_Node::Driver_Node(){
	
	// Initial Values
	usb_is_open     = false;
    //serialport_name = "/dev/ttyACM0";  --> now loaded as ROS param

    // Flexsea-comm params
    active_slave_1_index = 0       ;
    active_slave_1       = 40      ; // default value is for execute_1 --> change the config file

    // TODO load all from a config file of ROS params

	
    // Init Sub-pub-timers
    sub   = n.subscribe("u", 1000, &Driver_Node::input_callback, this );
    pub   = n.advertise<flexsea_execute::outputs>("y", 1000);
    timer = n.createTimer( ros::Duration(0.002), &Driver_Node::timer_callback, this );
	
	// Load ROS params
	load_ROS_param();
	
	//Open USB port
	com_init_tries =  5;
	com_init_delay =  1; // sec   : delay beetween connection trial
	com_read_delay = 20; // msec : max delay to wait for data
	open_USB_port();

    // Input msg data
    ctrl_mode     = 0;
    ctrl_gains[0] = 10;
    ctrl_gains[1] = 0;
    ctrl_gains[2] = 0;
    ctrl_setpoint = 0;
    trap_mode     = false;
    trap_values[3] = 50000;
    trap_values[4] = 50000;
    brake_pwm      = 0;


    // Set postion ctl mode
    set_position_ctl();
    pos_ref = 0;
}



void Driver_Node::timer_callback(const ros::TimerEvent&){
	
    // Request, read and decode data
    read_all_data();
	
    // Convert to ROS msg format and publish
    publish_sensor_msg();

}



void Driver_Node::input_callback(const flexsea_execute::inputs u_msg){

    // Print received cmd
    if (verbose){
        ROS_INFO("Driver Cmd: u=%d mode=%d", (int)u_msg.ctrl_setpoint, (int)u_msg.ctrl_mode);
    }

    // Request new control mode & gains if changed
    update_ctrl_if_needed( u_msg );

    // Update target
    update_target( u_msg );

    // Publish new setpoint
    request_new_ctrl_setpoint();

}


void Driver_Node::load_ROS_param(){
	
    // Load USB port to use
	std::string port_name_string;
	n.param<std::string>("port_name", port_name_string , "defaut_port_name");
	
	// String to qtstring
	serialport_name = QString::fromStdString( port_name_string );

    // Load ID number of the board
    n.param("execute_ID", active_slave_1, 40);

    ROS_INFO("Loaded serial port name : %s  and execute_ID: %i", serialport_name.toStdString().c_str() , active_slave_1 );
	    
}

void Driver_Node::open_USB_port(){
	
	// Set name
	USBSerialPort.setPortName( serialport_name );
	
	// Set other params
	USBSerialPort.setBaudRate(USBSerialPort.Baud115200);
	USBSerialPort.setDataBits(QSerialPort::Data8);
	USBSerialPort.setParity(QSerialPort::NoParity);
	USBSerialPort.setStopBits(QSerialPort::OneStop);
	USBSerialPort.setFlowControl(QSerialPort::NoFlowControl);
	
	// Try to open the port
	
	unsigned int tries_cnt = 0;
	
	do
	    {
			usb_is_open = USBSerialPort.open(QIODevice::ReadWrite);  //returns true if successful
			tries_cnt++;
	        if( tries_cnt >= com_init_tries)
	            break;

	        //When failure, print error code:
	        if( usb_is_open == false)
	        {
	        	ROS_INFO("Failed to open USB port %s : %s" , serialport_name.toStdString().c_str() , USBSerialPort.errorString().toStdString().c_str()  );
	        }
	        
	        // Sleep before trying again
	        ros::Duration( com_init_delay ).sleep();
	        
	    }while( usb_is_open != true);
	
	// Succes	
	if ( usb_is_open == true ){
		
		ROS_INFO("Driver Cmd: USB port %s is connected!", serialport_name.toStdString().c_str() );
		
		USBSerialPort.clear((QSerialPort::AllDirections));
		
	// Failure
	} else {
		
		ROS_INFO("Failed to open USB port %s, going into offline mode" , serialport_name.toStdString().c_str() );
		
	}
	
}

void Driver_Node::close_USB_port(){
	
	
	USBSerialPort.clear((QSerialPort::AllDirections));
	USBSerialPort.close();
	    
}

void Driver_Node::write_USB_port(char bytes_to_send, unsigned char *serial_tx_data){
	
	qint64 write_ret = 0;
	QByteArray myQBArray;
	myQBArray = QByteArray::fromRawData((const char*)serial_tx_data, bytes_to_send);

	write_ret = USBSerialPort.write(myQBArray);

	//return (int) write_ret;
	    
}

void Driver_Node::read_USB_port(  unsigned char *buf ){ 
	
	QByteArray data;
	bool dataReady = false;

	dataReady = USBSerialPort.waitForReadyRead( com_read_delay ); // 
	
	if(dataReady == true)
	{
		data = USBSerialPort.readAll();

		//We check to see if we are getting reasonnable packets, or a bunch of crap:
		int len = data.length();
		if(len > 256)
		{
			qDebug() << "Data length over 256 bytes (" << len << "bytes)";
			len = 256;
			USBSerialPort.clear((QSerialPort::AllDirections));
			//return 0;
		}

        // Debug prints
        //qDebug() << "Read" << len << "bytes.";
        //qDebug() << data;

		//Fill the rx buf with our new bytes:
		for(int i = 0; i < len; i++)
		{
			
			update_rx_buf_byte_usb(data[i]);
			//ToDo use array
		}
	}
	else
	{
		qDebug("No USB bytes available.");
	}
	    
}

void Driver_Node::request_read_all_data(){
	
	
	if ( usb_is_open == true ){
	
	
		int numb = 0;
		
		numb = tx_cmd_data_read_all( active_slave_1, CMD_READ, payload_str, PAYLOAD_BUF_LEN);
		
		numb = comm_gen_str( payload_str, comm_str_usb, PAYLOAD_BUF_LEN);
		
		numb = COMM_STR_BUF_LEN;
	
		write_USB_port( numb, comm_str_usb ); 
		
        //qDebug("Read All cmd sent");
	
	} else {
		
		qDebug("Port is closed, cannot send cmd");
		
	}
	
	    
}

void Driver_Node::read_all_data(){

    // Sent request over USB
    request_read_all_data();

    // Read usb port and decoder buffer
    read_USB_port( usb_rx );
    decode_usb_rx( usb_rx );


}

void Driver_Node::publish_sensor_msg(){

    // Convert value into ROS msg format/units and publish

    // Publish a message
    // Create messages
    flexsea_execute::outputs y_msg;

    // Create correct header time stamp
    y_msg.header.stamp = ros::Time::now();

    // Build Imu msg

    // Header
    y_msg.imu.header = y_msg.header ; // Copy global header into Imu sub-message

    // Orientation
    y_msg.imu.orientation_covariance[0] = -1 ; // Convention for orientation not inlcuded in IMU msg


    // TODO change publishing for general case (now only works for ID 1 or 2)
    // Board Execute ID #1
    if ( active_slave_1 == 40 ){

        // Accel
        float g2ms2 = 9.80665 ;
        y_msg.imu.linear_acceleration.x = (double) exec1.accel.x /8192 * g2ms2 ;
        y_msg.imu.linear_acceleration.y = (double) exec1.accel.y /8192 * g2ms2 ;
        y_msg.imu.linear_acceleration.z = (double) exec1.accel.z /8192 * g2ms2 ;

        // Velocity
        float deg2rad = 0.01745329 ;
        y_msg.imu.angular_velocity.x = (double) exec1.gyro.x /16.4 * deg2rad ;
        y_msg.imu.angular_velocity.y = (double) exec1.gyro.y /16.4 * deg2rad ;
        y_msg.imu.angular_velocity.z = (double) exec1.gyro.z /16.4 * deg2rad ;

        // Strain sensor
        y_msg.e = ( (double) ( exec1.strain-32768 ) / 32768 ) * 100 ; // Convertion to [%]

        // Analog inputs
        y_msg.analog_0 = ((float)exec1.analog[0]/P5_ADC_MAX)*P5_ADC_SUPPLY ; //exec1.analog[0] ;
        y_msg.analog_1 = ((float)exec1.analog[1]/P5_ADC_MAX)*P5_ADC_SUPPLY ; //exec1.analog[1] ;

        // Current
        int current_offset = 0;
        y_msg.current = (float) ( exec1.current - current_offset ) * 18.5;

        if (verbose_current){
            qDebug() << "______________________current_actual_raw: " << (exec1.current);
        }

        // Encoder
        y_msg.encoder = exec1.enc_display ;

        // Supply tension
        y_msg.vb = P4_ADC_SUPPLY*((16*(float)exec1.volt_batt/3 + 302 )/P4_ADC_MAX) / 0.0738 ; // exec1.volt_batt ;
        y_msg.vg = P4_ADC_SUPPLY*((26*(float)exec1.volt_int/3 + 440 )/P4_ADC_MAX)  / 0.43   ;  // exec1.volt_int  ;

        // Temperature
        y_msg.temp = ((((2.625*(float)exec1.temp + 41)/P4_ADC_MAX)*P4_ADC_SUPPLY) - P4_T0) / P4_TC ; // exec1.temp ;

        // Status
        y_msg.status_1 = exec1.status1 ;
        y_msg.status_2 = exec1.status2 ;

    // Board Execute ID #2
    } else if ( active_slave_1 == 41 ){

        // Accel
        float g2ms2 = 9.80665 ;
        y_msg.imu.linear_acceleration.x = (double) exec2.accel.x /8192 * g2ms2 ;
        y_msg.imu.linear_acceleration.y = (double) exec2.accel.y /8192 * g2ms2 ;
        y_msg.imu.linear_acceleration.z = (double) exec2.accel.z /8192 * g2ms2 ;

        // Velocity
        float deg2rad = 0.01745329 ;
        y_msg.imu.angular_velocity.x = (double) exec2.gyro.x /16.4 * deg2rad ;
        y_msg.imu.angular_velocity.y = (double) exec2.gyro.y /16.4 * deg2rad ;
        y_msg.imu.angular_velocity.z = (double) exec2.gyro.z /16.4 * deg2rad ;

        // Strain sensor
        y_msg.e = ( (double) ( exec2.strain-32768 ) / 32768 ) * 100 ; // Convertion to [%]

        // Analog inputs
        y_msg.analog_0 = ((float)exec2.analog[0]/P5_ADC_MAX)*P5_ADC_SUPPLY ; //exec1.analog[0] ;
        y_msg.analog_1 = ((float)exec2.analog[1]/P5_ADC_MAX)*P5_ADC_SUPPLY ; //exec1.analog[1] ;

        // Current
        int current_offset = 0;
        y_msg.current = (float) ( exec2.current - current_offset ) * 18.5;

        // Encoder
        y_msg.encoder = exec2.enc_display ;

        // Supply tension
        y_msg.vb = P4_ADC_SUPPLY*((16*(float)exec2.volt_batt/3 + 302 )/P4_ADC_MAX) / 0.0738 ; // exec1.volt_batt ;
        y_msg.vg = P4_ADC_SUPPLY*((26*(float)exec2.volt_int/3 + 440 )/P4_ADC_MAX)  / 0.43   ;  // exec1.volt_int  ;

        // Temperature
        y_msg.temp = ((((2.625*(float)exec2.temp + 41)/P4_ADC_MAX)*P4_ADC_SUPPLY) - P4_T0) / P4_TC ; // exec1.temp ;

        // Status
        y_msg.status_1 = exec2.status1 ;
        y_msg.status_2 = exec2.status2 ;


    } else {

        qDebug("Cannot read from this board ID : TODO ");
    }

    std::stringstream ss;
    //ss << "Accel axis : x = " << exec1.accel.x << " y : " << exec1.accel.y << " z : " << exec1.accel.z << "  Encoder Display : " << exec1.enc_display;
    ss << " Error code decoding not yet implemented";
    y_msg.status = ss.str();

    // Publish messages
    pub.publish( y_msg );


}

bool Driver_Node::check_gain_updated(const flexsea_execute::inputs u_msg){

    bool updated = false;

    for ( int i=0; i < 6 ; i++ ){
        if ( ctrl_gains[0] != u_msg.ctrl_gains[0] ) { updated = true; }
    }

    return updated;
}

void Driver_Node::update_ctrl_if_needed(const flexsea_execute::inputs u_msg){

    bool ctrl_changed = false;

    // Check if control mode changed
    if (u_msg.ctrl_mode != ctrl_mode ){

        ctrl_mode    = u_msg.ctrl_mode;
        ctrl_changed = true;

        // USB request
        request_ctrl_mode();
    }

    // Check if gain changed or if controller changed --> then send new gains values
    if ( check_gain_updated( u_msg) or ctrl_changed  ){
        // Assign new gains
        for ( int i=0; i < 6 ; i++ ){
            ctrl_gains[0] = u_msg.ctrl_gains[0];
        }

        // USB request
        request_ctrl_gains();
    }

    // Check if brake state changed
    if (u_msg.brake_pwm != brake_pwm ){

        brake_pwm = u_msg.brake_pwm;

        request_brake_pwm();
    }
}

void Driver_Node::update_target(const flexsea_execute::inputs u_msg){

    ctrl_setpoint = u_msg.ctrl_setpoint;

    for ( int i=0; i < 6 ; i++ ){
        trap_values[0] = u_msg.trap_values[0];
    }
}

void Driver_Node::request_ctrl_mode(){

    int numb = 0;

    tx_cmd_ctrl_mode(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, ctrl_mode );

    numb = comm_gen_str(payload_str, comm_str_usb, PAYLOAD_BUF_LEN);
    numb = COMM_STR_BUF_LEN;
    write_USB_port( numb, comm_str_usb );

    // Read usb port and decoder buffer
    read_USB_port( usb_rx );
    decode_usb_rx( usb_rx );

    ROS_INFO("Ctrl Mode %d requested", (int)ctrl_mode);

}

void Driver_Node::request_ctrl_gains(){

    int numb = 0, valid = 0;

    switch( ctrl_mode )
    {
        case 0: //Null
            valid = 0;
            break;
        case 1: //Open
            valid = 0;
            break;
        case 2: //Position
            valid = 1;
            tx_cmd_ctrl_p_g(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, ctrl_gains[0], ctrl_gains[1], ctrl_gains[2]);
             break;
        case 3: //Current
            valid = 1;
            numb = tx_cmd_ctrl_i_g(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, ctrl_gains[0], ctrl_gains[1], ctrl_gains[2]);
            break;
        case 4: //Impedance
            valid = 1;
            tx_cmd_ctrl_z_g(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, ctrl_gains[0], ctrl_gains[1], ctrl_gains[2]);
            break;
        case 5: //Custom/other
            valid = 0;
            break;
        default:
            valid = 0;
            break;
    }

    if (valid){
        numb = comm_gen_str(payload_str, comm_str_usb, PAYLOAD_BUF_LEN);
        numb = COMM_STR_BUF_LEN;
        write_USB_port( numb, comm_str_usb );

        // Read usb port and decoder buffer
        read_USB_port( usb_rx );
        decode_usb_rx( usb_rx );

        ROS_INFO("New ctrl gains requested");
    }
}

void Driver_Node::request_new_ctrl_setpoint(){

    int numb = 0, valid = 0;

    int trap_pos = 0, trap_posi = 0, trap_posf = 0, trap_spd = 0, trap_acc = 0;

    int val = 0;



    // Optionnal trap mode
    if ( trap_mode ) {
        trap_pos  = trap_values[0];
        trap_posi = trap_values[1];
        trap_posf = trap_values[2];
        trap_spd  = trap_values[3];
        trap_acc  = trap_values[4];
    } else {
        trap_pos  = ctrl_setpoint;
        trap_posi = exec1.enc_display; //= ctrl_setpoint;
        trap_posf = ctrl_setpoint;
        trap_spd  = 50000;
        trap_acc  = 50000;
    }

    //uint8_t payload_str_test[PAYLOAD_BUF_LEN];

    //qDebug() << "ctl_setpoint: " << ctrl_setpoint << " PAYLOAD_BUF_LEN: " << PAYLOAD_BUF_LEN << "payload_str: " << payload_str;

    switch( ctrl_mode )
    {
        case 0: //Null
            valid = 0;
            break;
        case 1: //Open
            valid = 1;
            numb = tx_cmd_ctrl_o(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, ctrl_setpoint);
            break;
        case 2: //Position
            valid = 1;
            numb = tx_cmd_ctrl_p(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, trap_pos, trap_posi, trap_posf, trap_spd, trap_acc);
             break;
        case 3: //Current
            valid = 1;
            val = ctrl_setpoint;
            if (verbose_current){
                qDebug() << "ctl_setpoint_raw: " <<  val;
            }
            numb = tx_cmd_ctrl_i(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, val, 0);
            break;
        case 4: //Impedance
            valid = 1;
            numb = tx_cmd_ctrl_p(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, trap_pos, trap_posi, trap_posf, trap_spd, trap_acc);
            break;
        case 5: //Custom/other
            valid = 0;
            break;
        default:
            valid = 0;
            break;
    }

    if (valid){
        numb = comm_gen_str(payload_str, comm_str_usb, PAYLOAD_BUF_LEN);
        numb = COMM_STR_BUF_LEN;
        write_USB_port( numb, comm_str_usb );

        // Read usb port and decoder buffer
        //read_USB_port( usb_rx );
        //decode_usb_rx( usb_rx );

        if (verbose){

            ROS_INFO("New ctrl setpoint requested");
        }
    }
}

void Driver_Node::request_brake_pwm(){

    int numb = 0;

    tx_cmd_exp_pwro(active_slave_1, CMD_WRITE, payload_str, PAYLOAD_BUF_LEN, brake_pwm );

    numb = comm_gen_str(payload_str, comm_str_usb, PAYLOAD_BUF_LEN);
    numb = COMM_STR_BUF_LEN;
    write_USB_port( numb, comm_str_usb );

    // Read usb port and decoder buffer
    read_USB_port( usb_rx );
    decode_usb_rx( usb_rx );

    ROS_INFO("Brake state updated");

}

void Driver_Node::set_position_ctl(){

    ctrl_mode = 2;
    request_ctrl_mode();
    request_ctrl_gains();

}




// ----------------------------------
void Driver_Node::print_debug(){

    qDebug() << "Debug values";
    qDebug() << "CMD_READ" << CMD_READ << " PAYLOAD_BUF_LEN" << PAYLOAD_BUF_LEN << " Alex" << Alex;


}




















// TODO : solve linkage problem with cmake instead...

// test function in this source files to run compil?? ---------------------------------------------------------------


//Transmission of a READ_ALL command
uint32_t tx_cmd_data_read_all(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len)
{
	uint8_t tmp0 = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
	uint32_t bytes = 0;

	//Fresh payload string:
	prepare_empty_payload(board_id, receiver, buf, len);

	//Command:
	buf[P_CMDS] = 1;                     //1 command in string

	if(cmd_type == CMD_READ)
	{
		buf[P_CMD1] = CMD_R(CMD_READ_ALL);

		bytes = P_CMD1 + 1;     //Bytes is always last+1
	}
	else if(cmd_type == CMD_WRITE)
	{
		//In that case Write is only used for the Reply
		
		buf[P_CMD1] = CMD_W(CMD_READ_ALL);
		
		#ifdef BOARD_TYPE_FLEXSEA_EXECUTE

		//Arguments:
		uint16_to_bytes((uint16_t)imu.gyro.x, &tmp0, &tmp1);
		buf[P_DATA1] = tmp0;
		buf[P_DATA1 + 1] = tmp1;
		uint16_to_bytes((uint16_t)imu.gyro.y, &tmp0, &tmp1);
		buf[P_DATA1 + 2] = tmp0;
		buf[P_DATA1 + 3] = tmp1;
		uint16_to_bytes((uint16_t)imu.gyro.z, &tmp0, &tmp1);
		buf[P_DATA1 + 4] = tmp0;
		buf[P_DATA1 + 5] = tmp1;
		
		uint16_to_bytes((uint16_t)imu.accel.x, &tmp0, &tmp1);
		buf[P_DATA1 + 6] = tmp0;
		buf[P_DATA1 + 7] = tmp1;
		uint16_to_bytes((uint16_t)imu.accel.y, &tmp0, &tmp1);
		buf[P_DATA1 + 8] = tmp0;
		buf[P_DATA1 + 9] = tmp1;
		uint16_to_bytes((uint16_t)imu.accel.z, &tmp0, &tmp1);
		buf[P_DATA1 + 10] = tmp0;
		buf[P_DATA1 + 11] = tmp1;		
		
		uint16_to_bytes(strain_read(), &tmp0, &tmp1);
		buf[P_DATA1 + 12] = tmp0;
		buf[P_DATA1 + 13] = tmp1;
		
		uint16_to_bytes(read_analog(0), &tmp0, &tmp1);
		buf[P_DATA1 + 14] = tmp0;
		buf[P_DATA1 + 15] = tmp1;
		
		uint16_to_bytes(read_analog(1), &tmp0, &tmp1);
		buf[P_DATA1 + 16] = tmp0;
		buf[P_DATA1 + 17] = tmp1;
		
		uint32_to_bytes((uint32_t)refresh_enc_display(), &tmp0, &tmp1, &tmp2, &tmp3);
		buf[P_DATA1 + 18] = tmp0;
		buf[P_DATA1 + 19] = tmp1;
		buf[P_DATA1 + 20] = tmp2;
		buf[P_DATA1 + 21] = tmp3;
		
		uint16_to_bytes((uint16_t)ctrl.current.actual_val, &tmp0, &tmp1);
		buf[P_DATA1 + 22] = tmp0;
		buf[P_DATA1 + 23] = tmp1;

		buf[P_DATA1 + 24] = safety_cop.v_vb;
		buf[P_DATA1 + 25] = safety_cop.v_vg;
		buf[P_DATA1 + 26] = safety_cop.temperature;
		buf[P_DATA1 + 27] = safety_cop.status1;
		buf[P_DATA1 + 28] = safety_cop.status2;

		bytes = P_DATA1 + 29;     //Bytes is always last+1
		
		#endif	//BOARD_TYPE_FLEXSEA_EXECUTE
	}
	else
	{
		//Invalid
		flexsea_error(SE_INVALID_READ_TYPE);
		bytes = 0;
	}

	return bytes;
}

//Transmission of a CTRL_MODE command
uint32_t tx_cmd_ctrl_mode(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, int16_t ctrl)
{
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_MODE);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_MODE);

        //Arguments:
        buf[P_DATA1] = ctrl;

        bytes = P_DATA1 + 1;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}



//Transmission of a CTRL_P_G command
uint32_t tx_cmd_ctrl_p_g(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, \
                        int16_t kp, int16_t ki, int16_t kd)
{
    uint8_t tmp0 = 0, tmp1 = 0;
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_P_G);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_P_G);

        //Arguments:
        uint16_to_bytes((uint16_t)kp, &tmp0, &tmp1);
        buf[P_DATA1 + 0] = tmp0;
        buf[P_DATA1 + 1] = tmp1;
        uint16_to_bytes((uint16_t)ki, &tmp0, &tmp1);
        buf[P_DATA1 + 2] = tmp0;
        buf[P_DATA1 + 3] = tmp1;
        uint16_to_bytes((uint16_t)kd, &tmp0, &tmp1);
        buf[P_DATA1 + 4] = tmp0;
        buf[P_DATA1 + 5] = tmp1;


        bytes = P_DATA1 + 6;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}


//Transmission of a CTRL_P command
uint32_t tx_cmd_ctrl_p(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, \
                        int32_t pos, int32_t posi, int32_t posf, int32_t spdm, int32_t acc)
{
    uint8_t tmp0 = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_P);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_P);

        //Arguments:
        uint32_to_bytes((uint32_t)pos, &tmp0, &tmp1, &tmp2, &tmp3);
        buf[P_DATA1 + 0] = tmp0;
        buf[P_DATA1 + 1] = tmp1;
        buf[P_DATA1 + 2] = tmp2;
        buf[P_DATA1 + 3] = tmp3;
        uint32_to_bytes((uint32_t)posi, &tmp0, &tmp1, &tmp2, &tmp3);
        buf[P_DATA1 + 4] = tmp0;
        buf[P_DATA1 + 5] = tmp1;
        buf[P_DATA1 + 6] = tmp2;
        buf[P_DATA1 + 7] = tmp3;
        uint32_to_bytes((uint32_t)posf, &tmp0, &tmp1, &tmp2, &tmp3);
        buf[P_DATA1 + 8] = tmp0;
        buf[P_DATA1 + 9] = tmp1;
        buf[P_DATA1 + 10] = tmp2;
        buf[P_DATA1 + 11] = tmp3;
        uint32_to_bytes((uint32_t)spdm, &tmp0, &tmp1, &tmp2, &tmp3);
        buf[P_DATA1 + 12] = tmp0;
        buf[P_DATA1 + 13] = tmp1;
        buf[P_DATA1 + 14] = tmp2;
        buf[P_DATA1 + 15] = tmp3;
        uint32_to_bytes((uint32_t)acc, &tmp0, &tmp1, &tmp2, &tmp3);
        buf[P_DATA1 + 16] = tmp0;
        buf[P_DATA1 + 17] = tmp1;
        buf[P_DATA1 + 18] = tmp2;
        buf[P_DATA1 + 19] = tmp3;

        bytes = P_DATA1 + 20;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}


//Transmission of a CTRL_I_G command
uint32_t tx_cmd_ctrl_i_g(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, \
                        int16_t kp, int16_t ki, int16_t kd)
{
    uint8_t tmp0 = 0, tmp1 = 0;
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_I_G);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_I_G);

        //Arguments:
        uint16_to_bytes((uint16_t)kp, &tmp0, &tmp1);
        buf[P_DATA1 + 0] = tmp0;
        buf[P_DATA1 + 1] = tmp1;
        uint16_to_bytes((uint16_t)ki, &tmp0, &tmp1);
        buf[P_DATA1 + 2] = tmp0;
        buf[P_DATA1 + 3] = tmp1;
        uint16_to_bytes((uint16_t)kd, &tmp0, &tmp1);
        buf[P_DATA1 + 4] = tmp0;
        buf[P_DATA1 + 5] = tmp1;


        bytes = P_DATA1 + 6;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}

//Transmission of a CTRL_Z_G command
uint32_t tx_cmd_ctrl_z_g(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, \
                        int16_t zk, int16_t zb, int16_t zi)
{
    uint8_t tmp0 = 0, tmp1 = 0;
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_Z_G);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_Z_G);

        //Arguments:
        uint16_to_bytes((uint16_t)zk, &tmp0, &tmp1);
        buf[P_DATA1 + 0] = tmp0;
        buf[P_DATA1 + 1] = tmp1;
        uint16_to_bytes((uint16_t)zb, &tmp0, &tmp1);
        buf[P_DATA1 + 2] = tmp0;
        buf[P_DATA1 + 3] = tmp1;
        uint16_to_bytes((uint16_t)zi, &tmp0, &tmp1);
        buf[P_DATA1 + 4] = tmp0;
        buf[P_DATA1 + 5] = tmp1;


        bytes = P_DATA1 + 6;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}

//Transmission of a CTRL_O command
uint32_t tx_cmd_ctrl_o(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, int16_t open_spd)
{
    uint8_t tmp0 = 0, tmp1 = 0;
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_O);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_O);

        //Arguments:
        uint16_to_bytes(open_spd, &tmp0, &tmp1);
        buf[P_DATA1] = tmp0;
        buf[P_DATA1 + 1] = tmp1;

        bytes = P_DATA1 + 2;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}

//Transmission of a CTRL_I command
uint32_t tx_cmd_ctrl_i(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, int16_t wanted, int16_t measured)
{
    uint8_t tmp0 = 0, tmp1 = 0;
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        buf[P_CMD1] = CMD_R(CMD_CTRL_I);

        bytes = P_CMD1 + 1;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        buf[P_CMD1] = CMD_W(CMD_CTRL_I);

        //Arguments:
        uint16_to_bytes(measured, &tmp0, &tmp1);
        buf[P_DATA1] = tmp0;
        buf[P_DATA1 + 1] = tmp1;
        uint16_to_bytes(wanted, &tmp0, &tmp1);
        buf[P_DATA1 + 2] = tmp0;
        buf[P_DATA1 + 3] = tmp1;

        bytes = P_DATA1 + 4;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}


//Transmission of a PWRO command
uint32_t tx_cmd_exp_pwro(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, \
                                uint8_t pwro_pwm)
{
    uint32_t bytes = 0;

    //Fresh payload string:
    prepare_empty_payload(board_id, receiver, buf, len);

    //Command:
    buf[P_CMDS] = 1;                     //1 command in string

    if(cmd_type == CMD_READ)
    {
        //No arguments needed to read the clutch state

        //Arguments:
        //...

        bytes = P_DATA1 + 0;     //Bytes is always last+1
    }
    else if(cmd_type == CMD_WRITE)
    {
        //In that case Write is only used for the Reply

        buf[P_CMD1] = CMD_W(CMD_PWRO);

        //Arguments:
        buf[P_DATA1 + 0] = pwro_pwm;

        bytes = P_DATA1 + 1;     //Bytes is always last+1
    }
    else
    {
        //Invalid
        flexsea_error(SE_INVALID_READ_TYPE);
        bytes = 0;
    }

    return bytes;
}
