#include "ros/ros.h"
#include "flexsea_execute/inputs.h"
#include "flexsea_execute/outputs.h"
#include "std_msgs/String.h"
#include <sstream>
#include <QSerialPort>
#include <QByteArray>
#include "QDebug"



//  Driver clas -----------------------------
class Driver_Node{
private:

	// Node
	ros::NodeHandle n;
	
	// Sub-Pub
	ros::Subscriber sub; // sub to actuator control input
	ros::Publisher  pub; // pub info read from actuator
    ros::Timer      timer;
	
	// USB SERIAL port
	QSerialPort USBSerialPort;
	bool usb_is_open;// = false;
	QString serialport_name;//("/dev/ttyACM0");
	
	//USB buffer
	unsigned char usb_rx[256];
	
	// Connection Params
	int com_init_tries;
	int com_init_delay;
	int com_read_delay;

    // Flexsea-comm params
    int active_slave_1_index;
    int active_slave_1;

    // Controller values   
    int pos_ref;

    // Input msg data
    int16_t     ctrl_mode;
    int16_t     ctrl_gains[6] = {10,0,0,0,0,0};
    int16_t     ctrl_setpoint;
    bool        trap_mode;
    int32_t     trap_values[6] = {0,0,0,50000,50000,0};
    int16_t     brake_pwm;

    // Debug params
    bool verbose         = false;
    bool verbose_current = true;
    int  slave_debug     = 40;
	
public:
	// Functions
	Driver_Node();
	
    void input_callback(const flexsea_execute::inputs u_msg);
    void timer_callback(const ros::TimerEvent&);
	void load_ROS_param();
	
	// USB cmd
	void open_USB_port();
	void close_USB_port();
	void write_USB_port(char bytes_to_send, unsigned char *serial_tx_data);
	void read_USB_port( unsigned char *buf );
	
	// Comm Cmd
	void request_read_all_data();
    void request_ctrl_gains();
    void request_ctrl_mode();
    void request_new_ctrl_setpoint();
    void request_brake_pwm();

    // Ctl selection
    bool check_gain_updated(const flexsea_execute::inputs u_msg);
    void update_ctrl_if_needed(const flexsea_execute::inputs u_msg);
    void update_target(const flexsea_execute::inputs u_msg);

    // Wrapper
    void read_all_data();
    void publish_sensor_msg();
    void set_position_ctl();
	
	//Other
    void print_debug();
};
	
