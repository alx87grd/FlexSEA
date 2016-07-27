/*******************************************************************************
* File Name: EX15.h  
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

#if !defined(CY_PINS_EX15_H) /* Pins EX15_H */
#define CY_PINS_EX15_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX15_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX15__PORT == 15 && ((EX15__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX15_Write(uint8 value) ;
void    EX15_SetDriveMode(uint8 mode) ;
uint8   EX15_ReadDataReg(void) ;
uint8   EX15_Read(void) ;
uint8   EX15_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX15_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX15_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX15_DM_RES_UP          PIN_DM_RES_UP
#define EX15_DM_RES_DWN         PIN_DM_RES_DWN
#define EX15_DM_OD_LO           PIN_DM_OD_LO
#define EX15_DM_OD_HI           PIN_DM_OD_HI
#define EX15_DM_STRONG          PIN_DM_STRONG
#define EX15_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX15_MASK               EX15__MASK
#define EX15_SHIFT              EX15__SHIFT
#define EX15_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX15_PS                     (* (reg8 *) EX15__PS)
/* Data Register */
#define EX15_DR                     (* (reg8 *) EX15__DR)
/* Port Number */
#define EX15_PRT_NUM                (* (reg8 *) EX15__PRT) 
/* Connect to Analog Globals */                                                  
#define EX15_AG                     (* (reg8 *) EX15__AG)                       
/* Analog MUX bux enable */
#define EX15_AMUX                   (* (reg8 *) EX15__AMUX) 
/* Bidirectional Enable */                                                        
#define EX15_BIE                    (* (reg8 *) EX15__BIE)
/* Bit-mask for Aliased Register Access */
#define EX15_BIT_MASK               (* (reg8 *) EX15__BIT_MASK)
/* Bypass Enable */
#define EX15_BYP                    (* (reg8 *) EX15__BYP)
/* Port wide control signals */                                                   
#define EX15_CTL                    (* (reg8 *) EX15__CTL)
/* Drive Modes */
#define EX15_DM0                    (* (reg8 *) EX15__DM0) 
#define EX15_DM1                    (* (reg8 *) EX15__DM1)
#define EX15_DM2                    (* (reg8 *) EX15__DM2) 
/* Input Buffer Disable Override */
#define EX15_INP_DIS                (* (reg8 *) EX15__INP_DIS)
/* LCD Common or Segment Drive */
#define EX15_LCD_COM_SEG            (* (reg8 *) EX15__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX15_LCD_EN                 (* (reg8 *) EX15__LCD_EN)
/* Slew Rate Control */
#define EX15_SLW                    (* (reg8 *) EX15__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX15_PRTDSI__CAPS_SEL       (* (reg8 *) EX15__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX15_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX15__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX15_PRTDSI__OE_SEL0        (* (reg8 *) EX15__PRTDSI__OE_SEL0) 
#define EX15_PRTDSI__OE_SEL1        (* (reg8 *) EX15__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX15_PRTDSI__OUT_SEL0       (* (reg8 *) EX15__PRTDSI__OUT_SEL0) 
#define EX15_PRTDSI__OUT_SEL1       (* (reg8 *) EX15__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX15_PRTDSI__SYNC_OUT       (* (reg8 *) EX15__PRTDSI__SYNC_OUT) 


#if defined(EX15__INTSTAT)  /* Interrupt Registers */

    #define EX15_INTSTAT                (* (reg8 *) EX15__INTSTAT)
    #define EX15_SNAP                   (* (reg8 *) EX15__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX15_H */


/* [] END OF FILE */
