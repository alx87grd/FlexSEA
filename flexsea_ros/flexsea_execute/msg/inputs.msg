# Message for flexsea execute inputs cmds
Header header
int16     ctrl_mode         # 0 : Null  1: Open 2: Position 3: Current 4: Impedance 5: Custom
int16[6]  ctrl_gains        #
int16     ctrl_setpoint     # general set point
bool      trap_mode         # 0 : postion controller use set point value 1 : use trap values
int32[6]  trap_values         
int16     brake_pwm         # 0 - 255 
