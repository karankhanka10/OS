#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    int min_index;
    while (completed < n) {
        int min_remaining_time = 9999; // A large initial value

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_remaining_time && processes[i].remaining_time > 0) {
                min_remaining_time = processes[i].remaining_time;
                min_index = i;
            }
        }

        if (min_remaining_time == 9999) {
            current_time++;
        } else {
            processes[min_index].remaining_time--;
            current_time++;
            if (processes[min_index].remaining_time == 0) {
                completed++;
                printf("Process %d completed at time %d\n", processes[min_index].id, current_time);
            }
        }
    }

    return 0;
}
