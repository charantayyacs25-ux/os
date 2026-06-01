#include <stdio.h>

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], weight[n];
    int ct[n], tat[n], wt[n];

    int total_weight = 0;

    // Input
    for(int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Weight: ");
        scanf("%d", &weight[i]);

        rt[i] = bt[i];
        total_weight += weight[i];
    }

    int time = 0, completed = 0;

    // Proportional Scheduling Loop
    while(completed < n) {

        for(int i = 0; i < n; i++) {

            if(rt[i] > 0) {

                // proportional time slice
                int slice = weight[i];

                if(rt[i] > slice) {
                    time += slice;
                    rt[i] -= slice;
                }
                else {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i];
                    wt[i] = tat[i] - bt[i];

                    completed++;
                }
            }
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nP\tBT\tWT\tTAT\tCT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
        i+1, bt[i], wt[i], tat[i], ct[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f\n", avg_tat/n);

    return 0;
}