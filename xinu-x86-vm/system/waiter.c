//
//  waiter.c
//  
//
//  Created by Liz Jeukeng on 11/7/18.
//

#include <xinu.h>

void waiter(void)
{
    wait(globalsemaphore);
    n++;
    }
    
}
