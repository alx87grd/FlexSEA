/*******************************************************************************
* File Name: EX12.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "EX12.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EX12__PORT == 15 && ((EX12__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EX12_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void EX12_Write(uint8 value) 
{
    uint8 staticBits = (EX12_DR & (uint8)(~EX12_MASK));
    EX12_DR = staticBits | ((uint8)(value << EX12_SHIFT) & EX12_MASK);
}


/*******************************************************************************
* Function Name: EX12_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EX12_DM_STRONG     Strong Drive 
*  EX12_DM_OD_HI      Open Drain, Drives High 
*  EX12_DM_OD_LO      Open Drain, Drives Low 
*  EX12_DM_RES_UP     Resistive Pull Up 
*  EX12_DM_RES_DWN    Resistive Pull Down 
*  EX12_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EX12_DM_DIG_HIZ    High Impedance Digital 
*  EX12_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EX12_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EX12_0, mode);
}


/*******************************************************************************
* Function Name: EX12_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro EX12_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EX12_Read(void) 
{
    return (EX12_PS & EX12_MASK) >> EX12_SHIFT;
}


/*******************************************************************************
* Function Name: EX12_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 EX12_ReadDataReg(void) 
{
    return (EX12_DR & EX12_MASK) >> EX12_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EX12_INTSTAT) 

    /*******************************************************************************
    * Function Name: EX12_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 EX12_ClearInterrupt(void) 
    {
        return (EX12_INTSTAT & EX12_MASK) >> EX12_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
