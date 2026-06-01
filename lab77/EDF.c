#include <stdio.h>

int main() {
    int n, i, t = 0, completed = 0;

    int arrival[10], burst[10], deadline[10];
    int remaining[10], done[10];

    float U = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Execution Time: ");
        scanf("%d", &burst[i]);

        printf("Deadline: ");
        scanf("%d", &deadline[i]);

        remaining[i] = burst[i];
        done[i] = 0;

        U += (float)burst[i] / deadline[i];
    }

    // Feasibility check
    printf("\nCPU Utilization = %.2f\n", U);
    if(U > 1)
        printf("Not Feasible\n");
    else
        printf("Feasible\n");

    // EDF Scheduling
    while(completed < n) {
        int idx = -1;
        int min_deadline = 9999;

        // Find earliest deadline
        for(i = 0; i < n; i++) {
            if(arrival[i] <= t && done[i] == 0) {
                if(deadline[i] < min_deadline) {
                    min_deadline = deadline[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            printf("Time %d: Idle\n", t);
            t++;
            continue;
        }

        printf("Time %d: P%d running\n", t, idx + 1);

        remaining[idx]--;

        if(remaining[idx] == 0) {
            done[idx] = 1;
            completed++;
            printf("Time %d: P%d completed\n", t + 1, idx + 1);
        }

        t++;
    }

    return 0;
}