/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* https://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : qe_touch_config.h
* Description  : This file includes definitions.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History      : MM/DD/YYYY Version Description
*              : 04/24/2021 1.00    First Release
*              : 05/27/2021 1.10    Adding API Wrapper Supporting
*              : 07/15/2021 1.20    Adding Diagnosis Supporting
*              : 03/01/2022 1.30    Adding Auto Sensing Supporting
***********************************************************************************************************************/

#ifndef QE_TOUCH_CONFIG_H
#define QE_TOUCH_CONFIG_H

#include "r_ctsu_qe.h"
#include "rm_touch_qe.h"
#include "qe_touch_define.h"


/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/
extern const ctsu_instance_t g_qe_ctsu_instance_config01;
extern const touch_instance_t g_qe_touch_instance_config01;




extern volatile uint8_t      g_qe_touch_flag;
extern volatile ctsu_event_t g_qe_ctsu_event;

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
extern void qe_touch_callback(touch_callback_args_t * p_args);


#endif /* QE_TOUCH_CONFIG_H */