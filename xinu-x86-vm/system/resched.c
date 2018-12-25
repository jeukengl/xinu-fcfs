void  resched(void)        /* assumes interrupts are disabled    */
{
    struct procent *ptold;    /* ptr to table entry for old process    */
    struct procent *ptnew;    /* ptr to table entry for new process    */
    
    /* If rescheduling is deferred, record attempt and return */
    
    if (Defer.ndefers > 0) {
        Defer.attempt = TRUE;
        return;
    }
    
    /* Point to process table entry for the current (old) process */
    
    ptold = &proctab[currpid];
    
    if (ptold->prstate == PR_CURR) {  /* process remains running */
        /* Lab4 modification */
        
        /* Old process will no longer remain current */
        
        ptold->prstate = PR_READY;
        /* Adds process to the end of readylist */
        
        /* Lab4 modification */
        enqueue(currpid, readylist);
    }
    
    /* Force context switch to the next ready process */
    
    currpid = dequeue(readylist);
    ptnew = &proctab[currpid];
    ptnew->prstate = PR_CURR;
    /* Lab4 modification */
    ctxsw(&ptold->prstkptr, &ptnew->prstkptr);
    
    /* Old process returns here when resumed */
    
    return;
}
