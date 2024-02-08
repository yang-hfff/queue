/**
  * @file     	ringQueue.c
  * @author   	YangHaifeng
  * @email   	yang_hfff@qq.com
  * @version	V0.0
  * @license  	MIT  
  * @detail		please follow the license!!!
  * @attention
  *  this file is aim to do something with ringQueue,it just fou usart and 
  * other communication part of MCU such as IIC,SPI,CAN,MODBUS etc.
  * in some MCU such as STM32,MSP432,MSP430,ESP32,ch32,gd32 etc.									
  * (foBUr speed up and simpify，program delete some function which not need)  																	
  * @htmlonly 
  * <span style="font-weight: bold">History</span> 
  * @endhtmlonly 
  * Version|Auther|Describe
  * ------|----|-------- 
  * V0.0|YangHaifeng|Create File
  * <h2><center>&copy;COPYRIGHT YangHaifeng All Rights Reserved.</center></h2>
  */ 

#include "queue.h"

#if !USE_INLINE_SPEED_UP

/**
 * @brief queue initialize
 * @param obj queue pointer
 * @param size data size
 * @param base data buffer address
 * @retval None
 * @note must alloc memory for queue pointer
*/
void Q_init(Q *obj,uint8_t *base,uint32_t size)
{
    obj->front = 0;
    obj->rear = 0;
    obj->size = size;
    obj->base = base;
}

/**
 * @brief judge queue is or not empty
 * @param obj queue pointer
 * @retval empty return 1,not empty return 0
*/
uint8_t Q_isEmpty(Q *obj)
{
    if(obj->front == obj->rear)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

/**
 * @brief judge queue is or not full
 * @param obj queue pointer
 * @retval full return 1,not full return 0
*/
uint8_t Q_isFull(Q *obj)
{
    if(obj->front == (obj->rear + 1) % obj->size)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

/**
 * @brief put data to queue
 * @param obj queue pointer
 * @param item  data ittem
 * @retval None
 * @note must do full check before enqueue(forbid up overflow) 
*/
void Q_enQueue(Q *obj,uint8_t item)
{
    obj->rear = (obj->rear + 1) % obj->size;
    obj->base[obj->rear] = item;
}

/**
 * @brief get data from queue and remove data
 * @param obj queue pointer
 * @retval return data
 * @note must do empty check before dequeue(forbid down overflow)
*/
uint8_t Q_deQueue(Q *obj)
{
    obj->front = (obj->front + 1) % obj->size;
    return obj->base[obj->front];
}

#endif //#if !USE_INLINE_SPEED_UP

