//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Fran�ois (Jeff) Duval
// jfduval@media.mit.edu
// 03/2016
//****************************************************************************
// flexsea_board: configuration and functions for this particular board
//****************************************************************************

//****************************************************************************
// Include(s)
//****************************************************************************

#include "main.h"
#include "flexsea_board.h"
#include "../../flexsea-system/inc/flexsea_system.h"

//****************************************************************************
// Variable(s)
//****************************************************************************

//Board ID (this board) - pick from Board list in flexsea_system.h
uint8 board_id = FLEXSEA_STRAIN_1;
uint8 board_up_id = FLEXSEA_PLAN_1;
uint8 board_sub1_id[SLAVE_BUS_1_CNT];
uint8 board_sub2_id[SLAVE_BUS_2_CNT];

//ToDo: This used to be in flexsea_rx_cmd... not clean. 
uint8_t read_offset = 0;

//Slave Read Buffer:
unsigned char slave_read_buffer[SLAVE_READ_BUFFER_LEN];

//****************************************************************************
// Function(s)
//****************************************************************************

//Wrapper for the specific serial functions. Useful to keep flexsea_network
//platform independent (for example, we don't need need puts_rs485() for Plan)
void flexsea_send_serial_slave(unsigned char port, unsigned char *str, unsigned char length)
{
	//...
}

void flexsea_send_serial_master(unsigned char port, unsigned char *str, unsigned char length)
{
	//...
}

//Fill the buffer with 0s
void flexsea_clear_slave_read_buffer(void)
{
	int i;

	for(i = 0; i < SLAVE_READ_BUFFER_LEN; i++)
	{
		slave_read_buffer[i] = 0;
	}
}

//Packages data in one unified array: slave_read_buffer[]
void flexsea_update_slave_read_buffer(unsigned char read_offset)
{
	//ToDo
	//...
}

//ToDo delete function?
void build_slave_payload(unsigned char base_addr)
{
	unsigned char i = 0;

    //Fresh string:
    prepare_empty_payload(board_id, board_up_id, payload_str, PAYLOAD_BUF_LEN);

    //Command:
    payload_str[P_CMDS] = 1;                     //1 command in string
    payload_str[P_CMD1] = 0;//CMD_MEM_READ_REPLY;

    //Copy a portion of slave_read_buffer[] in payload_str[]
	payload_str[P_DATA1] = slave_read_buffer[SRB_EXECUTE_OFFSET];	//Always the offset		//ToDO fix&enable if you keep this function!
    for(i = 1; i < PAYLOAD_BYTES; i++)
    {
    	payload_str[P_DATA1 + i] = slave_read_buffer[base_addr + i];
    }

    return;
}
