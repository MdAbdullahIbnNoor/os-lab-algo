#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], total_wt = 0, total_tat = 0, i, j;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Process Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate average waiting time and turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\n\nAverage Waiting Time: %.2f", avg_wt);
    printf("nAverage Turnaround Time: %.2f", avg_tat);

    return 0;
}
