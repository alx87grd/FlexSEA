#!/usr/bin/env python
import rospy
import numpy as np
from flexsea_execute.msg import inputs
from sensor_msgs.msg import Joy

#########################################
class nav(object):
    """
    navigation
    """
    def __init__(self):
        
        self.verbose = False
        
        self.pub_u        = rospy.Publisher("a0/u", inputs , queue_size=1      )
        self.pub_timer    = rospy.Timer( rospy.Duration.from_sec(0.3),    self.timer_callback  )
        self.sub_joy      = rospy.Subscriber("joy", Joy , self.joy_callback , queue_size=1      )
        
        # Init flexsea input msg
        self.ctrl_mode       = 0
        self.ctrl_gains      = [10,0,0,0,0,0]
        self.ctrl_setpoint   = 0
        self.trap_mode       = False
        trap_spd             = 50000
        trap_acc             = 50000
        self.trap_values     = [ 0 , 0 , 0 , trap_spd , trap_acc , 0 ]
        self.brake_pwm       = 0
        
    #######################################   
    def joy_callback( self, msg ):
        """ """
        
        # Pick ctrl_mode with button state
        if ( msg.buttons[0] == 1 ):
            self.ctrl_mode = 1 
        elif ( msg.buttons[1] == 1 ):
            self.ctrl_mode = 2
        elif ( msg.buttons[2] == 1 ):
            self.ctrl_mode = 3
        elif ( msg.buttons[3] == 1 ):
            self.ctrl_mode = 4
        elif ( msg.buttons[4] == 1 ):
            self.ctrl_mode = 5
        else:
            self.ctrl_mode= 0
        
        # Pick set_point with joysticks gain
        if ( self.ctrl_mode == 2):
            """ position mode """
            u  =    int( msg.axes[1] * 100000 )
            
        elif( self.ctrl_mode == 1):
            """ open loop mode """
            u  =    int( msg.axes[1] * 2000 )
            
        else:
            
            u  =    int( msg.axes[1] * 10000  )
            
        # Pick brake state with trigger
        if ( msg.axes[5] < 0):
            self.brake_pwm = 255
        else:
            self.brake_pwm = 0
            
            
        self.ctrl_setpoint  = u
        self.trap_values[0] = u
        self.trap_values[1] = u
        self.trap_values[2] = u
            
        self.pub_u_msg()
        
        if self.verbose:
            
            print( 'Ctrl mode: ', self.ctrl_mode, ' Set point: ', self.ctrl_setpoint )
            
        
    #######################################   
    def timer_callback( self, msg ):
        
        pass
            
    #######################################   
    def pub_u_msg( self ):
        """ pub actuator cmd """
        
        msg = inputs()
        
        msg.ctrl_mode       = self.ctrl_mode 
        msg.ctrl_gains      = self.ctrl_gains 
        msg.ctrl_setpoint   = self.ctrl_setpoint
        msg.trap_mode       = self.trap_mode
        msg.trap_values     = self.trap_values
        msg.brake_pwm       = self.brake_pwm
        
        self.pub_u.publish( msg )
        

            


#########################################
if __name__ == '__main__':
    
    rospy.init_node('nav',anonymous=False)
    node = nav()
    rospy.spin()
