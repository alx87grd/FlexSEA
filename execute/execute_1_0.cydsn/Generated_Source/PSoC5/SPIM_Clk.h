/*******************************************************************************
* File Name: SPIM_Clk.h
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

#if !defined(CY_CLOCK_SPIM_Clk_H)
#define CY_CLOCK_SPIM_Clk_H

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

void SPIM_Clk_Start(void) ;
void SPIM_Clk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SPIM_Clk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SPIM_Clk_StandbyPower(uint8 state) ;
void SPIM_Clk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SPIM_Clk_GetDividerRegister(void) ;
void SPIM_Clk_SetModeRegister(uint8 modeBitMask) ;
void SPIM_Clk_ClearModeRegister(uint8 modeBitMask) ;
uint8 SPIM_Clk_GetModeRegister(void) ;
void SPIM_Clk_SetSourceRegister(uint8 clkSource) ;
uint8 SPIM_Clk_GetSourceRegister(void) ;
#if defined(SPIM_Clk__CFG3)
void SPIM_Clk_SetPhaseRegister(uint8 clkPhase) ;
uint8 SPIM_Clk_GetPhaseRegister(void) ;
#endif /* defined(SPIM_Clk__CFG3) */

#define SPIM_Clk_Enable()                       SPIM_Clk_Start()
#define SPIM_Clk_Disable()                      SPIM_Clk_Stop()
#define SPIM_Clk_SetDivider(clkDivider)         SPIM_Clk_SetDividerRegister(clkDivider, 1u)
#define SPIM_Clk_SetDividerValue(clkDivider)    SPIM_Clk_SetDividerRegister((clkDivider) - 1u, 1u)
#define SPIM_Clk_SetMode(clkMode)               SPIM_Clk_SetModeRegister(clkMode)
#define SPIM_Clk_SetSource(clkSource)           SPIM_Clk_SetSourceRegister(clkSource)
#if defined(SPIM_Clk__CFG3)
#define SPIM_Clk_SetPhase(clkPhase)             SPIM_Clk_SetPhaseRegister(clkPhase)
#define SPIM_Clk_SetPhaseValue(clkPhase)        SPIM_Clk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SPIM_Clk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SPIM_Clk_CLKEN              (* (reg8 *) SPIM_Clk__PM_ACT_CFG)
#define SPIM_Clk_CLKEN_PTR          ((reg8 *) SPIM_Clk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SPIM_Clk_CLKSTBY            (* (reg8 *) SPIM_Clk__PM_STBY_CFG)
#define SPIM_Clk_CLKSTBY_PTR        ((reg8 *) SPIM_Clk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SPIM_Clk_DIV_LSB            (* (reg8 *) SPIM_Clk__CFG0)
#define SPIM_Clk_DIV_LSB_PTR        ((reg8 *) SPIM_Clk__CFG0)
#define SPIM_Clk_DIV_PTR            ((reg16 *) SPIM_Clk__CFG0)

/* Clock MSB divider configuration register. */
#define SPIM_Clk_DIV_MSB            (* (reg8 *) SPIM_Clk__CFG1)
#define SPIM_Clk_DIV_MSB_PTR        ((reg8 *) SPIM_Clk__CFG1)

/* Mode and source configuration register */
#define SPIM_Clk_MOD_SRC            (* (reg8 *) SPIM_Clk__CFG2)
#define SPIM_Clk_MOD_SRC_PTR        ((reg8 *) SPIM_Clk__CFG2)

#if defined(SPIM_Clk__CFG3)
/* Analog clock phase configuration register */
#define SPIM_Clk_PHASE              (* (reg8 *) SPIM_Clk__CFG3)
#define SPIM_Clk_PHASE_PTR          ((reg8 *) SPIM_Clk__CFG3)
#endif /* defined(SPIM_Clk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SPIM_Clk_CLKEN_MASK         SPIM_Clk__PM_ACT_MSK
#define SPIM_Clk_CLKSTBY_MASK       SPIM_Clk__PM_STBY_MSK

/* CFG2 field masks */
#define SPIM_Clk_SRC_SEL_MSK        SPIM_Clk__CFG2_SRC_SEL_MASK
#define SPIM_Clk_MODE_MASK          (~(SPIM_Clk_SRC_SEL_MSK))

#if defined(SPIM_Clk__CFG3)
/* CFG3 phase mask */
#define SPIM_Clk_PHASE_MASK         SPIM_Clk__CFG3_PHASE_DLY_MASK
#endif /* defined(SPIM_Clk__CFG3) */

#endif /* CY_CLOCK_SPIM_Clk_H */


/* [] END OF FILE */
