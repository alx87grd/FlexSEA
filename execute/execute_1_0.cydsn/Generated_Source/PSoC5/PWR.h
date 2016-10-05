/*******************************************************************************
* File Name: PWR.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWR_H) /* Pins PWR_H */
#define CY_PINS_PWR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWR_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWR__PORT == 15 && ((PWR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PWR_Write(uint8 value) ;
void    PWR_SetDriveMode(uint8 mode) ;
uint8   PWR_ReadDataReg(void) ;
uint8   PWR_Read(void) ;
uint8   PWR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWR_DM_RES_UP          PIN_DM_RES_UP
#define PWR_DM_RES_DWN         PIN_DM_RES_DWN
#define PWR_DM_OD_LO           PIN_DM_OD_LO
#define PWR_DM_OD_HI           PIN_DM_OD_HI
#define PWR_DM_STRONG          PIN_DM_STRONG
#define PWR_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWR_MASK               PWR__MASK
#define PWR_SHIFT              PWR__SHIFT
#define PWR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWR_PS                     (* (reg8 *) PWR__PS)
/* Data Register */
#define PWR_DR                     (* (reg8 *) PWR__DR)
/* Port Number */
#define PWR_PRT_NUM                (* (reg8 *) PWR__PRT) 
/* Connect to Analog Globals */                                                  
#define PWR_AG                     (* (reg8 *) PWR__AG)                       
/* Analog MUX bux enable */
#define PWR_AMUX                   (* (reg8 *) PWR__AMUX) 
/* Bidirectional Enable */                                                        
#define PWR_BIE                    (* (reg8 *) PWR__BIE)
/* Bit-mask for Aliased Register Access */
#define PWR_BIT_MASK               (* (reg8 *) PWR__BIT_MASK)
/* Bypass Enable */
#define PWR_BYP                    (* (reg8 *) PWR__BYP)
/* Port wide control signals */                                                   
#define PWR_CTL                    (* (reg8 *) PWR__CTL)
/* Drive Modes */
#define PWR_DM0                    (* (reg8 *) PWR__DM0) 
#define PWR_DM1                    (* (reg8 *) PWR__DM1)
#define PWR_DM2                    (* (reg8 *) PWR__DM2) 
/* Input Buffer Disable Override */
#define PWR_INP_DIS                (* (reg8 *) PWR__INP_DIS)
/* LCD Common or Segment Drive */
#define PWR_LCD_COM_SEG            (* (reg8 *) PWR__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWR_LCD_EN                 (* (reg8 *) PWR__LCD_EN)
/* Slew Rate Control */
#define PWR_SLW                    (* (reg8 *) PWR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWR_PRTDSI__CAPS_SEL       (* (reg8 *) PWR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWR_PRTDSI__OE_SEL0        (* (reg8 *) PWR__PRTDSI__OE_SEL0) 
#define PWR_PRTDSI__OE_SEL1        (* (reg8 *) PWR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWR_PRTDSI__OUT_SEL0       (* (reg8 *) PWR__PRTDSI__OUT_SEL0) 
#define PWR_PRTDSI__OUT_SEL1       (* (reg8 *) PWR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWR_PRTDSI__SYNC_OUT       (* (reg8 *) PWR__PRTDSI__SYNC_OUT) 


#if defined(PWR__INTSTAT)  /* Interrupt Registers */

    #define PWR_INTSTAT                (* (reg8 *) PWR__INTSTAT)
    #define PWR_SNAP                   (* (reg8 *) PWR__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWR_H */


/* [] END OF FILE */
