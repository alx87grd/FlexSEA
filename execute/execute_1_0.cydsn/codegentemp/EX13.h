/*******************************************************************************
* File Name: EX13.h  
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

#if !defined(CY_PINS_EX13_H) /* Pins EX13_H */
#define CY_PINS_EX13_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX13_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX13__PORT == 15 && ((EX13__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX13_Write(uint8 value) ;
void    EX13_SetDriveMode(uint8 mode) ;
uint8   EX13_ReadDataReg(void) ;
uint8   EX13_Read(void) ;
uint8   EX13_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX13_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX13_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX13_DM_RES_UP          PIN_DM_RES_UP
#define EX13_DM_RES_DWN         PIN_DM_RES_DWN
#define EX13_DM_OD_LO           PIN_DM_OD_LO
#define EX13_DM_OD_HI           PIN_DM_OD_HI
#define EX13_DM_STRONG          PIN_DM_STRONG
#define EX13_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX13_MASK               EX13__MASK
#define EX13_SHIFT              EX13__SHIFT
#define EX13_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX13_PS                     (* (reg8 *) EX13__PS)
/* Data Register */
#define EX13_DR                     (* (reg8 *) EX13__DR)
/* Port Number */
#define EX13_PRT_NUM                (* (reg8 *) EX13__PRT) 
/* Connect to Analog Globals */                                                  
#define EX13_AG                     (* (reg8 *) EX13__AG)                       
/* Analog MUX bux enable */
#define EX13_AMUX                   (* (reg8 *) EX13__AMUX) 
/* Bidirectional Enable */                                                        
#define EX13_BIE                    (* (reg8 *) EX13__BIE)
/* Bit-mask for Aliased Register Access */
#define EX13_BIT_MASK               (* (reg8 *) EX13__BIT_MASK)
/* Bypass Enable */
#define EX13_BYP                    (* (reg8 *) EX13__BYP)
/* Port wide control signals */                                                   
#define EX13_CTL                    (* (reg8 *) EX13__CTL)
/* Drive Modes */
#define EX13_DM0                    (* (reg8 *) EX13__DM0) 
#define EX13_DM1                    (* (reg8 *) EX13__DM1)
#define EX13_DM2                    (* (reg8 *) EX13__DM2) 
/* Input Buffer Disable Override */
#define EX13_INP_DIS                (* (reg8 *) EX13__INP_DIS)
/* LCD Common or Segment Drive */
#define EX13_LCD_COM_SEG            (* (reg8 *) EX13__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX13_LCD_EN                 (* (reg8 *) EX13__LCD_EN)
/* Slew Rate Control */
#define EX13_SLW                    (* (reg8 *) EX13__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX13_PRTDSI__CAPS_SEL       (* (reg8 *) EX13__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX13_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX13__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX13_PRTDSI__OE_SEL0        (* (reg8 *) EX13__PRTDSI__OE_SEL0) 
#define EX13_PRTDSI__OE_SEL1        (* (reg8 *) EX13__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX13_PRTDSI__OUT_SEL0       (* (reg8 *) EX13__PRTDSI__OUT_SEL0) 
#define EX13_PRTDSI__OUT_SEL1       (* (reg8 *) EX13__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX13_PRTDSI__SYNC_OUT       (* (reg8 *) EX13__PRTDSI__SYNC_OUT) 


#if defined(EX13__INTSTAT)  /* Interrupt Registers */

    #define EX13_INTSTAT                (* (reg8 *) EX13__INTSTAT)
    #define EX13_SNAP                   (* (reg8 *) EX13__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX13_H */


/* [] END OF FILE */
