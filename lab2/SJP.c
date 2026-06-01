#include <stdio.h>

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    int completed[n];

    for(int i = 0; i < n; i++) {
        completed[i] = 0;

        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int current_time = 0, done = 0;
    float total_wt = 0, total_tat = 0;

    while(done < n) {

        int min_index = -1;
        int min_bt = 10000;

        
        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    min_index = i;
                }
            }
        }

        if(min_index != -1) {

            ct[min_index] = current_time + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            rt[min_index] = wt[min_index];

            total_wt += wt[min_index];
            total_tat += tat[min_index];

            current_time = ct[min_index];
            completed[min_index] = 1;
            done++;
        }
        else {
            current_time++;   
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);

    return 0;
}