/** *****************************************************************************
 * \file    adc_api.h
 * \brief   API for comP_api.h
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

#ifndef HRPWM_API_H
#define HRPWM_API_H
#ifdef __cplusplus
extern "C"  {
#endif

/*******************************************************************************
 * Included header
 ******************************************************************************/

#include "hrpwm_conf.h"
/*******************************************************************************
 * Interface Data Types
 ******************************************************************************/

typedef struct HRPWM_PFC_INTERFACE_T {
  float32 f32Per;
  float32 f32Duty;
  float32 f32DeadTime;
  boolean bPol;
  boolean bPfcEn;
  boolean bRectEn;
} HRPWM_PFC_INTERFACE;
/** *****************************************************************************
 * \brief         Init function
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRPWM_vInit(void);

/** *****************************************************************************
 * \brief         De-init function
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRPWM_vDeInit(void);

/** *****************************************************************************
 * \brief         Start the high resolution timers synchronized
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRPWM_vSyncStartHrTimer(void);

/** *****************************************************************************
 * \brief         HRTIMER NVIC configuration
 *
 * \param[in]     HrTimChId: can be 0 to 5. PrePriority: can be 1 to 7. SubPriority: can be 1 to 7
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRTIMER_vHrTimerIsrNvicCfg(uint8 u8HrTimChId, uint8 u8PrePriority, uint8 u8SubPriority);

/** *****************************************************************************
 * \brief         HRTIMER interface function
 *
 * \param[in]     HrTimChId: can be 0 to 5. PrePriority: can be 1 to 7. SubPriority: can be 1 to 7
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRPWM_vHrTimerSet(HRPWM_PFC_INTERFACE* sPfcPwmCfg);
/** *****************************************************************************
 * \brief         Reset master timer ISR flag
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */

inline void HRTIMER_vHrTimerMstCmp2IsrFlgResetCcRam(void)
{
  //MG_REG_HRTIMER1_MST_CMP2_IR_CLR;
}



inline void HRTIMER_vHrTimerMstRepIsrFlgResetCcRam(void)
{
 // MG_REG_HRTIMER1_MST_REP_IR_CLR;
}

/** *****************************************************************************
 * \brief         Read ISR flag
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
#if 0
inline uint8 HRTIMER_u8HrTimerMstCmp2ReadIsrFlgCcRam(void)
{
  return MG_REG_HRTIMER1_MST_CMP2_IR_RD;
}


inline uint8 HRTIMER_u8HrTimerMstRepReadIsrFlgCcRam(void)
{
  return MG_REG_HRTIMER1_MST_REP_IR_RD;
}
#endif

/** *****************************************************************************
 * \brief         Turn off high resolution timer PWM
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
/* CCRAM functions */

inline void HRPWM_vPfcHrpwmOff()
{
  MG_REG_PWM_A_OFF;
}

inline void HRPWM_vRectHrpwmOff()
{
  MG_REG_PWM_B_OFF;
}


/** *****************************************************************************
 * \brief         Turn on high resolution timer PWM
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
inline void HRPWM_vPfcHrpwmOn()
{
  MG_REG_PWM_A_OFF;
}

inline void HRPWM_vRectHrpwmOn()
{
  MG_REG_PWM_B_OFF;
}

/** *****************************************************************************
 * \brief         Set dead timer for complementary mode
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
/* Normal functions */
inline void HRPWM_vHrTimerASetDt(float32 f32nsDeadTimeF, float32 f32nsDeadTimeR)
{

}

inline void HRPWM_vHrTimerBSetDt(float32 f32nsDeadTimeF, float32 f32nsDeadTimeR)
{

}

/** *****************************************************************************
 * \brief         Clear fault
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */


inline void HRTIMER_vHrTimerClrFault1()
{
  MG_REG_HRTIMER1_FAULT1_CLR;
}

inline void HRTIMER_vHrTimerClrFault2()
{
  MG_REG_HRTIMER1_FAULT2_CLR;
}

inline void HRTIMER_vHrTimerClrFault3()
{
  MG_REG_HRTIMER1_FAULT3_CLR;
}

inline void HRTIMER_vHrTimerClrFault4()
{
  MG_REG_HRTIMER1_FAULT4_CLR;
}

inline void HRTIMER_vHrTimerClrFault5()
{
  MG_REG_HRTIMER1_FAULT5_CLR;
}


/** *****************************************************************************
 * \brief         Read fault events
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */

inline uint8 HRTIMER_u8HrTimerReadFlt1()
{
  return MG_REG_HRTIMER1_FAULT1;    /*lint !e587 ; Due to unknown definition in ST libraries */
}

inline uint8 HRTIMER_u8HrTimerReadFlt2()
{
  return MG_REG_HRTIMER1_FAULT2;    /*lint !e587 ; Due to unknown definition in ST libraries */
}

inline uint8 HRTIMER_u8HrTimerReadFlt3()
{
  return MG_REG_HRTIMER1_FAULT3;    /*lint !e587 ; Due to unknown definition in ST libraries */
}

inline uint8 HRTIMER_u8HrTimerReadFlt4()
{
  return MG_REG_HRTIMER1_FAULT4;    /*lint !e587 ; Due to unknown definition in ST libraries */
}

inline uint8 HRTIMER_u8HrTimerReadFlt5()
{
  return MG_REG_HRTIMER1_FAULT5;    /*lint !e587 ; Due to unknown definition in ST libraries */
}



/** *****************************************************************************
 * \brief         Change the register settings for polarity change
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */

void HRPWM_vHrpwmSetPosPolarityConf();

 void HRPWM_vHrpwmSetNegPolarityConf();

/** *****************************************************************************
 * \brief         Disable faults
 *
 * \param[in]      -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
#if 0
inline void HRTIMER_vHrTimerFltDis()
{
  /* Disable faults */
  //MG_REG_HRTIMER1_FLT1_DIS;
  //MG_REG_HRTIMER1_FLT2_DIS;
}
#endif
/** *****************************************************************************
 * \brief         Enable faults
 *
 * \param[in]      -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
#if 0
inline void HRTIMER_vHrTimerFltEn()
{
  /* Enable faults */
  MG_REG_HRTIMER1_FLT1_EN;
  MG_REG_HRTIMER1_FLT2_EN;
}
#endif


#ifdef __cplusplus
}
#endif
#endif  /* HRTIMER_API_H */


/*
 * End of file
 */
