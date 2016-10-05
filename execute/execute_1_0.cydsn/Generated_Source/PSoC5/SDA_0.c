/*******************************************************************************
* File Name: SDA_0.c  
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
#include "SDA_0.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SDA_0__PORT == 15 && ((SDA_0__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SDA_0_Write
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
void SDA_0_Write(uint8 value) 
{
    uint8 staticBits = (SDA_0_DR & (uint8)(~SDA_0_MASK));
    SDA_0_DR = staticBits | ((uint8)(value << SDA_0_SHIFT) & SDA_0_MASK);
}


/*******************************************************************************
* Function Name: SDA_0_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SDA_0_DM_STRONG     Strong Drive 
*  SDA_0_DM_OD_HI      Open Drain, Drives High 
*  SDA_0_DM_OD_LO      Open Drain, Drives Low 
*  SDA_0_DM_RES_UP     Resistive Pull Up 
*  SDA_0_DM_RES_DWN    Resistive Pull Down 
*  SDA_0_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SDA_0_DM_DIG_HIZ    High Impedance Digital 
*  SDA_0_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SDA_0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SDA_0_0, mode);
}


/*******************************************************************************
* Function Name: SDA_0_Read
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
*  Macro SDA_0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SDA_0_Read(void) 
{
    return (SDA_0_PS & SDA_0_MASK) >> SDA_0_SHIFT;
}


/*******************************************************************************
* Function Name: SDA_0_ReadDataReg
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
uint8 SDA_0_ReadDataReg(void) 
{
    return (SDA_0_DR & SDA_0_MASK) >> SDA_0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SDA_0_INTSTAT) 

    /*******************************************************************************
    * Function Name: SDA_0_ClearInterrupt
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
    uint8 SDA_0_ClearInterrupt(void) 
    {
        return (SDA_0_INTSTAT & SDA_0_MASK) >> SDA_0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
