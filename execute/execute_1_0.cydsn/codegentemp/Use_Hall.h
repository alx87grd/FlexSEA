/*******************************************************************************
* File Name: Use_Hall.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_Use_Hall_H) /* CY_CONTROL_REG_Use_Hall_H */
#define CY_CONTROL_REG_Use_Hall_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Use_Hall_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Use_Hall_Write(uint8 control) ;
uint8   Use_Hall_Read(void) ;

void Use_Hall_SaveConfig(void) ;
void Use_Hall_RestoreConfig(void) ;
void Use_Hall_Sleep(void) ; 
void Use_Hall_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Use_Hall_Control        (* (reg8 *) Use_Hall_Sync_ctrl_reg__CONTROL_REG )
#define Use_Hall_Control_PTR    (  (reg8 *) Use_Hall_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Use_Hall_H */


/* [] END OF FILE */
