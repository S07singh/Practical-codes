#include <iostream>
using namespace std;
void waitingtime(int processes[], int n, int wt[], int bt[], int quantum)
{
int rem_bt[n];
for (int i = 0; i < n; i++)
rem_bt[i] = bt[i];
int t = 0; // Current time
while (true) {
bool done = true;
for (int i = 0; i < n; i++)
{
if (rem_bt[i] > 0)
{
done = false;
if (rem_bt[i] > quantum)
{
t += quantum;
rem_bt[i] -= quantum;
}
else
{
t = t + rem_bt[i];
wt[i] = t - bt[i];
rem_bt[i] = 0;
}
}
}
if (done)
break;
}
}
void turnaroundtime(int processes[], int n, int bt[], int wt[], int tat[])
{
for (int i = 0; i < n; i++)
tat[i] = bt[i] + wt[i];
}
void averagetime(int processes[], int n, int bt[], int quantum)
{
int wt[n], tat[n], totalwt = 0, totaltat = 0;
waitingtime(processes, n, wt, bt, quantum);
turnaroundtime(processes, n, bt, wt, tat);
cout << "Processes\tBurst Time\tWaiting Time\tTurn Around Time\n";
for (int i = 0; i < n; i++) {
totalwt += wt[i];
totaltat += tat[i];
cout << " " << i + 1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
}
cout << "Average Waiting Time = " << (float)totalwt / (float)n << endl;
cout << "Average Turn Around Time = " << (float)totaltat / (float)n << endl;
}
int main()
{
int processes[] = {1, 2, 3};
int n = sizeof(processes) / sizeof(processes[0]);
int bursttime[] = {10, 5, 8};
int quantum = 2;
averagetime(processes, n, bursttime, quantum);
return 0;
}
