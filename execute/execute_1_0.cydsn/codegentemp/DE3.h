/*******************************************************************************
* File Name: DE3.h  
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

#if !defined(CY_PINS_DE3_H) /* Pins DE3_H */
#define CY_PINS_DE3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DE3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DE3__PORT == 15 && ((DE3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    DE3_Write(uint8 value) ;
void    DE3_SetDriveMode(uint8 mode) ;
uint8   DE3_ReadDataReg(void) ;
uint8   DE3_Read(void) ;
uint8   DE3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DE3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DE3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DE3_DM_RES_UP          PIN_DM_RES_UP
#define DE3_DM_RES_DWN         PIN_DM_RES_DWN
#define DE3_DM_OD_LO           PIN_DM_OD_LO
#define DE3_DM_OD_HI           PIN_DM_OD_HI
#define DE3_DM_STRONG          PIN_DM_STRONG
#define DE3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DE3_MASK               DE3__MASK
#define DE3_SHIFT              DE3__SHIFT
#define DE3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DE3_PS                     (* (reg8 *) DE3__PS)
/* Data Register */
#define DE3_DR                     (* (reg8 *) DE3__DR)
/* Port Number */
#define DE3_PRT_NUM                (* (reg8 *) DE3__PRT) 
/* Connect to Analog Globals */                                                  
#define DE3_AG                     (* (reg8 *) DE3__AG)                       
/* Analog MUX bux enable */
#define DE3_AMUX                   (* (reg8 *) DE3__AMUX) 
/* Bidirectional Enable */                                                        
#define DE3_BIE                    (* (reg8 *) DE3__BIE)
/* Bit-mask for Aliased Register Access */
#define DE3_BIT_MASK               (* (reg8 *) DE3__BIT_MASK)
/* Bypass Enable */
#define DE3_BYP                    (* (reg8 *) DE3__BYP)
/* Port wide control signals */                                                   
#define DE3_CTL                    (* (reg8 *) DE3__CTL)
/* Drive Modes */
#define DE3_DM0                    (* (reg8 *) DE3__DM0) 
#define DE3_DM1                    (* (reg8 *) DE3__DM1)
#define DE3_DM2                    (* (reg8 *) DE3__DM2) 
/* Input Buffer Disable Override */
#define DE3_INP_DIS                (* (reg8 *) DE3__INP_DIS)
/* LCD Common or Segment Drive */
#define DE3_LCD_COM_SEG            (* (reg8 *) DE3__LCD_COM_SEG)
/* Enable Segment LCD */
#define DE3_LCD_EN                 (* (reg8 *) DE3__LCD_EN)
/* Slew Rate Control */
#define DE3_SLW                    (* (reg8 *) DE3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DE3_PRTDSI__CAPS_SEL       (* (reg8 *) DE3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DE3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DE3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DE3_PRTDSI__OE_SEL0        (* (reg8 *) DE3__PRTDSI__OE_SEL0) 
#define DE3_PRTDSI__OE_SEL1        (* (reg8 *) DE3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DE3_PRTDSI__OUT_SEL0       (* (reg8 *) DE3__PRTDSI__OUT_SEL0) 
#define DE3_PRTDSI__OUT_SEL1       (* (reg8 *) DE3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DE3_PRTDSI__SYNC_OUT       (* (reg8 *) DE3__PRTDSI__SYNC_OUT) 


#if defined(DE3__INTSTAT)  /* Interrupt Registers */

    #define DE3_INTSTAT                (* (reg8 *) DE3__INTSTAT)
    #define DE3_SNAP                   (* (reg8 *) DE3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DE3_H */


/* [] END OF FILE */