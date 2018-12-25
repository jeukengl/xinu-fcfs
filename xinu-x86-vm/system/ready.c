/* ready.c - ready */

#include <xinu.h>

qid16    readylist;            /* index of ready list        */

/*------------------------------------------------------------------------
 *  ready  -  Make a process eligible for CPU service
 *------------------------------------------------------------------------
 */
status    ready(
                pid32        pid,        /* ID of process to make ready    */
                bool8        resch        /* reschedule afterward?    */
)
{
    register struct procent *prptr;
    
    if (isbadpid(pid)) {
        return(SYSERR);
    }
    
    /* Set process state to indicate ready and add to ready list */
    
    prptr = &proctab[pid];
    prptr->prstate = PR_READY;
    /* added to end of ready list */
    /* Lab4 modification */
    enqueue(pid, readylist);
    
    if (resch == RESCHED_YES) {
        resched();
    }
    return OK;
}
