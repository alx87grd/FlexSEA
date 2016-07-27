/*******************************************************************************
* File Name: EX4.h  
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

#if !defined(CY_PINS_EX4_H) /* Pins EX4_H */
#define CY_PINS_EX4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX4_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX4__PORT == 15 && ((EX4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX4_Write(uint8 value) ;
void    EX4_SetDriveMode(uint8 mode) ;
uint8   EX4_ReadDataReg(void) ;
uint8   EX4_Read(void) ;
uint8   EX4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX4_DM_RES_UP          PIN_DM_RES_UP
#define EX4_DM_RES_DWN         PIN_DM_RES_DWN
#define EX4_DM_OD_LO           PIN_DM_OD_LO
#define EX4_DM_OD_HI           PIN_DM_OD_HI
#define EX4_DM_STRONG          PIN_DM_STRONG
#define EX4_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX4_MASK               EX4__MASK
#define EX4_SHIFT              EX4__SHIFT
#define EX4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX4_PS                     (* (reg8 *) EX4__PS)
/* Data Register */
#define EX4_DR                     (* (reg8 *) EX4__DR)
/* Port Number */
#define EX4_PRT_NUM                (* (reg8 *) EX4__PRT) 
/* Connect to Analog Globals */                                                  
#define EX4_AG                     (* (reg8 *) EX4__AG)                       
/* Analog MUX bux enable */
#define EX4_AMUX                   (* (reg8 *) EX4__AMUX) 
/* Bidirectional Enable */                                                        
#define EX4_BIE                    (* (reg8 *) EX4__BIE)
/* Bit-mask for Aliased Register Access */
#define EX4_BIT_MASK               (* (reg8 *) EX4__BIT_MASK)
/* Bypass Enable */
#define EX4_BYP                    (* (reg8 *) EX4__BYP)
/* Port wide control signals */                                                   
#define EX4_CTL                    (* (reg8 *) EX4__CTL)
/* Drive Modes */
#define EX4_DM0                    (* (reg8 *) EX4__DM0) 
#define EX4_DM1                    (* (reg8 *) EX4__DM1)
#define EX4_DM2                    (* (reg8 *) EX4__DM2) 
/* Input Buffer Disable Override */
#define EX4_INP_DIS                (* (reg8 *) EX4__INP_DIS)
/* LCD Common or Segment Drive */
#define EX4_LCD_COM_SEG            (* (reg8 *) EX4__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX4_LCD_EN                 (* (reg8 *) EX4__LCD_EN)
/* Slew Rate Control */
#define EX4_SLW                    (* (reg8 *) EX4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX4_PRTDSI__CAPS_SEL       (* (reg8 *) EX4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX4_PRTDSI__OE_SEL0        (* (reg8 *) EX4__PRTDSI__OE_SEL0) 
#define EX4_PRTDSI__OE_SEL1        (* (reg8 *) EX4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX4_PRTDSI__OUT_SEL0       (* (reg8 *) EX4__PRTDSI__OUT_SEL0) 
#define EX4_PRTDSI__OUT_SEL1       (* (reg8 *) EX4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX4_PRTDSI__SYNC_OUT       (* (reg8 *) EX4__PRTDSI__SYNC_OUT) 


#if defined(EX4__INTSTAT)  /* Interrupt Registers */

    #define EX4_INTSTAT                (* (reg8 *) EX4__INTSTAT)
    #define EX4_SNAP                   (* (reg8 *) EX4__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX4_H */


/* [] END OF FILE */
