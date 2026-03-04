#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int at[20], bt[20], ct[20], wt[20], tat[20], pid[20];
    float twt = 0, ttat = 0, awt, att;

    printf("Enter number of processes: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;  
        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
             
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

              
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

             
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
            wt[i] = 0;
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
            wt[i] = ct[i - 1] - at[i];
        }

        tat[i] = bt[i] + wt[i];
    }

    for (i = 0; i < n; i++)
    {
        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt / n;
    att = ttat / n;


    printf("\nPID\tAT\tBT\tCT\tWT\tTAT");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", att);

    return 0;
}