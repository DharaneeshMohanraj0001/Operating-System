#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

void swap_processes(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_arrival_time(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap_processes(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void round_robin_scheduling(struct Process processes[], int n, int quantum) {
    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (processes[i].remaining_time <= quantum) {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed_processes++;
                    printf("Process %d completed at time %d\n", processes[i].id, current_time);
                } else {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("Process %d executed for %d units at time %d\n", processes[i].id, quantum, current_time);
                }
            }
        }
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of each process (ID, Arrival Time, Burst Time, Priority):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &processes[i].id, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    sort_by_arrival_time(processes, n);

    printf("\nRound Robin Scheduling:\n");
    round_robin_scheduling(processes, n, quantum);

    return 0;
}