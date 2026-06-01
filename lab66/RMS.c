#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    float C[10], T[10], U = 0, bound;
    int tempIndex[10];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Step 1: Input and CPU Utilization
    for(i = 0; i < n; i++) {
        printf("Enter C%d and T%d: ", i+1, i+1);
        scanf("%f %f", &C[i], &T[i]);
        U += C[i] / T[i];
        tempIndex[i] = i + 1;  // store task number
    }

    printf("\nCPU Utilization (U) = %.4f\n", U);

    // Step 2: RMS Bound
    bound = n * (pow(2, 1.0/n) - 1);
    printf("RMS Bound = %.4f\n", bound);

    // Step 3: Check Schedulability
    if(U <= bound)
        printf("Schedulable using RMS\n");
    else
        printf("Not guaranteed schedulable\n");

    // Step 4: Sort tasks by period (ascending)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(T[i] > T[j]) {
                float tempT = T[i];
                T[i] = T[j];
                T[j] = tempT;

                float tempC = C[i];
                C[i] = C[j];
                C[j] = tempC;

                int temp = tempIndex[i];
                tempIndex[i] = tempIndex[j];
                tempIndex[j] = temp;
            }
        }
    }

    printf("\nTask Priority (smaller T = higher priority):\n");
    for(i = 0; i < n; i++) {
        printf("Task %d (T=%.2f)\n", tempIndex[i], T[i]);
    }

    // Step 5: Simple Scheduling Loop (one round)
    printf("\nScheduling Order:\n");
    for(i = 0; i < n; i++) {
        printf("Executing Task %d\n", tempIndex[i]);
    }

    return 0;
}