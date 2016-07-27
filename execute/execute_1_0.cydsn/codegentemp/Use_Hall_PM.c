/*******************************************************************************
* File Name: Use_Hall_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Use_Hall.h"

/* Check for removal by optimization */
#if !defined(Use_Hall_Sync_ctrl_reg__REMOVED)

static Use_Hall_BACKUP_STRUCT  Use_Hall_backup = {0u};

    
/*******************************************************************************
* Function Name: Use_Hall_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Use_Hall_SaveConfig(void) 
{
    Use_Hall_backup.controlState = Use_Hall_Control;
}


/*******************************************************************************
* Function Name: Use_Hall_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Use_Hall_RestoreConfig(void) 
{
     Use_Hall_Control = Use_Hall_backup.controlState;
}


/*******************************************************************************
* Function Name: Use_Hall_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Use_Hall_Sleep(void) 
{
    Use_Hall_SaveConfig();
}


/*******************************************************************************
* Function Name: Use_Hall_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Use_Hall_Wakeup(void)  
{
    Use_Hall_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
