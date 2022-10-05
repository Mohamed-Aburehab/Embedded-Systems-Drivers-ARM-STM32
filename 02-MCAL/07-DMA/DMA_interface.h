/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DMA                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

/* DMA MACROS */
#define CHANNEL_PRIORITY_LOW            0
#define CHANNEL_PRIORITY_MEDIUM         1
#define CHANNEL_PRIORITY_HIGH           2
#define CHANNEL_PRIORITY_VERY_HIGH      3


#define DMA_OPTION_DISABLE              0
#define DMA_OPTION_ENABLE               1

#define DMA_DATA_SIZE_8_BITS            0
#define DMA_DATA_SIZE_16_BITS           1
#define DMA_DATA_SIZE_32_BITS           2

typedef struct {
    /* ChannelId Options : 1 -> 7 */
    u8 ChannelId;
    /* MemoryToMemoryMode Options : ((DMA_OPTION_ENABLE) , DMA_OPTION_DISABLE) */
    u8 MemoryToMemoryMode;
    /* MemoryToMemoryMode Options : ( CHANNEL_PRIORITY_VERY_HIGH, 
                                      CHANNEL_PRIORITY_HIGH, 
                                      CHANNEL_PRIORITY_MEDIUM,
                                      CHANNEL_PRIORITY_LOW) 
    */
    u8 ChannelPriority;
    /* MemorySize Options : ( DMA_DATA_SIZE_8_BITS
                              DMA_DATA_SIZE_16_BITS
                              DMA_DATA_SIZE_32_BITS) 
    */
    u8 MemorySize;
    /* PeripheralSize Options : ( DMA_DATA_SIZE_8_BITS
                              DMA_DATA_SIZE_16_BITS
                              DMA_DATA_SIZE_32_BITS) 
    */
    u8 PeripheralSize;
    /* MemoryIncrementMode Options : ((DMA_OPTION_ENABLE) , DMA_OPTION_DISABLE) */
    u8 MemoryIncrementMode;
    /* PeripheralIncrementMode Options : ((DMA_OPTION_ENABLE) , DMA_OPTION_DISABLE) */
    u8 PeripheralIncrementMode;
    /* CircularMode Options : ((DMA_OPTION_ENABLE) , DMA_OPTION_DISABLE) */
    u8 CircularMode;
    /* DataTransferDirection Options : ((DMA_OPTION_ENABLE) , DMA_OPTION_DISABLE) */
    u8 DataTransferDirection;
    /* TransferErrorInterruptEnable Options : (DMA_OPTION_ENABLE , (DMA_OPTION_DISABLE)) */
    u8 TransferErrorInterruptEnable;
    /* HalfTransferInterruptEnable Options : (DMA_OPTION_ENABLE , (DMA_OPTION_DISABLE)) */
    u8 HalfTransferInterruptEnable;
    /* TransferCompleteInterruptEnable Options : ((DMA_OPTION_ENABLE) , DMA_OPTION_DISABLE) */
    u8 TransferCompleteInterruptEnable;

} DMA_channel_configuration;



void MDMA_voidChannelInit(DMA_channel_configuration *DMA_configStruct);

void MDMA_voidChannelStart(u8 Copy_u8ChannelID,u32 *Copy_Pu32SourceAddress, u32 *Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength);

void MDMA_voidSetCallBack(u8 Copy_u8ChannelId, void(*Copy_pvoidFunc)(void));

#endif