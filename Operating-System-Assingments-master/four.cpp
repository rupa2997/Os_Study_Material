#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

class Process
{
public:
    string pName;
    int aTime;
    int bTime;
    int rTime;
    int cTime;
    int wTime;
    int tTime;

    Process() {}

    // Process(string pName, int aTime, int bTime)
    // {
    //     this->pName = pName;
    //     this->aTime = aTime;
    //     this->bTime = bTime;
    // }
};

bool arrTime(Process p1, Process p2)
{
    return (p1.aTime < p2.aTime);
}

int main()
{
    int num;
    cout << "Enter Number of Processes: ";
    cin >> num;
    Process ps[num];
    float avgwTime = 0;
    float avgtTime = 0;
    for (int i = 0; i < num; i++)
    {
        int at, bt;
        string p;
        cout << "Enter Process Name, Arrival Time and Burst Time: ";
        cin >> p >> at >> bt;
        ps[i].aTime = at;
        ps[i].bTime = bt;
        ps[i].pName = p;
    }
    //    cout << "Hello Ritesh!!" << endl;
    sort(ps, ps + num, arrTime);

    for (int i = 0; i < num; i++)
    {
        cout << ps[i].pName << "   "
             << ps[i].bTime << "   "
             << ps[i].aTime << endl;
    }

    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            ps[i].rTime = ps[i].aTime;
        }
        else
        {
            ps[i].rTime = ps[i - 1].cTime;
        }
        ps[i].cTime = ps[i].rTime + ps[i].bTime;
        ps[i].wTime = ps[i].rTime - ps[i].aTime;
        ps[i].tTime = ps[i].cTime - ps[i].aTime;

        avgwTime += ps[i].wTime;
        avgtTime += ps[i].tTime;
    }
    avgwTime /= float(num);
    avgtTime /= float(num);

    cout << "AVG Wait Time: " << fixed << setprecision(2) << avgwTime << endl;
    cout << "AVG Turnaround Time: " << fixed << setprecision(2) << avgtTime << endl;

    return 0;
}