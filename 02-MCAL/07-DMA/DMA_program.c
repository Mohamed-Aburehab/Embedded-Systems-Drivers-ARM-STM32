/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DMA                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

/* An array of pointers to functions. */
static void(*CallBackFuncArr[7])(void) = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};


void MDMA_voidChannelInit(DMA_channel_configuration *DMA_configStruct){
    u32 DMA_CCRxValue = 0;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->TransferCompleteInterruptEnable << 1;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->HalfTransferInterruptEnable << 2;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->TransferErrorInterruptEnable << 3;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->DataTransferDirection << 4;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->CircularMode << 5;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->PeripheralIncrementMode << 6;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->MemoryIncrementMode << 7;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->PeripheralSize << 8;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->MemorySize << 10;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->ChannelPriority << 12;
    DMA_CCRxValue = DMA_CCRxValue | DMA_configStruct->MemoryToMemoryMode << 14;
    DMA->Channel[(DMA_configStruct->ChannelId -1)].CCR = DMA_CCRxValue;

}


void MDMA_voidChannelStart(u8 Copy_u8ChannelID,u32 *Copy_Pu32SourceAddress, u32 *Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength){
    /* Clearing the enable bit of the channel. */
	CLR_BIT(DMA->Channel[(Copy_u8ChannelID -1)].CCR,0);

    /* Assigning the source address to the channel's source address register. */
	DMA->Channel[(Copy_u8ChannelID -1)].CPAR=Copy_Pu32SourceAddress;

    /* Assigning the destination address to the channel's destination address register. */
	DMA->Channel[(Copy_u8ChannelID -1)].CMAR=Copy_Pu32DestinationAddress;

    /* Assigning the block length to the channel's block length register. */
	DMA->Channel[(Copy_u8ChannelID -1)].CNDTR=Copy_u16BlockLength;

    /* Setting the enable bit of the channel. */
	SET_BIT(DMA->Channel[(Copy_u8ChannelID -1)].CCR,0);
}

void MDMA_voidSetCallBack(u8 Copy_u8ChannelId, void(*Copy_pvoidFunc)(void)){
    CallBackFuncArr[Copy_u8ChannelId-1] = Copy_pvoidFunc;
}

void DMA1_Channel1_IRQHandler(void)
{
    if((CallBackFuncArr[0]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 0. */
        CallBackFuncArr[0]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<0;         /* Clear Global Interrupt flag of channel1 */
    DMA->IFCR=1<<1;         /* Clear transfer complete Interrupt flag of channel1 */
}
void DMA1_Channel2_IRQHandler(void)
{
    if((CallBackFuncArr[1]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 1. */
        CallBackFuncArr[1]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<4;         /* Clear Global Interrupt flag of channel2 */
    DMA->IFCR=1<<5;         /* Clear transfer complete Interrupt flag of channel2 */
}
void DMA1_Channel3_IRQHandler(void)
{
    if((CallBackFuncArr[2]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 2. */
        CallBackFuncArr[2]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<8;         /* Clear Global Interrupt flag of channel3 */
    DMA->IFCR=1<<9;         /* Clear transfer complete Interrupt flag of channel3 */
}
void DMA1_Channel4_IRQHandler(void)
{
    if((CallBackFuncArr[3]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 3. */
        CallBackFuncArr[3]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<12;                /* Clear Global Interrupt flag of channel4 */
    DMA->IFCR=1<<13;                /* Clear transfer complete Interrupt flag of channel4 */
}
void DMA1_Channel5_IRQHandler(void)
{
    if((CallBackFuncArr[4]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 4. */
        CallBackFuncArr[4]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<16;                /* Clear Global Interrupt flag of channel5 */
    DMA->IFCR=1<<17;                /* Clear transfer complete Interrupt flag of channel5 */
}
void DMA1_Channel6_IRQHandler(void)
{
    if((CallBackFuncArr[5]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 5. */
        CallBackFuncArr[5]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<20;                /* Clear Global Interrupt flag of channel6 */
    DMA->IFCR=1<<21;                /* Clear transfer complete Interrupt flag of channel6 */
}
void DMA1_Channel7_IRQHandler(void)
{
    if((CallBackFuncArr[6]!=NULL) )
    {
        /* Calling the call back function that is stored in the array at index 6. */
        CallBackFuncArr[6]();
    }
    /*Clear Interrupt flag*/
    DMA->IFCR=1<<24;                /* Clear Global Interrupt flag of channel7 */
    DMA->IFCR=1<<25;                /* Clear transfer complete Interrupt flag of channel7 */
}