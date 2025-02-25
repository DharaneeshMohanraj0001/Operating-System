#include <stdio.h>

#define MAX_PROCESSES 5

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int priority;
};

void sjf_scheduling(struct Process processes[], int n)
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
        int shortest_burst = 99999;
        int shortest_index = -1;

        for (j = 0; j < n; j++)
        {
            if (completed[j] == 0 && processes[j].arrival_time <= time && processes[j].burst_time < shortest_burst)
            {
                shortest_burst = processes[j].burst_time;
                shortest_index = j;
            }
        }

        if (shortest_index == -1)
        {
            break;
        }

        completed[shortest_index] = 1;
        time += processes[shortest_index].burst_time;
        printf("Process %d completed at time %d\n", processes[shortest_index].id, time);
    }
}

int main()
{
    struct Process processes[MAX_PROCESSES] = {
        {1, 0, 10, 3},
        {2, 2, 4, 1},
        {3, 3, 9, 2},
        {4, 4, 3, 4}};

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Shortest Job First Scheduling\n");
    sjf_scheduling(processes, n);

    return 0;
}