#include <stdio.h>
#include <stdbool.h>
int main() {
int n, m;
// Input: Number of processes and resource types
printf("Enter number of processes: \n");
if (scanf("%d", &n) != 1) return 0;
printf("Enter number of resource types: \n");
if (scanf("%d", &m) != 1) return 0;
int alloc[n][m], max[n][m], avail[m], need[n][m];
// Input: Allocation Matrix
printf("Enter Allocation Matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
scanf("%d", &alloc[i][j]);
}
}
// Input: Max Matrix
printf("Enter Max Matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
scanf("%d", &max[i][j]);
}
}
// Input: Available Resources
printf("Enter Available Resources: \n");
for (int j = 0; j < m; j++) {
scanf("%d", &avail[j]);
}
// Calculate Need Matrix: Need[i][j] = Max[i][j] - Allocation[i][j]
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
need[i][j] = max[i][j] - alloc[i][j];
}
}
bool finish[n];
for (int i = 0; i < n; i++) finish[i] = false;
int safeSeq[n];
int count = 0;
// Banker's Safety Algorithm
while (count < n) {
bool found = false;
for (int i = 0; i < n; i++) {
if (!finish[i]) {
bool possible = true;
// Check if Need <= Available
for (int j = 0; j < m; j++) {
if (need[i][j] > avail[j]) {
possible = false;
break;
}
}
if (possible) {
// Pretend to allocate and release resources
for (int j = 0; j < m; j++) {
avail[j] += alloc[i][j];
}
safeSeq[count++] = i;
finish[i] = true;
}
}
}}
