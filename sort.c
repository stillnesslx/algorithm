/**
  ******************************************************************************
  * @file    sort.c
  * @author  RuiXiaoliang
  * @version V1.0.0
  * @date    20141217/20141224
  * @brief   sort algorithm
  ******************************************************************************
  * @attention
  ******************************************************************************
**/
#include "sort.h"
#include "stdio.h"
#include <stdlib.h>
//#include "time.h"

unsigned int randint(unsigned int l, unsigned int u)
{
    return l + (RAND_MAX * rand() + rand()) % (u-l);
}

void swap(DATA_TYPE *a, DATA_TYPE *b)
{
    DATA_TYPE tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_quick4(DATA_TYPE *buf, unsigned int low, unsigned int up)
{
    #if(1 == EN_PRINTF)
    unsigned int k;
    #endif
    unsigned int i,j;
    DATA_TYPE t;
    if(low+1 >= up)
    {
        return;
    }
    //srand(time(NULL));
    swap(&buf[low],&buf[randint(low,up)]);
    t = buf[low];
    i = low + 1;
    j = up - 1;
    while(1)
    {
        while(i < up && buf[i] < t){i++;}
        while(buf[j] > t){j--;}
        if(i > j)break;
        swap(&buf[i],&buf[j]);
    }
    swap(&buf[low],&buf[j]);
    #if(1 == EN_PRINTF)
    for(k=low;k<up;k++)
    {
        printf("%x ",buf[k]);
    }
    printf("\n");
    printf("low:%x j:%x up:%x\n",low,j,up);
    #endif

    sort_quick3(buf,low,j);
    sort_quick3(buf,j+1,up);
}

void sort_quick3(DATA_TYPE *buf, unsigned int low, unsigned int up)
{
    #if(1 == EN_PRINTF)
    unsigned int k;
    #endif
    unsigned int i,j;
    DATA_TYPE t;
    if(low+1 >= up)
    {
        return;
    }
    t = buf[low];
    i = low + 1;
    j = up - 1;
    while(1)
    {
        while(i < up && buf[i] < t){i++;}
        while(buf[j] > t){j--;}
        if(i > j)break;
        swap(&buf[i],&buf[j]);
    }
    swap(&buf[low],&buf[j]);
    #if(1 == EN_PRINTF)
    for(k=low;k<up;k++)
    {
        printf("%x ",buf[k]);
    }
    printf("\n");
    printf("low:%x mid:%x up:%x\n",low,j,up);
    #endif

    sort_quick3(buf,low,j);
    sort_quick3(buf,j+1,up);
}

void sort_quick1(DATA_TYPE *buf, unsigned int low, unsigned int up)
{
    #if(1 == EN_PRINTF)
    unsigned int j;
    #endif
    unsigned int mid,i;
    if(low+1 >= up)
    {
        return;
    }
    mid = low;
    for(i=low+1;i<up;i++)
    {
        if(buf[i] < buf[low])
        {
            swap(&buf[++mid],&buf[i]);
        }
    }
    swap(&buf[low],&buf[mid]);

    #if(1 == EN_PRINTF)
    for(j=low;j<up;j++)
    {
        printf("%x ",buf[j]);
    }
    printf("\n");
    printf("low:%x mid:%x up:%x\n",low,mid,up);
    #endif
    sort_quick1(buf,low,mid);
    sort_quick1(buf,mid+1,up);
}
void sort_insert(DATA_TYPE *buf, unsigned int len)
{
    #if(1 == EN_PRINTF)
    unsigned int k;
    #endif
    unsigned int i,j;
    DATA_TYPE t;
    for(i=1;i<len;i++)
    {
        t = buf[i];
        for(j=i;j>0 && buf[j-1]>t;j--)
        {
            buf[j] = buf[j-1];
        }
        buf[j] = t;
    #if(1 == EN_PRINTF)
    for(k=0;k<len;k++)
    {
        printf("%x ",buf[k]);
    }
    printf("\n");
    #endif
    }
}


//end of file


