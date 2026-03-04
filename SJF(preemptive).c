#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, time = 0, smallest, count = 0;
    int at[20], bt[20], rt[20], ct[20], wt[20], tat[20];
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Remaining time = Burst time
    }

    while(count != n)
    {
        smallest = -1;
        int min = INT_MAX;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                smallest = i;
            }
        }

        if(smallest == -1)
        {
            time++;
            continue;
        }

        rt[smallest]--;   // Execute process for 1 unit
        time++;

        if(rt[smallest] == 0)
        {
            count++;
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            twt += wt[smallest];
            ttat += tat[smallest];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT");

    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", twt / n);
    printf("\nAverage Turnaround Time = %.2f\n", ttat / n);

    return 0;
}
