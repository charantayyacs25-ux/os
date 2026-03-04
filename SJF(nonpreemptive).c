#include <stdio.h>

int main()
{
    int n, i, j, pos;
    int at[20], bt[20], ct[20], wt[20], tat[20], pid[20];
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int time = 0, completed = 0;
    int isCompleted[20] = {0};

    while(completed < n)
    {
        int minBT = 9999;
        pos = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && isCompleted[i] == 0)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    pos = i;
                }
            }
        }

        if(pos == -1)
        {
            time++;
        }
        else
        {
            ct[pos] = time + bt[pos];
            wt[pos] = time - at[pos];
            tat[pos] = ct[pos] - at[pos];

            time = ct[pos];
            isCompleted[pos] = 1;
            completed++;

            twt += wt[pos];
            ttat += tat[pos];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT");

    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", twt/n);
    printf("\nAverage Turnaround Time = %.2f\n", ttat/n);

    return 0;
}
