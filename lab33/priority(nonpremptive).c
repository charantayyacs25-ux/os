#include <stdio.h>

int main(){

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    int completed[n];

    for(int i=0;i<n;i++){
        completed[i] = 0;

        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);
    }

    int current_time = 0, done = 0;
    float total_wt = 0, total_tat = 0;

    while(done < n){

        int index = -1;
        int highest_priority = 9999;

        for(int i=0;i<n;i++){
            if(at[i] <= current_time && completed[i] == 0){
                if(pr[i] < highest_priority){
                    highest_priority = pr[i];
                    index = i;
                }
            }
        }

        if(index != -1){

            ct[index] = current_time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            rt[index] = wt[index];

            total_wt += wt[index];
            total_tat += tat[index];

            current_time = ct[index];
            completed[index] = 1;
            done++;
        }
        else{
            current_time++; 
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i],rt[i]);
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}