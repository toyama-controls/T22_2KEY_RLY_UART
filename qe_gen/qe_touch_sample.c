/***********************************************************************
*
* FILE : qe_sample_main.c
* DATE : 2022-03-09
* DESCRIPTION : Main Program for RX
*
* NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "qe_touch_config.h"
#if ((TOUCH_CFG_UART_MONITOR_SUPPORT == 1) || (TOUCH_CFG_UART_TUNING_SUPPORT == 1))
#include "r_sci_rx_pinset.h"
#endif
#define TOUCH_SCAN_INTERVAL_EXAMPLE (2)    /* milliseconds */
extern uint8_t Rx_Buffer[8];
void R_CTSU_PinSetInit(void);
void qe_touch_main(void);



#if ((TOUCH_CFG_UART_MONITOR_SUPPORT == 1) || (TOUCH_CFG_UART_TUNING_SUPPORT == 1))
#if (TOUCH_CFG_UART_NUMBER == 0)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI0
#elif (TOUCH_CFG_UART_NUMBER == 1)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI1
#elif (TOUCH_CFG_UART_NUMBER == 2)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI2
#elif (TOUCH_CFG_UART_NUMBER == 3)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI3
#elif (TOUCH_CFG_UART_NUMBER == 4)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI4
#elif (TOUCH_CFG_UART_NUMBER == 5)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI5
#elif (TOUCH_CFG_UART_NUMBER == 6)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI6
#elif (TOUCH_CFG_UART_NUMBER == 7)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI7
#elif (TOUCH_CFG_UART_NUMBER == 8)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI8
#elif (TOUCH_CFG_UART_NUMBER == 9)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI9
#elif (TOUCH_CFG_UART_NUMBER == 10)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI10
#elif (TOUCH_CFG_UART_NUMBER == 11)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI11
#elif (TOUCH_CFG_UART_NUMBER == 12)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI12
#endif
#endif

uint64_t button_status;
#if (TOUCH_CFG_NUM_SLIDERS != 0)
uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif






void qe_touch_main(void)
{
    fsp_err_t err;

    /* Initialize pins (function created by Smart Configurator) */
    R_CTSU_PinSetInit();

#if ((TOUCH_CFG_UART_MONITOR_SUPPORT == 1) || (TOUCH_CFG_UART_TUNING_SUPPORT == 1))
    /* Setup pins for SCI (function created by Smart Configurator) */
    QE_SCI_PIN_SET();
#endif




    /* Open Touch middleware */
    err = RM_TOUCH_Open (g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
    if (FSP_SUCCESS != err)
    {
        while (true) {}
    }
    




    /* Main loop */
    while (true)
    {


        /* for [CONFIG01] configuration */
        err = RM_TOUCH_ScanStart (g_qe_touch_instance_config01.p_ctrl);
        if (FSP_SUCCESS != err)
        {
            while (true) {}
        }
        while (0 == g_qe_touch_flag) {}
        g_qe_touch_flag = 0;

        err = RM_TOUCH_DataGet (g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
        if (FSP_SUCCESS == err)
        {

        	handle_receive_data();

        	LED_FUNCTION(button_status);
            /* TODO: Add your own code here. */
        }



        /* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
        R_BSP_SoftwareDelay (TOUCH_SCAN_INTERVAL_EXAMPLE, BSP_DELAY_MILLISECS);
    }
}


