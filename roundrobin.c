#include <stdio.h>
int main() {
int n, tq;
printf("Enter number of processes: \n");
scanf("%d", &n);
printf("Enter Time Quantum: \n");
scanf("%d", &tq);
int at[n], bt[n], rt[n];
int ct[n], tat[n], wt[n];
int completed = 0, current_time = 0;
for(int i = 0; i < n; i++) {
printf("Enter AT and BT for P%d: \n", i + 1);
scanf("%d %d", &at[i], &bt[i]);
rt[i] = bt[i]; // Remaining time initially equals burst time
}
float total_tat = 0, total_wt = 0;
while(completed < n) {
int done = 1;
for(int i = 0; i < n; i++) {
if(rt[i] > 0 && at[i] <= current_time) {
done = 0;
if(rt[i] > tq) {
current_time += tq;
rt[i] -= tq;
}
else {
current_time += rt[i];
ct[i] = current_time;
rt[i] = 0;
completed++;
}
}
}
// If no process executed, move time forward
if(done == 1)
current_time++;
}
// Calculate TAT and WT
for(int i = 0; i < n; i++) {
tat[i] = ct[i] - at[i];
wt[i] = tat[i] - bt[i];
total_tat += tat[i];
total_wt += wt[i];
}
printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
printf("Average Waiting Time: %.2f\n", total_wt / n);
return 0;
}
