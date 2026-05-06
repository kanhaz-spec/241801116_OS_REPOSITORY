#include <stdio.h>
int main() {
int n, i, completed = 0, current_time = 0;
printf("Enter number of processes: \n");
scanf("%d", &n);
int at[n], bt[n], pr[n];
int ct[n], tat[n], wt[n];
int visited[n];
for(i = 0; i < n; i++) {
printf("Enter AT, BT and Priority for P%d: \n", i + 1);
scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
visited[i] = 0; // Mark as not completed
}
float total_tat = 0, total_wt = 0;
while(completed < n) {
int idx = -1;
int highest_priority = 9999;
// Select process with highest priority among arrived ones
for(i = 0; i < n; i++) {
if(at[i] <= current_time && visited[i] == 0) {
if(pr[i] < highest_priority) {
highest_priority = pr[i];
idx = i;
}
}
}
// If no process has arrived
if(idx == -1) {
current_time++;
}
else {
current_time += bt[idx];
ct[idx] = current_time;
tat[idx] = ct[idx] - at[idx];
wt[idx] = tat[idx] - bt[idx];
total_tat += tat[idx];
total_wt += wt[idx];
visited[idx] = 1;
completed++;
}
}
printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
printf("Average Waiting Time = %.2f\n", total_wt / n);
return 0;
}
