Second commit
PID fixed XX
** *****************************************************************************
 * \file    adc_api.h
 * \brief   implementation of comp.c
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
 * Copyright (c) 2023 weidmueller Intesrface (Germany) GmbH.
 * All rights reserved.
 ***************************************************************************** */

/*******************************************************************************
 * Included header
 ******************************************************************************/

#include "stm32f3xx_hal.h"


/* Module header */
#include "hrpwm_api.h"
#include "hrpwm_scb.h"
#include "hrpwm_conf.h"

/*******************************************************************************
 * Local data types (private typedefs / structs / enums)
 ******************************************************************************/

extern HRTIM_HandleTypeDef hhrtim1;

/*******************************************************************************
 * Local data (private to module)
 ******************************************************************************/
float32 mg_f32HrtimerNs2CntsvFact;


/*******************************************************************************
 * Local function prototypes (private to module)
 ******************************************************************************/



/*******************************************************************************
 * Global functions (public to other modules)
 ******************************************************************************/

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
void HRPWM_vInit(void)
{
  MX_HRTIM1_Init();

  MG_REG_PWM_A_OFF;
  MG_REG_PWM_B_OFF;
  /*Updare preload registers*/ //TODO
  HRPWM_vSyncStartHrTimer();

  mg_f32HrtimerNs2CntsvFact = MCAL_F32_HRTIM_CLK_GHZ;
}

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
void HRPWM_vDeInit(void)
{
  /* Disable drive */
  MG_REG_PWM_A_OFF;
  MG_REG_PWM_B_OFF;
  MG_REG_PWM_C_OFF;
  MG_REG_PWM_D_OFF;
  MG_REG_PWM_E_OFF;
}


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
void HRPWM_vSyncStartHrTimer(void)
{
  /* Start and syncronize CPU timers */
  HAL_HRTIM_WaveformCounterStart(&hhrtim1, HRTIM_TIMERID_MASTER | HRTIM_TIMERID_TIMER_A | HRTIM_TIMERID_TIMER_B  );
}

/** *****************************************************************************
 * \brief         Set high resolution timer period
 *
 * \param[in]     u8TimerId: 0 - 5; HrTimerPeriod: period in ns
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRTIMER_vHrTimerSetPeriod(uint8 u8TimerId, float32 f32nsHrTimerPeriod)
{
  switch (u8TimerId)
  {
  case MG_HRTIM_MST:
  {
    /* HRTIMER MASTER */
    MG_REG_HRTIMER1_MST_PERIOD = (uint16)(mg_f32TimerMstConvFact * f32nsHrTimerPeriod);
    break;
  }
  case MG_HRTIM_A:
  {
    /* HRTIMER A */
    MG_REG_HRTIMER1_A_PERIOD = (uint16)(mg_f32TimerAConvFact * f32nsHrTimerPeriod);
    break;
  }
  case MG_HRTIM_B:
  {
    /* HRTIMER B */
    MG_REG_HRTIMER1_B_PERIOD = (uint16)(mg_f32TimerBConvFact * f32nsHrTimerPeriod);
    break;
  }
  case MG_HRTIM_C:
  {
    /* HRTIMER C */
    MG_REG_HRTIMER1_C_PERIOD = (uint16)(mg_f32TimerCConvFact * f32nsHrTimerPeriod);
    break;
  }
  case MG_HRTIM_D:
  {
    /* HRTIMER D */
    MG_REG_HRTIMER1_D_PERIOD = (uint16)(mg_f32TimerDConvFact * f32nsHrTimerPeriod);
    break;
  }
  case MG_HRTIM_E:
  {
    /* HRTIMER E */
    MG_REG_HRTIMER1_E_PERIOD = (uint16)(mg_f32TimerEConvFact * f32nsHrTimerPeriod);
    break;
  }
  default:
  {
    break;
  }
  }
}

/** *****************************************************************************
 * \brief         Enable PWM drive
 *
 * \param[in]     u8TimerId: 0 - 5 (MASTER TIMER - TIMER E); Status: Enable or disable
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void HRTIMER_vHrTimerDrvEnable(uint8 u8TimerId, uint8 u8Status)
{
  switch (u8TimerId)
  {
  /* HRTIMER A */
  case MG_HRTIM_A:
  {
    /* Enable drive */
    if (u8Status == SET)
    {
#if (FALSE != DEBUG_SECTION_OCP_LATCH)
      if ((FALSE == MG_REG_HRTIMER1_FAULT1) && (FALSE == MG_REG_HRTIMER1_FAULT2))
      {
        MG_REG_PWM_A_ON;
      }
#else
      MG_REG_PWM_A_ON;
#endif
    }
    /* Disable drive */
    else
    {
      MG_REG_PWM_A_OFF;
    }
    break;
  }
  /* HRTIMER B */
  case MG_HRTIM_B:
  {
    /* Enable drive */
    if (u8Status == SET)
    {
      MG_REG_PWM_B_ON;
    }
    /* Disable drive */
    else
    {
      MG_REG_PWM_B_OFF;
    }
    break;
  }
  /* HRTIMER C */
  case MG_HRTIM_C:
  {
    /* Enable drive */
    if (u8Status == SET)
    {
      MG_REG_PWM_C_ON;
    }
    /* Disable drive */
    else
    {
      MG_REG_PWM_C_OFF;
    }
    break;
  }
  /* HRTIMER D */
  case MG_HRTIM_D:
  {
    /* Enable drive */
    if (u8Status == SET)
    {
      MG_REG_PWM_D_ON;
    }
    /* Disable drive */
    else
    {
      MG_REG_PWM_D_OFF;
    }
    break;
  }
  /* HRTIMER E */
  case MG_HRTIM_E:
  {
    /* Enable drive */
    if (u8Status == SET)
    {
      MG_REG_PWM_E_ON;
    }
    /* Disable drive */
    else
    {
      MG_REG_PWM_E_OFF;
    }
    break;
  }
  default:
  {
    break;
  }
  }
}


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
void HRPWM_vHrTimerSet(HRPWM_PFC_INTERFACE* sPfcPwmCfg)
{
  uint16 u16Per= (uint16) (sPfcPwmCfg->f32Per * mg_f32HrtimerNs2CntsvFact) ;
  uint16 u16DT =  (uint16) (sPfcPwmCfg->f32DeadTime * mg_f32HrtimerNs2CntsvFact) ;
  uint16 u16Duty  = (uint16) (sPfcPwmCfg->f32Duty * sPfcPwmCfg->f32Per * mg_f32HrtimerNs2CntsvFact);

  /*Master*/
  MG_REG_HRTIMER1_MST_PERIOD= u16Per; /*period*/
  MG_REG_HRTIMER1_MST_CMP1 = (u16Duty>>1) + MG_U16_HRPWM_ADC_SAMPLE_ADJ;   /*ADc trigger*/

  /*Timer A*/
  MG_REG_HRTIMER1_A_CMP1 = (uint16)u16DT;
  MG_REG_HRTIMER1_A_CMP2 = (uint16)u16Duty;
  MG_REG_HRTIMER1_A_CMP3 = (uint16)(u16Duty+u16DT);
  MG_REG_HRTIMER1_A_PERIOD = u16Per;
  if( FALSE != sPfcPwmCfg->bPfcEn)
  {
    MG_REG_PWM_A_ON;
  }
  else
  {
    MG_REG_PWM_A_OFF;
  }
  if( FALSE != sPfcPwmCfg->bRectEn)
  {
    MG_REG_PWM_B_ON;
  }
  else
  {
    MG_REG_PWM_B_OFF;
  }
}


void HRPWM_vHrpwmSetPosPolarityConf(void)
{
  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].SETx1R = HRTIM_OUTPUTSET_TIMCMP1;
  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].RSTx1R = HRTIM_OUTPUTRESET_TIMCMP2|HRTIM_OUTPUTRESET_EEV_1;

  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].SETx2R = HRTIM_OUTPUTSET_TIMCMP3;
  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].RSTx2R = HRTIM_OUTPUTRESET_TIMPER|HRTIM_OUTPUTRESET_EEV_2;

}


void HRPWM_vHrpwmSetNegPolarityConf(void)
{

  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].SETx2R = HRTIM_OUTPUTSET_TIMCMP1;
  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].RSTx2R = HRTIM_OUTPUTRESET_TIMCMP2|HRTIM_OUTPUTRESET_EEV_2;

  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].SETx1R = HRTIM_OUTPUTSET_TIMCMP3;
  hhrtim1.Instance->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].RSTx1R = HRTIM_OUTPUTRESET_TIMPER|HRTIM_OUTPUTRESET_EEV_1;
}


/*******************************************************************************
 * Local functions (privat for module)
 ******************************************************************************/




/*
 * End of file
 */
