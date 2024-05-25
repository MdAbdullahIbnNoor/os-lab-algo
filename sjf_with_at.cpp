#include <stdio.h>

int main() {
    // Matrix for storing Process Id, Arrival Time, Burst Time, Waiting Time & Turn Around Time.
    int A[100][5];
    int i, j, n, total = 0, temp;
    float avg_wt, avg_tat;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &A[i][1]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &A[i][2]);
        A[i][0] = i + 1; // Process ID
    }

    // Sorting processes according to their Arrival Time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i][1] > A[j][1]) {
                // Swap Arrival Time
                temp = A[i][1];
                A[i][1] = A[j][1];
                A[j][1] = temp;
                // Swap Burst Time
                temp = A[i][2];
                A[i][2] = A[j][2];
                A[j][2] = temp;
                // Swap Process ID
                temp = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = temp;
            }
        }
    }

    int complete = 0, currentTime = 0, minBurstTime;
    int isCompleted[100] = {0}; // To track if process is completed or not
    while (complete != n) {
        // Find process with minimum burst time among processes that have arrived till current time
        int minIndex = -1;
        minBurstTime = 100000; // A large number
        for (i = 0; i < n; i++) {
            if (A[i][1] <= currentTime && isCompleted[i] == 0 && A[i][2] < minBurstTime) {
                minBurstTime = A[i][2];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        // Calculate Waiting Time and Turn Around Time
        currentTime += A[minIndex][2];
        A[minIndex][3] = currentTime - A[minIndex][1]; // Turn Around Time
        A[minIndex][4] = A[minIndex][3] - A[minIndex][2]; // Waiting Time

        total += A[minIndex][3];
        isCompleted[minIndex] = 1;
        complete++;
    }

    total = 0;
    printf("P\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        total += A[i][4];
        printf("P%d\t%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][4], A[i][3]);
    }

    avg_wt = (float)total / n;
    total = 0;
    for (i = 0; i < n; i++) {
        total += A[i][3];
    }
    avg_tat = (float)total / n;

    printf("Average Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f", avg_tat);

    return 0;
}
