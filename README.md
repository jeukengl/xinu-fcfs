# xinu-fcfs
Changed Xinu's default scheduling algorithm
Instead of ordering processes based on priority, I changed the Xinu Operating System such that it can order processes solely based on when it was created. Therefore, changing it from priority based round robin to first come first serve. 

First, in order to print the processes based on priority, I put the correct code into /system/main.c.


Next, in order to print the processes in order of arrival, I first modified the resched.c file as seen in the system directory. Instead of using the insert() function that inserts processes in the queue based on priority, I used enqueue instead. I also removed the if statement that checks if the priority of the current process is higher than the first key in the ready list. Lastly, I removed the preempt to reset the time slice for the process. 

The next file I changed was /system/ready.c. I changed it so that the new process was put into the readylist at the end and not based on priority. 


The next file I changed was /system/resume.c to not record or return the priority. I just omitted two lines of code in this file and added none. 

The last file I changed was suspend.c. I removed the prio return statement and declaration.  
