3rd commit
/** *****************************************************************************
 * \file    comp_conf.h
 * \brief   API for comp_conf.h
 *
 * \section AUTHOR
 *    1. Mohamed Abdelaal
 *
 * \section SVN
 *  $Date: 2022-12-21 10:54:40 +0100 (Wed, 16 Mai 2023) $
 *  $Author: MOHA $
 *  $Revision: 00000 $
 *
 * \section LICENSE
 * Copyright (c) 2023 weidmueller Interface (Germany) GmbH.
 * All rights reserved.
 ***************************************************************************** */
#ifndef HRPWM_CONF_H
#define HRPWM_CONF_H
#ifdef __cplusplus
extern "C"  {
#endif

/*******************************************************************************
 * Included header
 ******************************************************************************/

#include "stm32f3xx_hal.h"
#include "stdtypes.h"
#include "stdmacro.h"
#include "hrtim_gen.h"
#include "hal_globaldef.h"

/*******************************************************************************
 * Local constants and macros (private to module)
 ******************************************************************************/
#define MG_HRTIM1MST_ENA        1
#define MG_HRTIM1A_ENA          1
#define MG_HRTIM1B_ENA          1
#define MG_HRTIM1C_ENA          1
#define MG_HRTIM1D_ENA          0
#define MG_HRTIM1E_ENA          0
#define MG_HRTIM1F_ENA          0

#define MG_F32_NS_HRPWM_ADC_SAMPLE_ADJ  20
#define MG_U16_HRPWM_ADC_SAMPLE_ADJ  (uint16)(MG_F32_NS_HRPWM_ADC_SAMPLE_ADJ)

/*******************************************************************************
 * General purpose section
 ******************************************************************************/
/* Registers */
#define MG_REG_PWM_A_B_C_OFF            (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TB1 | HRTIM_OUTPUT_TC1))

#define MG_REG_PWM_A_ON                 (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TA2))
#define MG_REG_PWM_A_OFF                (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TA2))
#define MG_REG_PWM_B_ON                 (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TB1 | HRTIM_OUTPUT_TB2))
#define MG_REG_PWM_B_OFF                (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TB1 | HRTIM_OUTPUT_TB2))
#define MG_REG_PWM_C_ON                 (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TC1 | HRTIM_OUTPUT_TC2))
#define MG_REG_PWM_C_OFF                (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TC1 | HRTIM_OUTPUT_TC2))
#define MG_REG_PWM_D_ON                 (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TD1 | HRTIM_OUTPUT_TD2))
#define MG_REG_PWM_D_OFF                (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TD1 | HRTIM_OUTPUT_TD2))
#define MG_REG_PWM_E_ON                 (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TE1 | HRTIM_OUTPUT_TE2))
#define MG_REG_PWM_E_OFF                (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TE1 | HRTIM_OUTPUT_TE2))

#define MG_REG_PWM_TA1_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TA1))
#define MG_REG_PWM_TA1_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TA1))
#define MG_REG_PWM_TA2_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TA2))
#define MG_REG_PWM_TA2_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TA2))
#define MG_REG_PWM_TB1_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TB1))
#define MG_REG_PWM_TB1_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TB1))
#define MG_REG_PWM_TB2_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TB2))
#define MG_REG_PWM_TB2_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TB2))
#define MG_REG_PWM_TC1_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TC1))
#define MG_REG_PWM_TC1_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TC1))
#define MG_REG_PWM_TC2_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TC2))
#define MG_REG_PWM_TC2_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TC2))
#define MG_REG_PWM_TD1_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TD1))
#define MG_REG_PWM_TD1_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TD1))
#define MG_REG_PWM_TD2_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TD2))
#define MG_REG_PWM_TD2_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TD2))
#define MG_REG_PWM_TE1_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TE1))
#define MG_REG_PWM_TE1_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TE1))
#define MG_REG_PWM_TE2_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TE2))
#define MG_REG_PWM_TE2_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TE2))
#define MG_REG_PWM_TF1_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TF1))
#define MG_REG_PWM_TF1_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TF1))
#define MG_REG_PWM_TF2_ON               (HRTIM1->sCommonRegs.OENR |= (HRTIM_OUTPUT_TF2))
#define MG_REG_PWM_TF2_OFF              (HRTIM1->sCommonRegs.ODISR |= (HRTIM_OUTPUT_TF2))

#define MG_REG_HRTIMER1_MST_UPDATE_EN   (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_MUDIS))
#define MG_REG_HRTIMER1_MST_UPDATE_DIS  (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_MUDIS))
#define MG_REG_HRTIMER1_A_UPDATE_EN     (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TAUDIS))
#define MG_REG_HRTIMER1_A_UPDATE_DIS    (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TAUDIS))
#define MG_REG_HRTIMER1_B_UPDATE_EN     (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TBUDIS))
#define MG_REG_HRTIMER1_B_UPDATE_DIS    (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TBUDIS))
#define MG_REG_HRTIMER1_C_UPDATE_EN     (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TCUDIS))
#define MG_REG_HRTIMER1_C_UPDATE_DIS    (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TCUDIS))
#define MG_REG_HRTIMER1_D_UPDATE_EN     (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TDUDIS))
#define MG_REG_HRTIMER1_D_UPDATE_DIS    (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TDUDIS))
#define MG_REG_HRTIMER1_E_UPDATE_EN     (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TEUDIS))
#define MG_REG_HRTIMER1_E_UPDATE_DIS    (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TEUDIS))
#define MG_REG_HRTIMER1_F_UPDATE_EN     (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TFUDIS))
#define MG_REG_HRTIMER1_F_UPDATE_DIS    (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TFUDIS))
#define MG_REG_HRTIMER1_UPDATE_EN       (HRTIM1->sCommonRegs.CR1 &= ~(HRTIM_CR1_TAUDIS | HRTIM_CR1_TBUDIS))
#define MG_REG_HRTIMER1_UPDATE_DIS      (HRTIM1->sCommonRegs.CR1 |= (HRTIM_CR1_TAUDIS | HRTIM_CR1_TBUDIS))

#define MG_REG_HRTIMER1_A_EN            (HRTIM1->sMasterRegs.MCR |= (HRTIM_TIMERID_TIMER_A))
#define MG_REG_HRTIMER1_A_DIS           (HRTIM1->sMasterRegs.MCR &= ~(HRTIM_TIMERID_TIMER_A))

#define MG_REG_HRTIMER1_B_EN            (HRTIM1->sMasterRegs.MCR |= (HRTIM_TIMERID_TIMER_B))
#define MG_REG_HRTIMER1_B_DIS           (HRTIM1->sMasterRegs.MCR &= ~(HRTIM_TIMERID_TIMER_B))

#define MG_REG_HRTIMER1_C_EN            (HRTIM1->sMasterRegs.MCR |= (HRTIM_TIMERID_TIMER_C))
#define MG_REG_HRTIMER1_C_DIS           (HRTIM1->sMasterRegs.MCR &= ~(HRTIM_TIMERID_TIMER_C))

#define MG_REG_HRTIMER1_D_EN            (HRTIM1->sMasterRegs.MCR |= (HRTIM_TIMERID_TIMER_D))
#define MG_REG_HRTIMER1_D_DIS           (HRTIM1->sMasterRegs.MCR &= ~(HRTIM_TIMERID_TIMER_D))

#define MG_REG_HRTIMER1_E_EN            (HRTIM1->sMasterRegs.MCR |= (HRTIM_TIMERID_TIMER_E))
#define MG_REG_HRTIMER1_E_DIS           (HRTIM1->sMasterRegs.MCR &= ~(HRTIM_TIMERID_TIMER_E))

#define MG_REG_HRTIMER1_F_EN            (HRTIM1->sMasterRegs.MCR |= (HRTIM_TIMERID_TIMER_F))
#define MG_REG_HRTIMER1_F_DIS           (HRTIM1->sMasterRegs.MCR &= ~(HRTIM_TIMERID_TIMER_F))

#define MG_REG_HRTIMER1_A_CTR_RST       (HRTIM1->sCommonRegs.CR2 = HRTIM_CR2_TARST)
#define MG_REG_HRTIMER1_B_CTR_RST       (HRTIM1->sCommonRegs.CR2 = HRTIM_CR2_TBRST)
#define MG_REG_HRTIMER1_C_CTR_RST       (HRTIM1->sCommonRegs.CR2 = HRTIM_CR2_TCRST)
#define MG_REG_HRTIMER1_D_CTR_RST       (HRTIM1->sCommonRegs.CR2 = HRTIM_CR2_TDRST)
#define MG_REG_HRTIMER1_E_CTR_RST       (HRTIM1->sCommonRegs.CR2 = HRTIM_CR2_TERST)
#define MG_REG_HRTIMER1_F_CTR_RST       (HRTIM1->sCommonRegs.CR2 = HRTIM_CR2_TFRST)

#define MG_REG_HRTIMER1_A_CTR_REG       (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CNTxR)
#define MG_REG_HRTIMER1_B_CTR_REG       (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CNTxR)
#define MG_REG_HRTIMER1_C_CTR_REG       (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CNTxR)
#define MG_REG_HRTIMER1_D_CTR_REG       (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CNTxR)
#define MG_REG_HRTIMER1_E_CTR_REG       (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CNTxR)
#define MG_REG_HRTIMER1_F_CTR_REG       (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_F].CNTxR)

#define MG_REG_HRTIMER1_MST_CMP1        (HRTIM1->sMasterRegs.MCMP1R)
#define MG_REG_HRTIMER1_MST_CMP2        (HRTIM1->sMasterRegs.MCMP2R)
#define MG_REG_HRTIMER1_MST_CMP3        (HRTIM1->sMasterRegs.MCMP3R)
#define MG_REG_HRTIMER1_MST_CMP4        (HRTIM1->sMasterRegs.MCMP4R)

#define MG_REG_HRTIMER1_A_CMP1          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP1xR)
#define MG_REG_HRTIMER1_A_CMP2          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP2xR)
#define MG_REG_HRTIMER1_A_CMP3          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP3xR)
#define MG_REG_HRTIMER1_A_CMP4          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP4xR)

#define MG_REG_HRTIMER1_B_CMP1          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP1xR)
#define MG_REG_HRTIMER1_B_CMP2          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP2xR)
#define MG_REG_HRTIMER1_B_CMP3          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP3xR)
#define MG_REG_HRTIMER1_B_CMP4          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP4xR)

#define MG_REG_HRTIMER1_C_CMP1          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CMP1xR)
#define MG_REG_HRTIMER1_C_CMP2          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CMP2xR)
#define MG_REG_HRTIMER1_C_CMP3          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CMP3xR)
#define MG_REG_HRTIMER1_C_CMP4          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CMP4xR)

#define MG_REG_HRTIMER1_D_CMP1          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CMP1xR)
#define MG_REG_HRTIMER1_D_CMP2          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CMP2xR)
#define MG_REG_HRTIMER1_D_CMP3          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CMP3xR)
#define MG_REG_HRTIMER1_D_CMP4          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CMP4xR)

#define MG_REG_HRTIMER1_E_CMP1          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CMP1xR)
#define MG_REG_HRTIMER1_E_CMP2          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CMP2xR)
#define MG_REG_HRTIMER1_E_CMP3          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CMP3xR)
#define MG_REG_HRTIMER1_E_CMP4          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CMP4xR)


#define MG_REG_HRTIMER1_MST_PERIOD      (HRTIM1->sMasterRegs.MPER)
#define MG_REG_HRTIMER1_A_PERIOD        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].PERxR)
#define MG_REG_HRTIMER1_B_PERIOD        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].PERxR)
#define MG_REG_HRTIMER1_C_PERIOD        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].PERxR)
#define MG_REG_HRTIMER1_D_PERIOD        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].PERxR)
#define MG_REG_HRTIMER1_E_PERIOD        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].PERxR)


/* Set DeadTime*/
#define MG_REG_HRTIMER1_A_DT_R(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].DTxR & 0xFFFFFE00) + var))
#define MG_REG_HRTIMER1_A_DT_F(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].DTxR & 0xFE00FFFF) + (var << 16)))
#define MG_REG_HRTIMER1_B_DT_R(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].DTxR & 0xFFFFFE00) + var))
#define MG_REG_HRTIMER1_B_DT_F(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].DTxR & 0xFE00FFFF) + (var << 16)))
#define MG_REG_HRTIMER1_C_DT_R(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].DTxR & 0xFFFFFE00) + var))
#define MG_REG_HRTIMER1_C_DT_F(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].DTxR & 0xFE00FFFF) + (var << 16)))
#define MG_REG_HRTIMER1_D_DT_R(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].DTxR & 0xFFFFFE00) + var))
#define MG_REG_HRTIMER1_D_DT_F(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].DTxR & 0xFE00FFFF) + (var << 16)))
#define MG_REG_HRTIMER1_E_DT_R(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].DTxR & 0xFFFFFE00) + var))
#define MG_REG_HRTIMER1_E_DT_F(var)     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].DTxR = ((HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].DTxR & 0xFE00FFFF) + (var << 16)))


/* Read Fautt Status Read*/
#define MG_REG_HRTIMER1_FAULT1          (HRTIM1->sCommonRegs.ISR & HRTIM_FAULT_1)
#define MG_REG_HRTIMER1_FAULT2          (HRTIM1->sCommonRegs.ISR & HRTIM_FAULT_2)
#define MG_REG_HRTIMER1_FAULT3          (HRTIM1->sCommonRegs.ISR & HRTIM_FAULT_3)
#define MG_REG_HRTIMER1_FAULT4          (HRTIM1->sCommonRegs.ISR & HRTIM_FAULT_4)
#define MG_REG_HRTIMER1_FAULT5          (HRTIM1->sCommonRegs.ISR & HRTIM_FAULT_5)

/*Fault  Clear*/

#define MG_REG_HRTIMER1_FAULT1_CLR      (HRTIM1->sCommonRegs.ICR = HRTIM_FAULT_1)
#define MG_REG_HRTIMER1_FAULT2_CLR      (HRTIM1->sCommonRegs.ICR = HRTIM_FAULT_2)
#define MG_REG_HRTIMER1_FAULT3_CLR      (HRTIM1->sCommonRegs.ICR = HRTIM_FAULT_3)
#define MG_REG_HRTIMER1_FAULT4_CLR      (HRTIM1->sCommonRegs.ICR = HRTIM_FAULT_4)
#define MG_REG_HRTIMER1_FAULT5_CLR      (HRTIM1->sCommonRegs.ICR = HRTIM_FAULT_5)

/*Fault  Enable/Disable*/
#define MG_REG_HRTIMER1_FLT1_EN         (HRTIM1->sCommonRegs.FLTINR1 |= (HRTIM_FLTINR1_FLT1E));
#define MG_REG_HRTIMER1_FLT1_DIS        (HRTIM1->sCommonRegs.FLTINR1 &= ~(HRTIM_FLTINR1_FLT1E));
#define MG_REG_HRTIMER1_FLT2_EN         (HRTIM1->sCommonRegs.FLTINR1 |= (HRTIM_FLTINR1_FLT2E));
#define MG_REG_HRTIMER1_FLT2_DIS        (HRTIM1->sCommonRegs.FLTINR1 &= ~(HRTIM_FLTINR1_FLT2E));
#define MG_REG_HRTIMER1_FLT3_EN         (HRTIM1->sCommonRegs.FLTINR1 |= (HRTIM_FLTINR1_FLT3E));
#define MG_REG_HRTIMER1_FLT3_DIS        (HRTIM1->sCommonRegs.FLTINR1 &= ~(HRTIM_FLTINR1_FLT3E));
#define MG_REG_HRTIMER1_FLT5_EN         (HRTIM1->sCommonRegs.FLTINR2 |= (HRTIM_FLTINR2_FLT5E));
#define MG_REG_HRTIMER1_FLT5_DIS        (HRTIM1->sCommonRegs.FLTINR2 &= ~(HRTIM_FLTINR2_FLT5E));
/*Fault  Polarity*/
#define MG_REG_HRTIMER1_FLT1_POL_HIGH   (HRTIM1->sCommonRegs.FLTINR1 |= (HRTIM_FLTINR1_FLT1P));
#define MG_REG_HRTIMER1_FLT1_POL_LOW    (HRTIM1->sCommonRegs.FLTINR1 &= ~(HRTIM_FLTINR1_FLT1P));
#define MG_REG_HRTIMER1_FLT2_POL_HIGH   (HRTIM1->sCommonRegs.FLTINR1 |= (HRTIM_FLTINR1_FLT2P));
#define MG_REG_HRTIMER1_FLT2_POL_LOW    (HRTIM1->sCommonRegs.FLTINR1 &= ~(HRTIM_FLTINR1_FLT2P));
#define MG_REG_HRTIMER1_FLT3_POL_HIGH   (HRTIM1->sCommonRegs.FLTINR1 |= (HRTIM_FLTINR1_FLT3P));
#define MG_REG_HRTIMER1_FLT3_POL_LOW    (HRTIM1->sCommonRegs.FLTINR1 &= ~(HRTIM_FLTINR1_FLT3P));
#define MG_REG_HRTIMER1_FLT5_POL_HIGH   (HRTIM1->sCommonRegs.FLTINR2 |= (HRTIM_FLTINR2_FLT5P));
#define MG_REG_HRTIMER1_FLT5_POL_LOW    (HRTIM1->sCommonRegs.FLTINR2 &= ~(HRTIM_FLTINR2_FLT5P));

/*Events Polarity*/
#define MG_REG_HRTIMER1_EEV1_POL_HIGH   (HRTIM1->sCommonRegs.EECR1 &= ~(HRTIM_EECR1_EE1POL));
#define MG_REG_HRTIMER1_EEV1_POL_LOW    (HRTIM1->sCommonRegs.EECR1 |= (HRTIM_EECR1_EE1POL));
#define MG_REG_HRTIMER1_EEV2_POL_HIGH   (HRTIM1->sCommonRegs.EECR1 &= ~(HRTIM_EECR1_EE2POL));
#define MG_REG_HRTIMER1_EEV2_POL_LOW    (HRTIM1->sCommonRegs.EECR1 |= (HRTIM_EECR1_EE2POL));
#define MG_REG_HRTIMER1_EEV3_POL_HIGH   (HRTIM1->sCommonRegs.EECR1 &= ~(HRTIM_EECR1_EE3POL));
#define MG_REG_HRTIMER1_EEV3_POL_LOW    (HRTIM1->sCommonRegs.EECR1 |= (HRTIM_EECR1_EE3POL));
#define MG_REG_HRTIMER1_EEV4_POL_HIGH   (HRTIM1->sCommonRegs.EECR1 &= ~(HRTIM_EECR1_EE4POL));
#define MG_REG_HRTIMER1_EEV4_POL_LOW    (HRTIM1->sCommonRegs.EECR1 |= (HRTIM_EECR1_EE4POL));
#define MG_REG_HRTIMER1_EEV5_POL_HIGH   (HRTIM1->sCommonRegs.EECR1 &= ~(HRTIM_EECR1_EE5POL));
#define MG_REG_HRTIMER1_EEV5_POL_LOW    (HRTIM1->sCommonRegs.EECR1 |= (HRTIM_EECR1_EE5POL));
#define MG_REG_HRTIMER1_EEV6_POL_HIGH   (HRTIM1->sCommonRegs.EECR2 &= ~(HRTIM_EECR2_EE6POL));
#define MG_REG_HRTIMER1_EEV6_POL_LOW    (HRTIM1->sCommonRegs.EECR2 |= (HRTIM_EECR2_EE6POL));



#if 0
#define MG_REG_HRTIMER1_MST_REP_IR_CLR  (HRTIM1->sMasterRegs.MICR |= HRTIM_MISR_MREP)
#define MG_REG_HRTIMER1_MST_CMP1_IR_CLR (HRTIM1->sMasterRegs.MICR |= HRTIM_MASTER_FLAG_MCMP1)
#define MG_REG_HRTIMER1_MST_CMP2_IR_CLR (HRTIM1->sMasterRegs.MICR |= HRTIM_MASTER_FLAG_MCMP2)
#define MG_REG_HRTIMER1_MST_CMP3_IR_CLR (HRTIM1->sMasterRegs.MICR |= HRTIM_MASTER_FLAG_MCMP3)
#define MG_REG_HRTIMER1_MST_CMP4_IR_CLR (HRTIM1->sMasterRegs.MICR |= HRTIM_MASTER_FLAG_MCMP4)



#define MG_REG_HRTIMER1_MST_REP_IR_RD   (HRTIM1->sMasterRegs.MISR & HRTIM_MISR_MREP)
#define MG_REG_HRTIMER1_MST_CMP1_IR_RD  (HRTIM1->sMasterRegs.MISR & HRTIM_MASTER_FLAG_MCMP1)
#define MG_REG_HRTIMER1_MST_CMP2_IR_RD  (HRTIM1->sMasterRegs.MISR & HRTIM_MASTER_FLAG_MCMP2)
#define MG_REG_HRTIMER1_MST_CMP3_IR_RD  (HRTIM1->sMasterRegs.MISR & HRTIM_MASTER_FLAG_MCMP3)
#define MG_REG_HRTIMER1_MST_CMP4_IR_RD  (HRTIM1->sMasterRegs.MISR & HRTIM_MASTER_FLAG_MCMP4)

#define MG_REG_HRTIMER1_A_REP_IR_CLR    (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].TIMxICR |= HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_B_REP_IR_CLR    (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].TIMxICR |= HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_C_REP_IR_CLR    (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].TIMxICR |= HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_D_REP_IR_CLR    (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].TIMxICR |= HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_E_REP_IR_CLR    (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].TIMxICR |= HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_F_REP_IR_CLR    (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_F].TIMxICR |= HRTIM_TIMISR_REP)

#define MG_REG_HRTIMER1_A_REP_IR_RD     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].TIMxISR & HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_B_REP_IR_RD     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].TIMxISR & HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_C_REP_IR_RD     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].TIMxISR & HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_D_REP_IR_RD     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].TIMxISR & HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_E_REP_IR_RD     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].TIMxISR & HRTIM_TIMISR_REP)
#define MG_REG_HRTIMER1_F_REP_IR_RD     (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_F].TIMxISR & HRTIM_TIMISR_REP)
#endif

#if 0
#define MG_REG_HRTIMER1_A_CAPT_1        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CPT1xR)
#define MG_REG_HRTIMER1_A_CAPT_2        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CPT2xR)
#define MG_REG_HRTIMER1_B_CAPT_1        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CPT1xR)
#define MG_REG_HRTIMER1_B_CAPT_2        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CPT2xR)
#define MG_REG_HRTIMER1_C_CAPT_1        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CPT1xR)
#define MG_REG_HRTIMER1_C_CAPT_2        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CPT2xR)
#define MG_REG_HRTIMER1_D_CAPT_1        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CPT1xR)
#define MG_REG_HRTIMER1_D_CAPT_2        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CPT2xR)
#define MG_REG_HRTIMER1_E_CAPT_1        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CPT1xR)
#define MG_REG_HRTIMER1_E_CAPT_2        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].CPT2xR)
#define MG_REG_HRTIMER1_F_CAPT_1        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_F].CPT1xR)
#define MG_REG_HRTIMER1_F_CAPT_2        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_F].CPT2xR)
#endif

#if 0
#define MG_REG_HRTIMER1_ADCT1_PS(var)   (HRTIM1->sCommonRegs.ADCPS1 = ((HRTIM1->sCommonRegs.ADCPS1 & ~HRTIM_ADCPS1_AD1PSC) + (var << HRTIM_ADCPS1_AD1PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT2_PS(var)   (HRTIM1->sCommonRegs.ADCPS1 = ((HRTIM1->sCommonRegs.ADCPS1 & ~HRTIM_ADCPS1_AD2PSC) + (var << HRTIM_ADCPS1_AD2PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT3_PS(var)   (HRTIM1->sCommonRegs.ADCPS1 = ((HRTIM1->sCommonRegs.ADCPS1 & ~HRTIM_ADCPS1_AD3PSC) + (var << HRTIM_ADCPS1_AD3PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT4_PS(var)   (HRTIM1->sCommonRegs.ADCPS1 = ((HRTIM1->sCommonRegs.ADCPS1 & ~HRTIM_ADCPS1_AD4PSC) + (var << HRTIM_ADCPS1_AD4PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT5_PS(var)   (HRTIM1->sCommonRegs.ADCPS1 = ((HRTIM1->sCommonRegs.ADCPS1 & ~HRTIM_ADCPS1_AD5PSC) + (var << HRTIM_ADCPS1_AD5PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT6_PS(var)   (HRTIM1->sCommonRegs.ADCPS2 = ((HRTIM1->sCommonRegs.ADCPS2 & ~HRTIM_ADCPS2_AD6PSC) + (var << HRTIM_ADCPS2_AD6PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT7_PS(var)   (HRTIM1->sCommonRegs.ADCPS2 = ((HRTIM1->sCommonRegs.ADCPS2 & ~HRTIM_ADCPS2_AD7PSC) + (var << HRTIM_ADCPS2_AD7PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT8_PS(var)   (HRTIM1->sCommonRegs.ADCPS2 = ((HRTIM1->sCommonRegs.ADCPS2 & ~HRTIM_ADCPS2_AD8PSC) + (var << HRTIM_ADCPS2_AD8PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT9_PS(var)   (HRTIM1->sCommonRegs.ADCPS2 = ((HRTIM1->sCommonRegs.ADCPS2 & ~HRTIM_ADCPS2_AD9PSC) + (var << HRTIM_ADCPS2_AD9PSC_Pos)))
#define MG_REG_HRTIMER1_ADCT10_PS(var)  (HRTIM1->sCommonRegs.ADCPS2 = ((HRTIM1->sCommonRegs.ADCPS2 & ~HRTIM_ADCPS2_AD10PSC) + (var << HRTIM_ADCPS2_AD10PSC_Pos)))
#endif

#define MG_HRTIMER1_MASTER_UPDATE       (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_MSWU)
#define MG_HRTIMER1_A_UPDATE            (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TASWU)
#define MG_HRTIMER1_B_UPDATE            (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TBSWU)
#define MG_HRTIMER1_C_UPDATE            (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TCSWU)
#define MG_HRTIMER1_D_UPDATE            (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TDSWU)
#define MG_HRTIMER1_E_UPDATE            (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TESWU)
#define MG_HRTIMER1_F_UPDATE            (HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TFSWU)

/***************************************
 * Hrtimer Output SW Set/Reset
 **************************************/
#define MG_REG_HRTIMER1_A1_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].SETx1R |= HRTIM_SET1R_SST)
#define MG_REG_HRTIMER1_A2_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].SETx2R |= HRTIM_SET2R_SST)
#define MG_REG_HRTIMER1_A1_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].RSTx1R |= HRTIM_RST1R_SRT)
#define MG_REG_HRTIMER1_A2_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].RSTx2R |= HRTIM_RST2R_SRT)

#define MG_REG_HRTIMER1_B1_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].SETx1R |= HRTIM_SET1R_SST)
#define MG_REG_HRTIMER1_B2_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].SETx2R |= HRTIM_SET2R_SST)
#define MG_REG_HRTIMER1_B1_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].RSTx1R |= HRTIM_RST1R_SRT)
#define MG_REG_HRTIMER1_B2_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].RSTx2R |= HRTIM_RST2R_SRT)

#define MG_REG_HRTIMER1_C1_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].SETx1R |= HRTIM_SET1R_SST)
#define MG_REG_HRTIMER1_C2_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].SETx2R |= HRTIM_SET2R_SST)
#define MG_REG_HRTIMER1_C1_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].RSTx1R |= HRTIM_RST1R_SRT)
#define MG_REG_HRTIMER1_C2_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].RSTx2R |= HRTIM_RST2R_SRT)

#define MG_REG_HRTIMER1_D1_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].SETx1R |= HRTIM_SET1R_SST)
#define MG_REG_HRTIMER1_D2_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].SETx2R |= HRTIM_SET2R_SST)
#define MG_REG_HRTIMER1_D1_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].RSTx1R |= HRTIM_RST1R_SRT)
#define MG_REG_HRTIMER1_D2_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].RSTx2R |= HRTIM_RST2R_SRT)

#define MG_REG_HRTIMER1_E1_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].SETx1R |= HRTIM_SET1R_SST)
#define MG_REG_HRTIMER1_E2_SET          (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].SETx2R |= HRTIM_SET2R_SST)
#define MG_REG_HRTIMER1_E1_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].RSTx1R |= HRTIM_RST1R_SRT)
#define MG_REG_HRTIMER1_E2_RESET        (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_E].RSTx2R |= HRTIM_RST2R_SRT)


/***************************************
 * Swap Registers [not implemented in hrtimer v1[STF334]]
 **************************************/
#if 0 //TDODO th think there is not swap in F3
#define MG_REG_HRTIMER1_A_OUT_SWAP      (HRTIM1->sCommonRegs.CR2 |= (HRTIM_CR2_SWPA));
#define MG_REG_HRTIMER1_A_OUT_SWAP_BACK (HRTIM1->sCommonRegs.CR2 &= ~(HRTIM_CR2_SWPA));
#define MG_REG_HRTIMER1_B_OUT_SWAP      (HRTIM1->sCommonRegs.CR2 |= (HRTIM_CR2_SWPB));
#define MG_REG_HRTIMER1_B_OUT_SWAP_BACK (HRTIM1->sCommonRegs.CR2 &= ~(HRTIM_CR2_SWPB));
//#define MG_REG_HRTIMER1_C_OUT_SWAP      (HRTIM1->sCommonRegs.CR2 |= (HRTIM_CR2_SWPC));
//#define MG_REG_HRTIMER1_C_OUT_SWAP_BACK (HRTIM1->sCommonRegs.CR2 &= ~(HRTIM_CR2_SWPC));
#define MG_REG_HRTIMER1_D_OUT_SWAP      (HRTIM1->sCommonRegs.CR2 |= (HRTIM_CR2_SWPD));
#define MG_REG_HRTIMER1_D_OUT_SWAP_BACK (HRTIM1->sCommonRegs.CR2 &= ~(HRTIM_CR2_SWPD));
#define MG_REG_HRTIMER1_E_OUT_SWAP      (HRTIM1->sCommonRegs.CR2 |= (HRTIM_CR2_SWPE));
#define MG_REG_HRTIMER1_E_OUT_SWAP_BACK (HRTIM1->sCommonRegs.CR2 &= ~(HRTIM_CR2_SWPE));
#define MG_REG_HRTIMER1_F_OUT_SWAP      (HRTIM1->sCommonRegs.CR2 |= (HRTIM_CR2_SWPF));
#define MG_REG_HRTIMER1_F_OUT_SWAP_BACK (HRTIM1->sCommonRegs.CR2 &= ~(HRTIM_CR2_SWPF));
#endif
/***************************************
 * HrTimer ID config
 **************************************/

#define MG_HRTIM_A      HRTIM_TIMERINDEX_TIMER_A
#define MG_HRTIM_B      HRTIM_TIMERINDEX_TIMER_B
#define MG_HRTIM_C      HRTIM_TIMERINDEX_TIMER_C
#define MG_HRTIM_D      HRTIM_TIMERINDEX_TIMER_D
#define MG_HRTIM_E      HRTIM_TIMERINDEX_TIMER_E
#define MG_HRTIM_MST    HRTIM_TIMERINDEX_MASTER
#define MG_HRTIM_COMMON      HRTIM_TIMERINDEX_COMMON

#define MG_FAULT1       1
#define MG_FAULT2       2
#define MG_FAULT3       3
#define MG_FAULT4       4
#define MG_FAULT5       5
#define MG_FAULT6       6

/***************************************
   factors to convert ns to timer ticks, should be calculated on the fly
 **************************************/
#define  mg_f32TimerMstConvFact 1  //TODO
#define  mg_f32TimerAConvFact 1    //TODO
#define  mg_f32TimerBConvFact 1    //TODO
#define  mg_f32TimerCConvFact 1    //TODO
#define  mg_f32TimerDConvFact 1    //TODO
#define  mg_f32TimerEConvFact 1    //TODO
/******************************************************
 * Output Polarity
 * ****************************************************/
/*TIM A Output Polarity*/
#define MG_REG_HRTIMER1_TIMA_OUT1_POL_HIGH   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].OUTxR  &= ~(HRTIM_OUTR_POL1))
#define MG_REG_HRTIMER1_TIMA_OUT1_POL_LOW   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].OUTxR)  |= (HRTIM_OUTR_POL1))
#define MG_REG_HRTIMER1_TIMA_OUT2_POL_HIGH   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].OUTxR) &= ~(HRTIM_OUTR_POL2))
#define MG_REG_HRTIMER1_TIMA_OUT2_POL_LOW   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].OUTxR)  |= (HRTIM_OUTR_POL2))

/*TIM B Output Polarity*/
#define MG_REG_HRTIMER1_TIMB_OUT1_POL_HIGH   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].OUTxR  &= ~(HRTIM_OUTR_POL1))
#define MG_REG_HRTIMER1_TIMB_OUT1_POL_LOW   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].OUTxR)  |= (HRTIM_OUTR_POL1))
#define MG_REG_HRTIMER1_TIMB_OUT2_POL_HIGH   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].OUTxR) &= ~(HRTIM_OUTR_POL2))
#define MG_REG_HRTIMER1_TIMB_OUT2_POL_LOW   (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].OUTxR)  |= (HRTIM_OUTR_POL2))
/*TIM C Output Polarity*/
/*TIM D Output Polarity*/
/*TIM E Output Polarity*/



#ifdef __cplusplus
}
#endif
#endif  /* HRTIMER_CONF_H */


/*
 * End of file
 */

