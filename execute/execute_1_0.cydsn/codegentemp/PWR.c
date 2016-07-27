/*******************************************************************************
* File Name: PWR.c  
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
#include "PWR.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PWR__PORT == 15 && ((PWR__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PWR_Write
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
void PWR_Write(uint8 value) 
{
    uint8 staticBits = (PWR_DR & (uint8)(~PWR_MASK));
    PWR_DR = staticBits | ((uint8)(value << PWR_SHIFT) & PWR_MASK);
}


/*******************************************************************************
* Function Name: PWR_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWR_DM_STRONG     Strong Drive 
*  PWR_DM_OD_HI      Open Drain, Drives High 
*  PWR_DM_OD_LO      Open Drain, Drives Low 
*  PWR_DM_RES_UP     Resistive Pull Up 
*  PWR_DM_RES_DWN    Resistive Pull Down 
*  PWR_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWR_DM_DIG_HIZ    High Impedance Digital 
*  PWR_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWR_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PWR_0, mode);
}


/*******************************************************************************
* Function Name: PWR_Read
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
*  Macro PWR_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWR_Read(void) 
{
    return (PWR_PS & PWR_MASK) >> PWR_SHIFT;
}


/*******************************************************************************
* Function Name: PWR_ReadDataReg
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
uint8 PWR_ReadDataReg(void) 
{
    return (PWR_DR & PWR_MASK) >> PWR_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWR_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWR_ClearInterrupt
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
    uint8 PWR_ClearInterrupt(void) 
    {
        return (PWR_INTSTAT & PWR_MASK) >> PWR_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
