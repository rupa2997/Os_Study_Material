#include <iostream>
#include <sched.h>
main()
{
    struct sched_param param;
    int pid_num = 0;

    param.sched_priority = 1;
    sched_setscheduler(pid_num, SCHED_FIFO, &param);
    while (1)
        ;
}