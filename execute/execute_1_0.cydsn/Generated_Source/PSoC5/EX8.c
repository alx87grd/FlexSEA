/*******************************************************************************
* File Name: EX8.c  
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
#include "EX8.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EX8__PORT == 15 && ((EX8__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EX8_Write
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
void EX8_Write(uint8 value) 
{
    uint8 staticBits = (EX8_DR & (uint8)(~EX8_MASK));
    EX8_DR = staticBits | ((uint8)(value << EX8_SHIFT) & EX8_MASK);
}


/*******************************************************************************
* Function Name: EX8_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EX8_DM_STRONG     Strong Drive 
*  EX8_DM_OD_HI      Open Drain, Drives High 
*  EX8_DM_OD_LO      Open Drain, Drives Low 
*  EX8_DM_RES_UP     Resistive Pull Up 
*  EX8_DM_RES_DWN    Resistive Pull Down 
*  EX8_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EX8_DM_DIG_HIZ    High Impedance Digital 
*  EX8_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EX8_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EX8_0, mode);
}


/*******************************************************************************
* Function Name: EX8_Read
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
*  Macro EX8_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EX8_Read(void) 
{
    return (EX8_PS & EX8_MASK) >> EX8_SHIFT;
}


/*******************************************************************************
* Function Name: EX8_ReadDataReg
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
uint8 EX8_ReadDataReg(void) 
{
    return (EX8_DR & EX8_MASK) >> EX8_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EX8_INTSTAT) 

    /*******************************************************************************
    * Function Name: EX8_ClearInterrupt
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
    uint8 EX8_ClearInterrupt(void) 
    {
        return (EX8_INTSTAT & EX8_MASK) >> EX8_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
