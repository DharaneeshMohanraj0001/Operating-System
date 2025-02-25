#include <stdio.h>

#define MAX_PROCESSES 5


// Structure for process
struct Process
{
    int id;
    int burstTime;
};

// Function to find the waiting time for all processes
void findWaitingTime(struct Process processes[], int n, int waitingTime[])
{
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
    }
}

// Function to find the turn around time for all processes
void findTurnAroundTime(struct Process processes[], int n, int waitingTime[], int turnAroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

// Function to calculate average waiting and turn around time
void findAverageTime(struct Process processes[], int n)
{
    int waitingTime[n], turnAroundTime[n], totalWaitingTime = 0, totalTurnAroundTime = 0;

    findWaitingTime(processes, n, waitingTime);
    findTurnAroundTime(processes, n, waitingTime, turnAroundTime);

    printf("Process ID\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, waitingTime[i], turnAroundTime[i]);
    }

    printf("Average Waiting Time = %.2f\n", (float)totalWaitingTime / (float)n);
    printf("Average Turn Around Time = %.2f\n", (float)totalTurnAroundTime / (float)n);
}

int main()
{
    struct Process processes[MAX_PROCESSES] = {
        {1, 4},
        {2, 2},
        {3, 3},
        {4, 4}};

    int n = sizeof(processes) / sizeof(processes[0]);


    findAverageTime(processes, n);

    return 0;
}