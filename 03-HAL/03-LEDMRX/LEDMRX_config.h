/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LEDMRX              **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef LEDMRX_CONFIG_H_
#define LEDMRX_CONFIG_H_

/*Please write Pin Pair ex: PORT,PIN */
#define LEDMRX_ROW0_PIN         MGPIO_PORT_A,MGPIO_PIN_0
#define LEDMRX_ROW1_PIN         MGPIO_PORT_A,MGPIO_PIN_1     
#define LEDMRX_ROW2_PIN         MGPIO_PORT_A,MGPIO_PIN_2
#define LEDMRX_ROW3_PIN         MGPIO_PORT_A,MGPIO_PIN_3
#define LEDMRX_ROW4_PIN         MGPIO_PORT_A,MGPIO_PIN_4
#define LEDMRX_ROW5_PIN         MGPIO_PORT_A,MGPIO_PIN_5
#define LEDMRX_ROW6_PIN         MGPIO_PORT_A,MGPIO_PIN_6
#define LEDMRX_ROW7_PIN         MGPIO_PORT_A,MGPIO_PIN_7

/*Please write Pin Pair ex: PORT,PIN */
#define LEDMRX_COL0_PIN         MGPIO_PORT_B,MGPIO_PIN_0
#define LEDMRX_COL1_PIN         MGPIO_PORT_B,MGPIO_PIN_1     
#define LEDMRX_COL2_PIN         MGPIO_PORT_B,MGPIO_PIN_10
#define LEDMRX_COL3_PIN         MGPIO_PORT_B,MGPIO_PIN_11
#define LEDMRX_COL4_PIN         MGPIO_PORT_B,MGPIO_PIN_6
#define LEDMRX_COL5_PIN         MGPIO_PORT_B,MGPIO_PIN_7
#define LEDMRX_COL6_PIN         MGPIO_PORT_B,MGPIO_PIN_8
#define LEDMRX_COL7_PIN         MGPIO_PORT_B,MGPIO_PIN_9

#endif