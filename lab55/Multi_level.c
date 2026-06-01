#include <stdio.h>


int main() {
    int n;
    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int PID[n], AT[n], BT[n], TYPE[n];
    int CT[n], TAT[n], WT[n], Start[n];

    int systemQueue[n], userQueue[n];
    int sysCount = 0, userCount = 0;

    int time = 0;

  

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &PID[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Type (0 = System, 1 = User): ");
        scanf("%d", &TYPE[i]);
    }

    // Step 1: Separate into queues
    for (int i = 0; i < n; i++) {
        if (TYPE[i] == 0)
            systemQueue[sysCount++] = i;
        else
            userQueue[userCount++] = i;
    }

    // Step 2: Sort System Queue by Arrival Time
    for (int i = 0; i < sysCount - 1; i++) {
        for (int j = i + 1; j < sysCount; j++) {
            if (AT[systemQueue[i]] > AT[systemQueue[j]]) {
                int temp = systemQueue[i];
                systemQueue[i] = systemQueue[j];
                systemQueue[j] = temp;
            }
        }
    }

    // Sort User Queue by Arrival Time
    for (int i = 0; i < userCount - 1; i++) {
        for (int j = i + 1; j < userCount; j++) {
            if (AT[userQueue[i]] > AT[userQueue[j]]) {
                int temp = userQueue[i];
                userQueue[i] = userQueue[j];
                userQueue[j] = temp;
            }
        }
    }

    // Step 3: Execute System Processes
    for (int i = 0; i < sysCount; i++) {
        int p = systemQueue[i];

        if (time < AT[p])
            time = AT[p];

        Start[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }

    // Step 4: Execute User Processes
    for (int i = 0; i < userCount; i++) {
        int p = userQueue[i];

        if (time < AT[p])
            time = AT[p];

        Start[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }

    // Step 5: Display Results
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               PID[i], AT[i], BT[i], TYPE[i],
               CT[i], TAT[i], WT[i]);
    }

    return 0;
}