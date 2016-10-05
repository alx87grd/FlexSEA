/*******************************************************************************
* File Name: EX11.c  
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
#include "EX11.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EX11__PORT == 15 && ((EX11__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EX11_Write
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
void EX11_Write(uint8 value) 
{
    uint8 staticBits = (EX11_DR & (uint8)(~EX11_MASK));
    EX11_DR = staticBits | ((uint8)(value << EX11_SHIFT) & EX11_MASK);
}


/*******************************************************************************
* Function Name: EX11_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EX11_DM_STRONG     Strong Drive 
*  EX11_DM_OD_HI      Open Drain, Drives High 
*  EX11_DM_OD_LO      Open Drain, Drives Low 
*  EX11_DM_RES_UP     Resistive Pull Up 
*  EX11_DM_RES_DWN    Resistive Pull Down 
*  EX11_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EX11_DM_DIG_HIZ    High Impedance Digital 
*  EX11_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EX11_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EX11_0, mode);
}


/*******************************************************************************
* Function Name: EX11_Read
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
*  Macro EX11_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EX11_Read(void) 
{
    return (EX11_PS & EX11_MASK) >> EX11_SHIFT;
}


/*******************************************************************************
* Function Name: EX11_ReadDataReg
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
uint8 EX11_ReadDataReg(void) 
{
    return (EX11_DR & EX11_MASK) >> EX11_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EX11_INTSTAT) 

    /*******************************************************************************
    * Function Name: EX11_ClearInterrupt
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
    uint8 EX11_ClearInterrupt(void) 
    {
        return (EX11_INTSTAT & EX11_MASK) >> EX11_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
