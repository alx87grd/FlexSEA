/*******************************************************************************
* File Name: EX10.h  
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

#if !defined(CY_PINS_EX10_H) /* Pins EX10_H */
#define CY_PINS_EX10_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX10_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX10__PORT == 15 && ((EX10__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX10_Write(uint8 value) ;
void    EX10_SetDriveMode(uint8 mode) ;
uint8   EX10_ReadDataReg(void) ;
uint8   EX10_Read(void) ;
uint8   EX10_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX10_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX10_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX10_DM_RES_UP          PIN_DM_RES_UP
#define EX10_DM_RES_DWN         PIN_DM_RES_DWN
#define EX10_DM_OD_LO           PIN_DM_OD_LO
#define EX10_DM_OD_HI           PIN_DM_OD_HI
#define EX10_DM_STRONG          PIN_DM_STRONG
#define EX10_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX10_MASK               EX10__MASK
#define EX10_SHIFT              EX10__SHIFT
#define EX10_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX10_PS                     (* (reg8 *) EX10__PS)
/* Data Register */
#define EX10_DR                     (* (reg8 *) EX10__DR)
/* Port Number */
#define EX10_PRT_NUM                (* (reg8 *) EX10__PRT) 
/* Connect to Analog Globals */                                                  
#define EX10_AG                     (* (reg8 *) EX10__AG)                       
/* Analog MUX bux enable */
#define EX10_AMUX                   (* (reg8 *) EX10__AMUX) 
/* Bidirectional Enable */                                                        
#define EX10_BIE                    (* (reg8 *) EX10__BIE)
/* Bit-mask for Aliased Register Access */
#define EX10_BIT_MASK               (* (reg8 *) EX10__BIT_MASK)
/* Bypass Enable */
#define EX10_BYP                    (* (reg8 *) EX10__BYP)
/* Port wide control signals */                                                   
#define EX10_CTL                    (* (reg8 *) EX10__CTL)
/* Drive Modes */
#define EX10_DM0                    (* (reg8 *) EX10__DM0) 
#define EX10_DM1                    (* (reg8 *) EX10__DM1)
#define EX10_DM2                    (* (reg8 *) EX10__DM2) 
/* Input Buffer Disable Override */
#define EX10_INP_DIS                (* (reg8 *) EX10__INP_DIS)
/* LCD Common or Segment Drive */
#define EX10_LCD_COM_SEG            (* (reg8 *) EX10__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX10_LCD_EN                 (* (reg8 *) EX10__LCD_EN)
/* Slew Rate Control */
#define EX10_SLW                    (* (reg8 *) EX10__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX10_PRTDSI__CAPS_SEL       (* (reg8 *) EX10__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX10_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX10__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX10_PRTDSI__OE_SEL0        (* (reg8 *) EX10__PRTDSI__OE_SEL0) 
#define EX10_PRTDSI__OE_SEL1        (* (reg8 *) EX10__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX10_PRTDSI__OUT_SEL0       (* (reg8 *) EX10__PRTDSI__OUT_SEL0) 
#define EX10_PRTDSI__OUT_SEL1       (* (reg8 *) EX10__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX10_PRTDSI__SYNC_OUT       (* (reg8 *) EX10__PRTDSI__SYNC_OUT) 


#if defined(EX10__INTSTAT)  /* Interrupt Registers */

    #define EX10_INTSTAT                (* (reg8 *) EX10__INTSTAT)
    #define EX10_SNAP                   (* (reg8 *) EX10__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX10_H */


/* [] END OF FILE */
