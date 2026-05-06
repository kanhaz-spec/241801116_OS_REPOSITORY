#include <stdio.h>
int main() {
int n;
printf("Enter number of processes: \n");
scanf("%d", &n);
int at[n], bt[n];
int ct[n], tat[n], wt[n];
for(int i = 0; i < n; i++) {
printf("Enter Arrival Time and Burst Time for P%d: \n", i + 1);
scanf("%d %d", &at[i], &bt[i]);
}
int current_time = 0;
float total_tat = 0, total_wt = 0;
for(int i = 0; i < n; i++) {
// If CPU is idle, move time forward
if(current_time < at[i]) {
current_time = at[i];
}
current_time += bt[i];
ct[i] = current_time;
tat[i] = ct[i] - at[i];
wt[i] = tat[i] - bt[i];
total_tat += tat[i];
total_wt += wt[i];
}
printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
printf("Average Waiting Time: %.2f\n", total_wt / n);
return 0;
}
