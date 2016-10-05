/*******************************************************************************
* File Name: EX11.h  
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

#if !defined(CY_PINS_EX11_H) /* Pins EX11_H */
#define CY_PINS_EX11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX11_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX11__PORT == 15 && ((EX11__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX11_Write(uint8 value) ;
void    EX11_SetDriveMode(uint8 mode) ;
uint8   EX11_ReadDataReg(void) ;
uint8   EX11_Read(void) ;
uint8   EX11_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX11_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX11_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX11_DM_RES_UP          PIN_DM_RES_UP
#define EX11_DM_RES_DWN         PIN_DM_RES_DWN
#define EX11_DM_OD_LO           PIN_DM_OD_LO
#define EX11_DM_OD_HI           PIN_DM_OD_HI
#define EX11_DM_STRONG          PIN_DM_STRONG
#define EX11_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX11_MASK               EX11__MASK
#define EX11_SHIFT              EX11__SHIFT
#define EX11_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX11_PS                     (* (reg8 *) EX11__PS)
/* Data Register */
#define EX11_DR                     (* (reg8 *) EX11__DR)
/* Port Number */
#define EX11_PRT_NUM                (* (reg8 *) EX11__PRT) 
/* Connect to Analog Globals */                                                  
#define EX11_AG                     (* (reg8 *) EX11__AG)                       
/* Analog MUX bux enable */
#define EX11_AMUX                   (* (reg8 *) EX11__AMUX) 
/* Bidirectional Enable */                                                        
#define EX11_BIE                    (* (reg8 *) EX11__BIE)
/* Bit-mask for Aliased Register Access */
#define EX11_BIT_MASK               (* (reg8 *) EX11__BIT_MASK)
/* Bypass Enable */
#define EX11_BYP                    (* (reg8 *) EX11__BYP)
/* Port wide control signals */                                                   
#define EX11_CTL                    (* (reg8 *) EX11__CTL)
/* Drive Modes */
#define EX11_DM0                    (* (reg8 *) EX11__DM0) 
#define EX11_DM1                    (* (reg8 *) EX11__DM1)
#define EX11_DM2                    (* (reg8 *) EX11__DM2) 
/* Input Buffer Disable Override */
#define EX11_INP_DIS                (* (reg8 *) EX11__INP_DIS)
/* LCD Common or Segment Drive */
#define EX11_LCD_COM_SEG            (* (reg8 *) EX11__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX11_LCD_EN                 (* (reg8 *) EX11__LCD_EN)
/* Slew Rate Control */
#define EX11_SLW                    (* (reg8 *) EX11__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX11_PRTDSI__CAPS_SEL       (* (reg8 *) EX11__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX11_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX11__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX11_PRTDSI__OE_SEL0        (* (reg8 *) EX11__PRTDSI__OE_SEL0) 
#define EX11_PRTDSI__OE_SEL1        (* (reg8 *) EX11__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX11_PRTDSI__OUT_SEL0       (* (reg8 *) EX11__PRTDSI__OUT_SEL0) 
#define EX11_PRTDSI__OUT_SEL1       (* (reg8 *) EX11__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX11_PRTDSI__SYNC_OUT       (* (reg8 *) EX11__PRTDSI__SYNC_OUT) 


#if defined(EX11__INTSTAT)  /* Interrupt Registers */

    #define EX11_INTSTAT                (* (reg8 *) EX11__INTSTAT)
    #define EX11_SNAP                   (* (reg8 *) EX11__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX11_H */


/* [] END OF FILE */
