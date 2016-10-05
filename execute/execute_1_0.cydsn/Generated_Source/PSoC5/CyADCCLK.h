/*******************************************************************************
* File Name: CyADCCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CyADCCLK_H)
#define CY_CLOCK_CyADCCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void CyADCCLK_Start(void) ;
void CyADCCLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CyADCCLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CyADCCLK_StandbyPower(uint8 state) ;
void CyADCCLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CyADCCLK_GetDividerRegister(void) ;
void CyADCCLK_SetModeRegister(uint8 modeBitMask) ;
void CyADCCLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 CyADCCLK_GetModeRegister(void) ;
void CyADCCLK_SetSourceRegister(uint8 clkSource) ;
uint8 CyADCCLK_GetSourceRegister(void) ;
#if defined(CyADCCLK__CFG3)
void CyADCCLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 CyADCCLK_GetPhaseRegister(void) ;
#endif /* defined(CyADCCLK__CFG3) */

#define CyADCCLK_Enable()                       CyADCCLK_Start()
#define CyADCCLK_Disable()                      CyADCCLK_Stop()
#define CyADCCLK_SetDivider(clkDivider)         CyADCCLK_SetDividerRegister(clkDivider, 1u)
#define CyADCCLK_SetDividerValue(clkDivider)    CyADCCLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define CyADCCLK_SetMode(clkMode)               CyADCCLK_SetModeRegister(clkMode)
#define CyADCCLK_SetSource(clkSource)           CyADCCLK_SetSourceRegister(clkSource)
#if defined(CyADCCLK__CFG3)
#define CyADCCLK_SetPhase(clkPhase)             CyADCCLK_SetPhaseRegister(clkPhase)
#define CyADCCLK_SetPhaseValue(clkPhase)        CyADCCLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(CyADCCLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CyADCCLK_CLKEN              (* (reg8 *) CyADCCLK__PM_ACT_CFG)
#define CyADCCLK_CLKEN_PTR          ((reg8 *) CyADCCLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CyADCCLK_CLKSTBY            (* (reg8 *) CyADCCLK__PM_STBY_CFG)
#define CyADCCLK_CLKSTBY_PTR        ((reg8 *) CyADCCLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CyADCCLK_DIV_LSB            (* (reg8 *) CyADCCLK__CFG0)
#define CyADCCLK_DIV_LSB_PTR        ((reg8 *) CyADCCLK__CFG0)
#define CyADCCLK_DIV_PTR            ((reg16 *) CyADCCLK__CFG0)

/* Clock MSB divider configuration register. */
#define CyADCCLK_DIV_MSB            (* (reg8 *) CyADCCLK__CFG1)
#define CyADCCLK_DIV_MSB_PTR        ((reg8 *) CyADCCLK__CFG1)

/* Mode and source configuration register */
#define CyADCCLK_MOD_SRC            (* (reg8 *) CyADCCLK__CFG2)
#define CyADCCLK_MOD_SRC_PTR        ((reg8 *) CyADCCLK__CFG2)

#if defined(CyADCCLK__CFG3)
/* Analog clock phase configuration register */
#define CyADCCLK_PHASE              (* (reg8 *) CyADCCLK__CFG3)
#define CyADCCLK_PHASE_PTR          ((reg8 *) CyADCCLK__CFG3)
#endif /* defined(CyADCCLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CyADCCLK_CLKEN_MASK         CyADCCLK__PM_ACT_MSK
#define CyADCCLK_CLKSTBY_MASK       CyADCCLK__PM_STBY_MSK

/* CFG2 field masks */
#define CyADCCLK_SRC_SEL_MSK        CyADCCLK__CFG2_SRC_SEL_MASK
#define CyADCCLK_MODE_MASK          (~(CyADCCLK_SRC_SEL_MSK))

#if defined(CyADCCLK__CFG3)
/* CFG3 phase mask */
#define CyADCCLK_PHASE_MASK         CyADCCLK__CFG3_PHASE_DLY_MASK
#endif /* defined(CyADCCLK__CFG3) */

#endif /* CY_CLOCK_CyADCCLK_H */


/* [] END OF FILE */
