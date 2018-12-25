//
//  runafterwait.c
//  
//
//  Created by Liz Jeukeng on 11/7/18.
//

#include <stdio.h>
#include <xinu.h>
#include <stdlib.h>

void runafterwait(void)
{
    kprintf("running PID:%d\n", getpid());
    while(1){
        delay(10000)
    }
}

