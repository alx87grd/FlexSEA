/*******************************************************************************
* File Name: EX5.h  
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

#if !defined(CY_PINS_EX5_H) /* Pins EX5_H */
#define CY_PINS_EX5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX5_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX5__PORT == 15 && ((EX5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX5_Write(uint8 value) ;
void    EX5_SetDriveMode(uint8 mode) ;
uint8   EX5_ReadDataReg(void) ;
uint8   EX5_Read(void) ;
uint8   EX5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX5_DM_RES_UP          PIN_DM_RES_UP
#define EX5_DM_RES_DWN         PIN_DM_RES_DWN
#define EX5_DM_OD_LO           PIN_DM_OD_LO
#define EX5_DM_OD_HI           PIN_DM_OD_HI
#define EX5_DM_STRONG          PIN_DM_STRONG
#define EX5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX5_MASK               EX5__MASK
#define EX5_SHIFT              EX5__SHIFT
#define EX5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX5_PS                     (* (reg8 *) EX5__PS)
/* Data Register */
#define EX5_DR                     (* (reg8 *) EX5__DR)
/* Port Number */
#define EX5_PRT_NUM                (* (reg8 *) EX5__PRT) 
/* Connect to Analog Globals */                                                  
#define EX5_AG                     (* (reg8 *) EX5__AG)                       
/* Analog MUX bux enable */
#define EX5_AMUX                   (* (reg8 *) EX5__AMUX) 
/* Bidirectional Enable */                                                        
#define EX5_BIE                    (* (reg8 *) EX5__BIE)
/* Bit-mask for Aliased Register Access */
#define EX5_BIT_MASK               (* (reg8 *) EX5__BIT_MASK)
/* Bypass Enable */
#define EX5_BYP                    (* (reg8 *) EX5__BYP)
/* Port wide control signals */                                                   
#define EX5_CTL                    (* (reg8 *) EX5__CTL)
/* Drive Modes */
#define EX5_DM0                    (* (reg8 *) EX5__DM0) 
#define EX5_DM1                    (* (reg8 *) EX5__DM1)
#define EX5_DM2                    (* (reg8 *) EX5__DM2) 
/* Input Buffer Disable Override */
#define EX5_INP_DIS                (* (reg8 *) EX5__INP_DIS)
/* LCD Common or Segment Drive */
#define EX5_LCD_COM_SEG            (* (reg8 *) EX5__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX5_LCD_EN                 (* (reg8 *) EX5__LCD_EN)
/* Slew Rate Control */
#define EX5_SLW                    (* (reg8 *) EX5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX5_PRTDSI__CAPS_SEL       (* (reg8 *) EX5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX5_PRTDSI__OE_SEL0        (* (reg8 *) EX5__PRTDSI__OE_SEL0) 
#define EX5_PRTDSI__OE_SEL1        (* (reg8 *) EX5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX5_PRTDSI__OUT_SEL0       (* (reg8 *) EX5__PRTDSI__OUT_SEL0) 
#define EX5_PRTDSI__OUT_SEL1       (* (reg8 *) EX5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX5_PRTDSI__SYNC_OUT       (* (reg8 *) EX5__PRTDSI__SYNC_OUT) 


#if defined(EX5__INTSTAT)  /* Interrupt Registers */

    #define EX5_INTSTAT                (* (reg8 *) EX5__INTSTAT)
    #define EX5_SNAP                   (* (reg8 *) EX5__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX5_H */


/* [] END OF FILE */
