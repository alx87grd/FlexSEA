/*******************************************************************************
* File Name: EX0.h  
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

#if !defined(CY_PINS_EX0_H) /* Pins EX0_H */
#define CY_PINS_EX0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX0_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX0__PORT == 15 && ((EX0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX0_Write(uint8 value) ;
void    EX0_SetDriveMode(uint8 mode) ;
uint8   EX0_ReadDataReg(void) ;
uint8   EX0_Read(void) ;
uint8   EX0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX0_DM_RES_UP          PIN_DM_RES_UP
#define EX0_DM_RES_DWN         PIN_DM_RES_DWN
#define EX0_DM_OD_LO           PIN_DM_OD_LO
#define EX0_DM_OD_HI           PIN_DM_OD_HI
#define EX0_DM_STRONG          PIN_DM_STRONG
#define EX0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX0_MASK               EX0__MASK
#define EX0_SHIFT              EX0__SHIFT
#define EX0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX0_PS                     (* (reg8 *) EX0__PS)
/* Data Register */
#define EX0_DR                     (* (reg8 *) EX0__DR)
/* Port Number */
#define EX0_PRT_NUM                (* (reg8 *) EX0__PRT) 
/* Connect to Analog Globals */                                                  
#define EX0_AG                     (* (reg8 *) EX0__AG)                       
/* Analog MUX bux enable */
#define EX0_AMUX                   (* (reg8 *) EX0__AMUX) 
/* Bidirectional Enable */                                                        
#define EX0_BIE                    (* (reg8 *) EX0__BIE)
/* Bit-mask for Aliased Register Access */
#define EX0_BIT_MASK               (* (reg8 *) EX0__BIT_MASK)
/* Bypass Enable */
#define EX0_BYP                    (* (reg8 *) EX0__BYP)
/* Port wide control signals */                                                   
#define EX0_CTL                    (* (reg8 *) EX0__CTL)
/* Drive Modes */
#define EX0_DM0                    (* (reg8 *) EX0__DM0) 
#define EX0_DM1                    (* (reg8 *) EX0__DM1)
#define EX0_DM2                    (* (reg8 *) EX0__DM2) 
/* Input Buffer Disable Override */
#define EX0_INP_DIS                (* (reg8 *) EX0__INP_DIS)
/* LCD Common or Segment Drive */
#define EX0_LCD_COM_SEG            (* (reg8 *) EX0__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX0_LCD_EN                 (* (reg8 *) EX0__LCD_EN)
/* Slew Rate Control */
#define EX0_SLW                    (* (reg8 *) EX0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX0_PRTDSI__CAPS_SEL       (* (reg8 *) EX0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX0_PRTDSI__OE_SEL0        (* (reg8 *) EX0__PRTDSI__OE_SEL0) 
#define EX0_PRTDSI__OE_SEL1        (* (reg8 *) EX0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX0_PRTDSI__OUT_SEL0       (* (reg8 *) EX0__PRTDSI__OUT_SEL0) 
#define EX0_PRTDSI__OUT_SEL1       (* (reg8 *) EX0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX0_PRTDSI__SYNC_OUT       (* (reg8 *) EX0__PRTDSI__SYNC_OUT) 


#if defined(EX0__INTSTAT)  /* Interrupt Registers */

    #define EX0_INTSTAT                (* (reg8 *) EX0__INTSTAT)
    #define EX0_SNAP                   (* (reg8 *) EX0__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX0_H */


/* [] END OF FILE */
