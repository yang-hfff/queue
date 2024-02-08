#include <stdio.h>
#include <stdint.h>
#include "queue.h"



int main()
{
    Q aqueue;
    uint8_t arr[256];
    int t;

    Q_init(&aqueue,arr,6);

    /*入队之前一定要判断满*/
    while(!Q_isFull(&aqueue))
    {
        printf("input:");
        scanf("%d",&t);
        Q_enQueue(&aqueue,(uint8_t)t);
    }

    /*出队之前要判断空*/
    while(!Q_isEmpty(&aqueue))
    {
        printf("%d\n",Q_deQueue(&aqueue));
    }

    return 0;
}