#include <stdio.h>

#define MAX 10

// Function to find GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Find Hyperperiod
int find_hyperperiod(int T[], int n) {
    int h = T[0];
    for (int i = 1; i < n; i++) {
        h = lcm(h, T[i]);
    }
    return h;
}

int main() {
    int n;
    int C[MAX], T[MAX], D[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter C%d T%d D%d: ", i+1, i+1, i+1);
        scanf("%d %d %d", &C[i], &T[i], &D[i]);
    }

    int hyper = find_hyperperiod(T, n);

    int remaining[MAX] = {0};
    int deadline[MAX] = {0};

    printf("\nDetailed Execution:\n");

    for (int t = 0; t < hyper; t++) {

        // Release jobs
        for (int i = 0; i < n; i++) {
            if (t % T[i] == 0) {
                remaining[i] = C[i];
                deadline[i] = t + D[i];
            }
        }

        // Select task with earliest deadline
        int selected = -1;
        int min_deadline = 99999;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0 && deadline[i] < min_deadline) {
                min_deadline = deadline[i];
                selected = i;
            }
        }

        // Execute or idle
        if (selected != -1) {
            printf("%d-%d -> T%d (deadline %d)\n",
                   t, t+1, selected+1, deadline[selected]);
            remaining[selected]--;
        } else {
            printf("%d-%d -> idle\n", t, t+1);
        }
    }

    return 0;
}