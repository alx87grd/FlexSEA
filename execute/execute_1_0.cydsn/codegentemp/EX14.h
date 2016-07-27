/*******************************************************************************
* File Name: EX14.h  
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

#if !defined(CY_PINS_EX14_H) /* Pins EX14_H */
#define CY_PINS_EX14_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX14_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX14__PORT == 15 && ((EX14__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX14_Write(uint8 value) ;
void    EX14_SetDriveMode(uint8 mode) ;
uint8   EX14_ReadDataReg(void) ;
uint8   EX14_Read(void) ;
uint8   EX14_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX14_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX14_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX14_DM_RES_UP          PIN_DM_RES_UP
#define EX14_DM_RES_DWN         PIN_DM_RES_DWN
#define EX14_DM_OD_LO           PIN_DM_OD_LO
#define EX14_DM_OD_HI           PIN_DM_OD_HI
#define EX14_DM_STRONG          PIN_DM_STRONG
#define EX14_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX14_MASK               EX14__MASK
#define EX14_SHIFT              EX14__SHIFT
#define EX14_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX14_PS                     (* (reg8 *) EX14__PS)
/* Data Register */
#define EX14_DR                     (* (reg8 *) EX14__DR)
/* Port Number */
#define EX14_PRT_NUM                (* (reg8 *) EX14__PRT) 
/* Connect to Analog Globals */                                                  
#define EX14_AG                     (* (reg8 *) EX14__AG)                       
/* Analog MUX bux enable */
#define EX14_AMUX                   (* (reg8 *) EX14__AMUX) 
/* Bidirectional Enable */                                                        
#define EX14_BIE                    (* (reg8 *) EX14__BIE)
/* Bit-mask for Aliased Register Access */
#define EX14_BIT_MASK               (* (reg8 *) EX14__BIT_MASK)
/* Bypass Enable */
#define EX14_BYP                    (* (reg8 *) EX14__BYP)
/* Port wide control signals */                                                   
#define EX14_CTL                    (* (reg8 *) EX14__CTL)
/* Drive Modes */
#define EX14_DM0                    (* (reg8 *) EX14__DM0) 
#define EX14_DM1                    (* (reg8 *) EX14__DM1)
#define EX14_DM2                    (* (reg8 *) EX14__DM2) 
/* Input Buffer Disable Override */
#define EX14_INP_DIS                (* (reg8 *) EX14__INP_DIS)
/* LCD Common or Segment Drive */
#define EX14_LCD_COM_SEG            (* (reg8 *) EX14__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX14_LCD_EN                 (* (reg8 *) EX14__LCD_EN)
/* Slew Rate Control */
#define EX14_SLW                    (* (reg8 *) EX14__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX14_PRTDSI__CAPS_SEL       (* (reg8 *) EX14__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX14_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX14__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX14_PRTDSI__OE_SEL0        (* (reg8 *) EX14__PRTDSI__OE_SEL0) 
#define EX14_PRTDSI__OE_SEL1        (* (reg8 *) EX14__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX14_PRTDSI__OUT_SEL0       (* (reg8 *) EX14__PRTDSI__OUT_SEL0) 
#define EX14_PRTDSI__OUT_SEL1       (* (reg8 *) EX14__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX14_PRTDSI__SYNC_OUT       (* (reg8 *) EX14__PRTDSI__SYNC_OUT) 


#if defined(EX14__INTSTAT)  /* Interrupt Registers */

    #define EX14_INTSTAT                (* (reg8 *) EX14__INTSTAT)
    #define EX14_SNAP                   (* (reg8 *) EX14__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX14_H */


/* [] END OF FILE */
