#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

using namespace std;
int main()
{
    pid_t pid;
    cout << "Before fork!!!!!" << endl;
    pid = fork();
    if (pid == 0)
    {
        // cout << pid << endl;
        cout << "This is child process. Process ID: " << getpid() << "  "
             << "Parent ID: " << getppid() << "  "
             << "Scheduling Policy Status: "
             << sched_getscheduler(pid) << endl;

        // execl("/bin/date", "date", NULL);
        cout << endl
             << "-----------------------------" << endl;
        exit(0);
    }
    else if (pid > 0)
    {
        //  cout << pid << endl;
        cout << "this is parent process:" << getpid() << "  "
             << "Parent ID: " << getppid() << "  "
             << "Scheduling Policy Status: "
             << sched_getscheduler(pid) << endl;
        // execl("/bin/date", "date", NULL);
        exit(0);
    }
    else
    {
        cout << "process is not created" << endl;
    }
    exit(0);
    return 0;
}
