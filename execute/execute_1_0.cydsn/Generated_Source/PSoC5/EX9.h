/*******************************************************************************
* File Name: EX9.h  
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

#if !defined(CY_PINS_EX9_H) /* Pins EX9_H */
#define CY_PINS_EX9_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX9_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX9__PORT == 15 && ((EX9__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX9_Write(uint8 value) ;
void    EX9_SetDriveMode(uint8 mode) ;
uint8   EX9_ReadDataReg(void) ;
uint8   EX9_Read(void) ;
uint8   EX9_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX9_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX9_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX9_DM_RES_UP          PIN_DM_RES_UP
#define EX9_DM_RES_DWN         PIN_DM_RES_DWN
#define EX9_DM_OD_LO           PIN_DM_OD_LO
#define EX9_DM_OD_HI           PIN_DM_OD_HI
#define EX9_DM_STRONG          PIN_DM_STRONG
#define EX9_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX9_MASK               EX9__MASK
#define EX9_SHIFT              EX9__SHIFT
#define EX9_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX9_PS                     (* (reg8 *) EX9__PS)
/* Data Register */
#define EX9_DR                     (* (reg8 *) EX9__DR)
/* Port Number */
#define EX9_PRT_NUM                (* (reg8 *) EX9__PRT) 
/* Connect to Analog Globals */                                                  
#define EX9_AG                     (* (reg8 *) EX9__AG)                       
/* Analog MUX bux enable */
#define EX9_AMUX                   (* (reg8 *) EX9__AMUX) 
/* Bidirectional Enable */                                                        
#define EX9_BIE                    (* (reg8 *) EX9__BIE)
/* Bit-mask for Aliased Register Access */
#define EX9_BIT_MASK               (* (reg8 *) EX9__BIT_MASK)
/* Bypass Enable */
#define EX9_BYP                    (* (reg8 *) EX9__BYP)
/* Port wide control signals */                                                   
#define EX9_CTL                    (* (reg8 *) EX9__CTL)
/* Drive Modes */
#define EX9_DM0                    (* (reg8 *) EX9__DM0) 
#define EX9_DM1                    (* (reg8 *) EX9__DM1)
#define EX9_DM2                    (* (reg8 *) EX9__DM2) 
/* Input Buffer Disable Override */
#define EX9_INP_DIS                (* (reg8 *) EX9__INP_DIS)
/* LCD Common or Segment Drive */
#define EX9_LCD_COM_SEG            (* (reg8 *) EX9__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX9_LCD_EN                 (* (reg8 *) EX9__LCD_EN)
/* Slew Rate Control */
#define EX9_SLW                    (* (reg8 *) EX9__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX9_PRTDSI__CAPS_SEL       (* (reg8 *) EX9__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX9_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX9__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX9_PRTDSI__OE_SEL0        (* (reg8 *) EX9__PRTDSI__OE_SEL0) 
#define EX9_PRTDSI__OE_SEL1        (* (reg8 *) EX9__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX9_PRTDSI__OUT_SEL0       (* (reg8 *) EX9__PRTDSI__OUT_SEL0) 
#define EX9_PRTDSI__OUT_SEL1       (* (reg8 *) EX9__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX9_PRTDSI__SYNC_OUT       (* (reg8 *) EX9__PRTDSI__SYNC_OUT) 


#if defined(EX9__INTSTAT)  /* Interrupt Registers */

    #define EX9_INTSTAT                (* (reg8 *) EX9__INTSTAT)
    #define EX9_SNAP                   (* (reg8 *) EX9__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX9_H */


/* [] END OF FILE */
