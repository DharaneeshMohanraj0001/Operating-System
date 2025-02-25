#include <stdio.h>
#define MAX_PROCESSES 10

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int priority;
};

void priority_scheduling(struct Process processes[], int n)
{
    int completed[n];
    int time = 0;
    int i, j;

    for (i = 0; i < n; i++)
    {
        completed[i] = 0;
    }

    while (1)
    {
        int highest_priority = -1;
        int shortest_burst = 99999;

        for (j = 0; j < n; j++)
        {
            if (completed[j] == 0 && processes[j].priority > highest_priority && processes[j].burst_time <= shortest_burst)
            {
                highest_priority = processes[j].priority;
                shortest_burst = processes[j].burst_time;
                i = j;
            }
        }

        if (highest_priority == -1)
        {
            break;
        }

        completed[i] = 1;
        time += processes[i].burst_time;
        printf("Process %d completed at time %d\n", processes[i].id, time);
    }
}

int main()
{
    struct Process processes[MAX_PROCESSES] = {
        {1, 0, 10, 3},
        {2, 2, 4, 1},
        {3, 3, 9, 9},
        {4, 4, 3, 4}};

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Priority Scheduling\n");
    priority_scheduling(processes, n);

    return 0;
}