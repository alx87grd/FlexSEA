/*******************************************************************************
* File Name: EX8.h  
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

#if !defined(CY_PINS_EX8_H) /* Pins EX8_H */
#define CY_PINS_EX8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX8_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX8__PORT == 15 && ((EX8__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX8_Write(uint8 value) ;
void    EX8_SetDriveMode(uint8 mode) ;
uint8   EX8_ReadDataReg(void) ;
uint8   EX8_Read(void) ;
uint8   EX8_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX8_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX8_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX8_DM_RES_UP          PIN_DM_RES_UP
#define EX8_DM_RES_DWN         PIN_DM_RES_DWN
#define EX8_DM_OD_LO           PIN_DM_OD_LO
#define EX8_DM_OD_HI           PIN_DM_OD_HI
#define EX8_DM_STRONG          PIN_DM_STRONG
#define EX8_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX8_MASK               EX8__MASK
#define EX8_SHIFT              EX8__SHIFT
#define EX8_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX8_PS                     (* (reg8 *) EX8__PS)
/* Data Register */
#define EX8_DR                     (* (reg8 *) EX8__DR)
/* Port Number */
#define EX8_PRT_NUM                (* (reg8 *) EX8__PRT) 
/* Connect to Analog Globals */                                                  
#define EX8_AG                     (* (reg8 *) EX8__AG)                       
/* Analog MUX bux enable */
#define EX8_AMUX                   (* (reg8 *) EX8__AMUX) 
/* Bidirectional Enable */                                                        
#define EX8_BIE                    (* (reg8 *) EX8__BIE)
/* Bit-mask for Aliased Register Access */
#define EX8_BIT_MASK               (* (reg8 *) EX8__BIT_MASK)
/* Bypass Enable */
#define EX8_BYP                    (* (reg8 *) EX8__BYP)
/* Port wide control signals */                                                   
#define EX8_CTL                    (* (reg8 *) EX8__CTL)
/* Drive Modes */
#define EX8_DM0                    (* (reg8 *) EX8__DM0) 
#define EX8_DM1                    (* (reg8 *) EX8__DM1)
#define EX8_DM2                    (* (reg8 *) EX8__DM2) 
/* Input Buffer Disable Override */
#define EX8_INP_DIS                (* (reg8 *) EX8__INP_DIS)
/* LCD Common or Segment Drive */
#define EX8_LCD_COM_SEG            (* (reg8 *) EX8__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX8_LCD_EN                 (* (reg8 *) EX8__LCD_EN)
/* Slew Rate Control */
#define EX8_SLW                    (* (reg8 *) EX8__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX8_PRTDSI__CAPS_SEL       (* (reg8 *) EX8__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX8_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX8__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX8_PRTDSI__OE_SEL0        (* (reg8 *) EX8__PRTDSI__OE_SEL0) 
#define EX8_PRTDSI__OE_SEL1        (* (reg8 *) EX8__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX8_PRTDSI__OUT_SEL0       (* (reg8 *) EX8__PRTDSI__OUT_SEL0) 
#define EX8_PRTDSI__OUT_SEL1       (* (reg8 *) EX8__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX8_PRTDSI__SYNC_OUT       (* (reg8 *) EX8__PRTDSI__SYNC_OUT) 


#if defined(EX8__INTSTAT)  /* Interrupt Registers */

    #define EX8_INTSTAT                (* (reg8 *) EX8__INTSTAT)
    #define EX8_SNAP                   (* (reg8 *) EX8__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX8_H */


/* [] END OF FILE */
