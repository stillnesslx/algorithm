/**
  ******************************************************************************
  * @file    search.h
  * @author  RuiXiaoliang
  * @version V1.0.0
  * @date    20140912
  * @brief   search
  ******************************************************************************
  * @attention
  ******************************************************************************
**//* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SORT_H
#define __SORT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
//#include "stdint.h"

//#define DATA_TYPE u16
#define EN_PRINTF 1
typedef unsigned short int DATA_TYPE;

//extern unsigned int randint(unsigned int l, unsigned int u);
extern void swap(DATA_TYPE *a, DATA_TYPE *b);
extern void sort_insert(DATA_TYPE *buf, unsigned int len);
extern void sort_quick1(DATA_TYPE *buf, unsigned int low, unsigned int up);
extern void sort_quick3(DATA_TYPE *buf, unsigned int low, unsigned int up);
extern void sort_quick4(DATA_TYPE *buf, unsigned int low, unsigned int up);
#ifdef __cplusplus
}
#endif

#endif /*__SORT_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT  *****END OF FILE****/
