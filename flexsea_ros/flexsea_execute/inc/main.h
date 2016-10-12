
#ifndef INC_MAIN_H
#define INC_MAIN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "iolib.h"

#include "flexsea_board.h"
#include "flexsea_system.h"
#include "flexsea.h"

//****************************************************************************
// Shared variable(s)
//****************************************************************************

extern char *fake_argv[];
extern const char *delims;


#ifdef SINGLE_COMMAND
#ifdef MULTIPLE_COMMANDS
#error "Pick one Command option!"
#endif
#endif

//Multiple commands:
#define MAX_COMMAND_LEN 		256
#define MAX_ARGS 				12

//IO functions, Reset:
#define RESET_PORT				9
#define RESET_PIN				12

//PSoC 4 ADC conversions:
#define P4_ADC_SUPPLY           5.0
#define P4_ADC_MAX              2048
#define P4_T0                   0.5
#define P4_TC                   0.01

//PSoC 5 ADC conversions:
#define P5_ADC_SUPPLY           5.0
#define P5_ADC_MAX              4096

//#define NULL					0



#endif  //INC_MAIN_H
