#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sort.h"

int main()
{
    uint16_t len = 0,i;
    char cmd;
    DATA_TYPE buf[100];
    printf("sort program!\n");
    printf("select sort program!\n");
    printf("i:insert sort\n1:quick1 sort\n3:quick3 sort\n4:quick4 sort\n");
    //while(getchar() != '\n');
    while(1 != scanf("%c",&cmd));

    while(1)
    {
        printf("input buf len!\n");
        scanf("%x",(unsigned int *)&len);
        printf("input %d hex numbers!\n",len);
        for(i=0;i<len;i++)
        {
            scanf("%x",(unsigned int *)&buf[i]);
        }
        printf("\n");
        switch(cmd)
        {
            case 'i':sort_insert(buf,len);break;
            case '1':sort_quick1(buf,0,len);break;
            case '3':sort_quick3(buf,0,len);break;
            case '4':sort_quick4(buf,0,len);break;
            default:break;
        }

        printf("sort result is:\n");
        for(i=0;i<len;i++)
        {
            printf("%x ",buf[i]);
        }
        printf("\n");
        while(getchar() != '\n');
    }
    printf("Hello world!\n");
    return 0;
}
