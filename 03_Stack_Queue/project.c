#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

void readProcessesFromFile(const char* filename, Process** processes, int* num_processes) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    fscanf(file, "%d", num_processes);
    *processes = (Process*)malloc(*num_processes * sizeof(Process));

    for (int i = 0; i < *num_processes; i++) {
        fscanf(file, "%d %d %d %d", &(*processes)[i].process_id, &(*processes)[i].arrival_time, &(*processes)[i].burst_time, &(*processes)[i].priority);
        (*processes)[i].waiting_time = 0;
        (*processes)[i].turnaround_time = 0;
    }

    fclose(file);
}

void priorityScheduling(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }
}

void calculateAverageMetrics(Process* processes, int num_processes, double* avg_waiting_time, double* avg_turnaround_time) {
    *avg_waiting_time = 0;
    *avg_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        *avg_waiting_time += processes[i].waiting_time;
        *avg_turnaround_time += processes[i].turnaround_time;
    }

    *avg_waiting_time /= num_processes;
    *avg_turnaround_time /= num_processes;
}

void printGanttChart(Process* processes, int num_processes) {
    printf("Gantt Chart:\n");
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        printf("| P%d ", processes[i].process_id);
        current_time += processes[i].burst_time;
    }
    printf("|\n");
}

int main() {
    Process* processes = NULL;
    int num_processes;

    readProcessesFromFile("input.txt", &processes, &num_processes);

    priorityScheduling(processes, num_processes);

    double avg_waiting_time, avg_turnaround_time;
    calculateAverageMetrics(processes, num_processes, &avg_waiting_time, &avg_turnaround_time);

    printGanttChart(processes, num_processes);

    printf("Average Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n");

    free(processes);

    return 0;
}
