/*******************************************************************************
* File Name: EX12.h  
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

#if !defined(CY_PINS_EX12_H) /* Pins EX12_H */
#define CY_PINS_EX12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EX12_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EX12__PORT == 15 && ((EX12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EX12_Write(uint8 value) ;
void    EX12_SetDriveMode(uint8 mode) ;
uint8   EX12_ReadDataReg(void) ;
uint8   EX12_Read(void) ;
uint8   EX12_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EX12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EX12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EX12_DM_RES_UP          PIN_DM_RES_UP
#define EX12_DM_RES_DWN         PIN_DM_RES_DWN
#define EX12_DM_OD_LO           PIN_DM_OD_LO
#define EX12_DM_OD_HI           PIN_DM_OD_HI
#define EX12_DM_STRONG          PIN_DM_STRONG
#define EX12_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EX12_MASK               EX12__MASK
#define EX12_SHIFT              EX12__SHIFT
#define EX12_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EX12_PS                     (* (reg8 *) EX12__PS)
/* Data Register */
#define EX12_DR                     (* (reg8 *) EX12__DR)
/* Port Number */
#define EX12_PRT_NUM                (* (reg8 *) EX12__PRT) 
/* Connect to Analog Globals */                                                  
#define EX12_AG                     (* (reg8 *) EX12__AG)                       
/* Analog MUX bux enable */
#define EX12_AMUX                   (* (reg8 *) EX12__AMUX) 
/* Bidirectional Enable */                                                        
#define EX12_BIE                    (* (reg8 *) EX12__BIE)
/* Bit-mask for Aliased Register Access */
#define EX12_BIT_MASK               (* (reg8 *) EX12__BIT_MASK)
/* Bypass Enable */
#define EX12_BYP                    (* (reg8 *) EX12__BYP)
/* Port wide control signals */                                                   
#define EX12_CTL                    (* (reg8 *) EX12__CTL)
/* Drive Modes */
#define EX12_DM0                    (* (reg8 *) EX12__DM0) 
#define EX12_DM1                    (* (reg8 *) EX12__DM1)
#define EX12_DM2                    (* (reg8 *) EX12__DM2) 
/* Input Buffer Disable Override */
#define EX12_INP_DIS                (* (reg8 *) EX12__INP_DIS)
/* LCD Common or Segment Drive */
#define EX12_LCD_COM_SEG            (* (reg8 *) EX12__LCD_COM_SEG)
/* Enable Segment LCD */
#define EX12_LCD_EN                 (* (reg8 *) EX12__LCD_EN)
/* Slew Rate Control */
#define EX12_SLW                    (* (reg8 *) EX12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EX12_PRTDSI__CAPS_SEL       (* (reg8 *) EX12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EX12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EX12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EX12_PRTDSI__OE_SEL0        (* (reg8 *) EX12__PRTDSI__OE_SEL0) 
#define EX12_PRTDSI__OE_SEL1        (* (reg8 *) EX12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EX12_PRTDSI__OUT_SEL0       (* (reg8 *) EX12__PRTDSI__OUT_SEL0) 
#define EX12_PRTDSI__OUT_SEL1       (* (reg8 *) EX12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EX12_PRTDSI__SYNC_OUT       (* (reg8 *) EX12__PRTDSI__SYNC_OUT) 


#if defined(EX12__INTSTAT)  /* Interrupt Registers */

    #define EX12_INTSTAT                (* (reg8 *) EX12__INTSTAT)
    #define EX12_SNAP                   (* (reg8 *) EX12__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EX12_H */


/* [] END OF FILE */
