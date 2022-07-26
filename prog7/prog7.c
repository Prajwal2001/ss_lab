#include<stdio.h>

#include<stdlib.h>

int arrival[10];
int burst[10];
int rem[10];
int wait[10];
int finish[10];
int turnaround[10];
int flag[10];
void roundrobin(int, int, int[], int[]);
void srtf(int);
int main() {
    int n, tq, choice;
    int bt[10], st[10], i, j;
    for (;;) {
        printf("Enter the choice\n 1. Round Robin\n 2. SRT\n 3. Exit\n");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            printf("Enter no. of process:\n");
            scanf("%d", & n);
            printf("Enter Burst Time\n");
            for (i = 0; i < n; i++) {
                scanf("%d", & bt[i]);
                st[i] = bt[i];
            }
            printf("Enter Time Quantum");
            scanf("%d", & tq);
            roundrobin(n, tq, st, bt);
            break;
        case 2:
            printf("\n\n Enter the no. of process:");
            scanf("%d", & n);
            srtf(n);
            break;
        case 3:
            return 0;
        }
    }
}
void roundrobin(int n, int tq, int st[], int bt[]) {
    int time = 0;
    int tat[10], wt[10], i, count = 0, swt = 0, stat = 0, temp1, sq = 0;
    while (1) {
        for (i = 0, count = 0; i < n; i++) {
            temp1 = tq;
            if (st[i] == 0) {
                count++;
                continue;
            }
            if (st[i] > tq)
                st[i] = st[i] - tq;
            else
            if (st[i] >= 0) {
                temp1 = st[i];
                st[i] = 0;
            }
            sq = sq + temp1;
            tat[i] = sq;
        }
        if (n == count)
            break;
    }
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        swt = swt + wt[i];
        stat = stat + tat[i];
    }
    printf("Process_no Burst Time Wait Time Turnaround Time\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    printf("Average waiting time is %f\n Average turnaround time is %f\n", (float) swt / n, (float) stat / n);
}
void srtf(int n) {
    int stat = 0, swt = 0, time = 0, count = 0, i, j, min = 999;
    for (i = 1; i <= n; i++) {
        printf("Arrival of p%d : ", i);
        scanf("%d", & arrival[i]);
        printf("Burst of p%d :", i);
        scanf("%d", & burst[i]);
        rem[i] = burst[i];
        flag[i] = 0;
    }
    while (1) {
        for (i = 1, min = 999; i <= n; i++)
            if (arrival[i] <= time && flag[i] == 0)
                if (rem[i] < min) {
                    min = rem[i];
                    j = i;
                }
        time++;
        rem[j] -= 1;
        if (rem[j] == 0) {
            finish[j] = time;
            flag[j] = 1;
            count++;
        }
        if (count == n)
            break;
    }
    for (i = 1; i <= n; i++) {
        turnaround[i] = finish[i] - arrival[i];
        wait[i] = turnaround[i] - burst[i];
        stat += turnaround[i];
        swt += wait[i];
    }
    printf("The process table: \n\t Process no.\t|Finish\t|Wait\t|Turnaround\t\n");
    for (i = 1; i <= n; i++)
        printf("\t%d\t|%d\t|%d\t|%d\t|%d\t|%d\n", i, arrival[i], burst[i], finish[i], wait[i], turnaround[i]);
    printf("AverageWaitingTime: %f\t Avgturnaroundtime: %f\n", (float) swt / n, (float) stat / n);
    return;
}
