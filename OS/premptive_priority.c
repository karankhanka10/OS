#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int priority;
    int burst_time;
    int remaining_time;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int completed = 0;
    int current_time = 0;

    while (completed < n) {
        int highest_priority = 9999; // A large initial value
        int selected_process = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            current_time++;
        } else {
            processes[selected_process].remaining_time--;
            current_time++;
            if (processes[selected_process].remaining_time == 0) {
                completed++;
                printf("Process %d completed at time %d\n", processes[selected_process].id, current_time);
            }
        }
    }

    return 0;
}
