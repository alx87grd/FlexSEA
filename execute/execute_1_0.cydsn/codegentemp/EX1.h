/*******************************************************************************
* File Name: EX1.h  
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

#if !defined(CY_PINS_EX1_H) /* Pins EX1_H */
#define CY_PINS_EX1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX1__PORT == 15 && ((EX1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX1_Write(uint8 value) ;
void    EX1_SetDriveMode(uint8 mode) ;
uint8   EX1_ReadDataReg(void) ;
uint8   EX1_Read(void) ;
uint8   EX1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX1_DM_RES_UP          PIN_DM_RES_UP
#define EX1_DM_RES_DWN         PIN_DM_RES_DWN
#define EX1_DM_OD_LO           PIN_DM_OD_LO
#define EX1_DM_OD_HI           PIN_DM_OD_HI
#define EX1_DM_STRONG          PIN_DM_STRONG
#define EX1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX1_MASK               EX1__MASK
#define EX1_SHIFT              EX1__SHIFT
#define EX1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX1_PS                     (* (reg8 *) EX1__PS)
/* Data Register */
#define EX1_DR                     (* (reg8 *) EX1__DR)
/* Port Number */
#define EX1_PRT_NUM                (* (reg8 *) EX1__PRT) 
/* Connect to Analog Globals */                                                  
#define EX1_AG                     (* (reg8 *) EX1__AG)                       
/* Analog MUX bux enable */
#define EX1_AMUX                   (* (reg8 *) EX1__AMUX) 
/* Bidirectional Enable */                                                        
#define EX1_BIE                    (* (reg8 *) EX1__BIE)
/* Bit-mask for Aliased Register Access */
#define EX1_BIT_MASK               (* (reg8 *) EX1__BIT_MASK)
/* Bypass Enable */
#define EX1_BYP                    (* (reg8 *) EX1__BYP)
/* Port wide control signals */                                                   
#define EX1_CTL                    (* (reg8 *) EX1__CTL)
/* Drive Modes */
#define EX1_DM0                    (* (reg8 *) EX1__DM0) 
#define EX1_DM1                    (* (reg8 *) EX1__DM1)
#define EX1_DM2                    (* (reg8 *) EX1__DM2) 
/* Input Buffer Disable Override */
#define EX1_INP_DIS                (* (reg8 *) EX1__INP_DIS)
/* LCD Common or Segment Drive */
#define EX1_LCD_COM_SEG            (* (reg8 *) EX1__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX1_LCD_EN                 (* (reg8 *) EX1__LCD_EN)
/* Slew Rate Control */
#define EX1_SLW                    (* (reg8 *) EX1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX1_PRTDSI__CAPS_SEL       (* (reg8 *) EX1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX1_PRTDSI__OE_SEL0        (* (reg8 *) EX1__PRTDSI__OE_SEL0) 
#define EX1_PRTDSI__OE_SEL1        (* (reg8 *) EX1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX1_PRTDSI__OUT_SEL0       (* (reg8 *) EX1__PRTDSI__OUT_SEL0) 
#define EX1_PRTDSI__OUT_SEL1       (* (reg8 *) EX1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX1_PRTDSI__SYNC_OUT       (* (reg8 *) EX1__PRTDSI__SYNC_OUT) 


#if defined(EX1__INTSTAT)  /* Interrupt Registers */

    #define EX1_INTSTAT                (* (reg8 *) EX1__INTSTAT)
    #define EX1_SNAP                   (* (reg8 *) EX1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX1_H */


/* [] END OF FILE */
