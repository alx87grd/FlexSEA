/*******************************************************************************
 * File Name: project.h
 * PSoC Creator  3.1 SP3
 *
 *  Description:
 *  This file is automatically generated by PSoC Creator and should not 
 *  be edited by hand.
 *
 *
 ********************************************************************************
 * Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
 * You may use this file only in accordance with the license, terms, conditions, 
 * disclaimers, and limitations in the end user license agreement accompanying 
 * the software package with which this file was provided.
 ********************************************************************************/

#include <cyfitter_cfg.h>
#include <cydevice.h>
#include <cydevice_trm.h>
#include <cyfitter.h>
#include <cydisabledsheets.h>
#include <AOP_OUT_aliases.h>
#include <AOP_OUT.h>
#include <Opamp_1.h>
#include <CS1_aliases.h>
#include <CS1.h>
#include <DieTemp_1.h>
#include <SG_VO2_aliases.h>
#include <SG_VO2.h>
#include <ADC_DelSig_1.h>
#include <ADC_SAR_2.h>
#include <i2cclk.h>
#include <I2C_1.h>
#include <I2C_1_PVT.h>
#include <SCL_1_aliases.h>
#include <SCL_1.h>
#include <SDA_1_aliases.h>
#include <SDA_1.h>
#include <CLUTCH_aliases.h>
#include <CLUTCH.h>
#include <EXP5_aliases.h>
#include <EXP5.h>
#include <EXP4_aliases.h>
#include <EXP4.h>
#include <EXP3_aliases.h>
#include <EXP3.h>
#include <EXP0_aliases.h>
#include <EXP0.h>
#include <Q1_I_aliases.h>
#include <Q1_I.h>
#include <ADC_SAR_1.h>
#include <UART_2.h>
#include <RO_aliases.h>
#include <RO.h>
#include <DI_aliases.h>
#include <DI.h>
#include <DE_aliases.h>
#include <DE.h>
#include <NOT_RE_aliases.h>
#include <NOT_RE.h>
#include <isr_t1.h>
#include <Timer_1.h>
#include <MotorDirection.h>
#include <PWML3_aliases.h>
#include <PWML3.h>
#include <PWMH3_aliases.h>
#include <PWMH3.h>
#include <PWML2_aliases.h>
#include <PWML2.h>
#include <PWMH2_aliases.h>
#include <PWMH2.h>
#include <PWM_1.h>
#include <PWML1_aliases.h>
#include <PWML1.h>
#include <PWMH1_aliases.h>
#include <PWMH1.h>
#include <LED_B_aliases.h>
#include <LED_B.h>
#include <LED_G_aliases.h>
#include <LED_G.h>
#include <LED_R_aliases.h>
#include <LED_R.h>
#include <H3_aliases.h>
#include <H3.h>
#include <H2_aliases.h>
#include <H2.h>
#include <H1_aliases.h>
#include <H1.h>
#include <Q1_B_aliases.h>
#include <Q1_B.h>
#include <Q1_A_aliases.h>
#include <Q1_A.h>
#include <QuadDec_1.h>
#include <QuadDec_1_PVT.h>
#include <USBUART_1.h>
#include <USBUART_1_audio.h>
#include <USBUART_1_cdc.h>
#include <USBUART_1_hid.h>
#include <USBUART_1_midi.h>
#include <USBUART_1_pvt.h>
#include <MUXO_aliases.h>
#include <MUXO.h>
#include <AOP_IN_aliases.h>
#include <AOP_IN.h>
#include <REF_aliases.h>
#include <REF.h>
#include <VDAC8_1.h>
#include <EXP1_aliases.h>
#include <EXP1.h>
#include <isr_dma.h>
#include <DMA_2_dma.h>
#include <isr_ds.h>
#include <DMA_1_dma.h>
#include <CS2_aliases.h>
#include <CS2.h>
#include <CS3_aliases.h>
#include <CS3.h>
#include <EXP6_SDA_aliases.h>
#include <EXP6_SDA.h>
#include <EXP7_SCL_aliases.h>
#include <EXP7_SCL.h>
#include <I2C_2.h>
#include <I2C_2_PVT.h>
#include <AMux_1.h>
#include <EXP2_aliases.h>
#include <EXP2.h>
#include <VR1_aliases.h>
#include <VR1.h>
#include <VR1_PRE_aliases.h>
#include <VR1_PRE.h>
#include <VR2_aliases.h>
#include <VR2.h>
#include <Opamp_2.h>
#include <VDAC8_3.h>
#include <Opamp_3.h>
#include <HalfV_aliases.h>
#include <HalfV.h>
#include <PWM_2.h>
#include <Clock_4.h>
#include <RX2_aliases.h>
#include <RX2.h>
#include <RX3_aliases.h>
#include <RX3.h>
#include <DE2_aliases.h>
#include <DE2.h>
#include <DE3_aliases.h>
#include <DE3.h>
#include <TX2_aliases.h>
#include <TX2.h>
#include <TX3_aliases.h>
#include <TX3.h>
#include <NOT_RE2_aliases.h>
#include <NOT_RE2.h>
#include <NOT_RE3_aliases.h>
#include <NOT_RE3.h>
#include <MV1_aliases.h>
#include <MV1.h>
#include <MV2_aliases.h>
#include <MV2.h>
#include <MV3_aliases.h>
#include <MV3.h>
#include <LED_HB_aliases.h>
#include <LED_HB.h>
#include <WDCLK_aliases.h>
#include <WDCLK.h>
#include <EXP10_aliases.h>
#include <EXP10.h>
#include <EXP11_aliases.h>
#include <EXP11.h>
#include <I2C_OPT_PU_aliases.h>
#include <I2C_OPT_PU.h>
#include <VB_SNS_aliases.h>
#include <VB_SNS.h>
#include <EXP8_aliases.h>
#include <EXP8.h>
#include <AMux_2.h>
#include <SG_VO1_aliases.h>
#include <SG_VO1.h>
#include <C8M.h>
#include <ADC_CLK.h>
#include <EXP9_aliases.h>
#include <EXP9.h>
#include <Coast_Brake.h>
#include <VDAC8_2.h>
#include <DMA_3_dma.h>
#include <isr_dma_uart.h>
#include <DMA_4_dma.h>
#include <UART_DMA_XMIT.h>
#include <isr_dma_uart_tx.h>
#include <ADC_DelSig_1_AMux.h>
#include <ADC_DelSig_1_Ext_CP_Clk.h>
#include <ADC_DelSig_1_IRQ.h>
#include <ADC_DelSig_1_theACLK.h>
#include <ADC_SAR_2_IRQ.h>
#include <ADC_SAR_1_IRQ.h>
#include <ADC_SAR_1_theACLK.h>
#include <QuadDec_1_isr.h>
#include <QuadDec_1_Cnt16.h>
#include <USBUART_1_Dm_aliases.h>
#include <USBUART_1_Dm.h>
#include <USBUART_1_Dp_aliases.h>
#include <USBUART_1_Dp.h>
#include <CyHBUS_40MHZ.h>
#include <core_cm3_psoc5.h>
#include <core_cm3.h>
#include <CyDmac.h>
#include <CyFlash.h>
#include <CyLib.h>
#include <cypins.h>
#include <cyPm.h>
#include <CySpc.h>
#include <cytypes.h>
#include <core_cmFunc.h>
#include <core_cmInstr.h>

/*[]*/

