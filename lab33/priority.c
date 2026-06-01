#include <stdio.h>

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], pr[n];
    int rt[n], ct[n], tat[n], wt[n], resp[n];
    int started[n];

    for(int i=0;i<n;i++){
        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i] = bt[i];   
        started[i] = 0;
    }

    int complete = 0, current_time = 0;
    int min_index;
    int highest_priority;

    float total_wt = 0, total_tat = 0, total_rt = 0;

    while(complete < n){

        min_index = -1;
        highest_priority = 9999;

        
        for(int i=0;i<n;i++){
            if(at[i] <= current_time && rt[i] > 0){
                if(pr[i] < highest_priority){
                    highest_priority = pr[i];
                    min_index = i;
                }
            }
        }

        if(min_index == -1){
            current_time++;
            continue;
        }

        
        if(started[min_index] == 0){
            resp[min_index] = current_time - at[min_index];
            started[min_index] = 1;
        }

        rt[min_index]--;

        if(rt[min_index] == 0){
            complete++;

            ct[min_index] = current_time + 1;
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            total_wt += wt[min_index];
            total_tat += tat[min_index];
            total_rt += resp[min_index];
        }

        current_time++;
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i],resp[i]);
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f", total_tat/n);
    printf("\nAverage RT = %.2f\n", total_rt/n);

    return 0;
}