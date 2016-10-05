/*******************************************************************************
* File Name: .h
* Version 3.50
*
* Description:
*  This file provides private constants and parameter values for the I2C
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_I2C_PVT_I2C_0_H)
#define CY_I2C_PVT_I2C_0_H

#include "I2C_0.h"

#define I2C_0_TIMEOUT_ENABLED_INC    (0u)
#if (0u != I2C_0_TIMEOUT_ENABLED_INC)
    #include "I2C_0_TMOUT.h"
#endif /* (0u != I2C_0_TIMEOUT_ENABLED_INC) */


/**********************************
*   Variables with external linkage
**********************************/

extern I2C_0_BACKUP_STRUCT I2C_0_backup;

extern volatile uint8 I2C_0_state;   /* Current state of I2C FSM */

/* Master variables */
#if (I2C_0_MODE_MASTER_ENABLED)
    extern volatile uint8 I2C_0_mstrStatus;   /* Master Status byte  */
    extern volatile uint8 I2C_0_mstrControl;  /* Master Control byte */

    /* Transmit buffer variables */
    extern volatile uint8 * I2C_0_mstrRdBufPtr;   /* Pointer to Master Read buffer */
    extern volatile uint8   I2C_0_mstrRdBufSize;  /* Master Read buffer size       */
    extern volatile uint8   I2C_0_mstrRdBufIndex; /* Master Read buffer Index      */

    /* Receive buffer variables */
    extern volatile uint8 * I2C_0_mstrWrBufPtr;   /* Pointer to Master Write buffer */
    extern volatile uint8   I2C_0_mstrWrBufSize;  /* Master Write buffer size       */
    extern volatile uint8   I2C_0_mstrWrBufIndex; /* Master Write buffer Index      */

#endif /* (I2C_0_MODE_MASTER_ENABLED) */

/* Slave variables */
#if (I2C_0_MODE_SLAVE_ENABLED)
    extern volatile uint8 I2C_0_slStatus;         /* Slave Status  */

    /* Transmit buffer variables */
    extern volatile uint8 * I2C_0_slRdBufPtr;     /* Pointer to Transmit buffer  */
    extern volatile uint8   I2C_0_slRdBufSize;    /* Slave Transmit buffer size  */
    extern volatile uint8   I2C_0_slRdBufIndex;   /* Slave Transmit buffer Index */

    /* Receive buffer variables */
    extern volatile uint8 * I2C_0_slWrBufPtr;     /* Pointer to Receive buffer  */
    extern volatile uint8   I2C_0_slWrBufSize;    /* Slave Receive buffer size  */
    extern volatile uint8   I2C_0_slWrBufIndex;   /* Slave Receive buffer Index */

    #if (I2C_0_SW_ADRR_DECODE)
        extern volatile uint8 I2C_0_slAddress;     /* Software address variable */
    #endif   /* (I2C_0_SW_ADRR_DECODE) */

#endif /* (I2C_0_MODE_SLAVE_ENABLED) */

#if ((I2C_0_FF_IMPLEMENTED) && (I2C_0_WAKEUP_ENABLED))
    extern volatile uint8 I2C_0_wakeupSource;
#endif /* ((I2C_0_FF_IMPLEMENTED) && (I2C_0_WAKEUP_ENABLED)) */


#endif /* CY_I2C_PVT_I2C_0_H */


/* [] END OF FILE */
