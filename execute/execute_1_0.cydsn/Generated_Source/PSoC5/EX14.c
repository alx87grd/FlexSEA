/*******************************************************************************
* File Name: EX14.c  
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
#include "EX14.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EX14__PORT == 15 && ((EX14__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EX14_Write
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
void EX14_Write(uint8 value) 
{
    uint8 staticBits = (EX14_DR & (uint8)(~EX14_MASK));
    EX14_DR = staticBits | ((uint8)(value << EX14_SHIFT) & EX14_MASK);
}


/*******************************************************************************
* Function Name: EX14_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EX14_DM_STRONG     Strong Drive 
*  EX14_DM_OD_HI      Open Drain, Drives High 
*  EX14_DM_OD_LO      Open Drain, Drives Low 
*  EX14_DM_RES_UP     Resistive Pull Up 
*  EX14_DM_RES_DWN    Resistive Pull Down 
*  EX14_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EX14_DM_DIG_HIZ    High Impedance Digital 
*  EX14_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EX14_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EX14_0, mode);
}


/*******************************************************************************
* Function Name: EX14_Read
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
*  Macro EX14_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EX14_Read(void) 
{
    return (EX14_PS & EX14_MASK) >> EX14_SHIFT;
}


/*******************************************************************************
* Function Name: EX14_ReadDataReg
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
uint8 EX14_ReadDataReg(void) 
{
    return (EX14_DR & EX14_MASK) >> EX14_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EX14_INTSTAT) 

    /*******************************************************************************
    * Function Name: EX14_ClearInterrupt
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
    uint8 EX14_ClearInterrupt(void) 
    {
        return (EX14_INTSTAT & EX14_MASK) >> EX14_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
