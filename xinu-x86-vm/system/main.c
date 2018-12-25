/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/*declared the different process functions */
void process2();
void process3();
void process4();


int main(void)
{
    /*created each process with the require PID*/
    resume(create(process2,8192, 5, "process 2", 0));
    resume(create(process3,8192, 10, "process 3", 0));
    resume(create(process4,8192, 20, "process 4", 0));
}
/*process 2 function*/
void process2(){
    printf("Process 2's process ID:%d\n", getpid()); //getpid() retrieves the process id of the process
    sleep(15); //sleeps for 15 seconds
    while(1){
        printf("Process 2 is running.");
    }
}
/*process 3 function*/

void process3(){
    printf("Process 3's process ID:%d\n",getpid());//getpid() retrieves the process id of the process
    sleep(15);//sleeps for 15 seconds
    while(1){
        printf("Process 3 is running.");
    }
    
}
/*process 4 function*/

void process4(){
    printf("Process 4's process ID:%d\n",getpid());//getpid() retrieves the process id of the process
    sleep(15);//sleeps for 15 seconds
    while(1){
        //this while statement is always true so the process will continue running
        printf("Process 4 is running.");
    }
}

