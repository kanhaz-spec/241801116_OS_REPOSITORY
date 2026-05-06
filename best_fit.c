#include <stdio.h>
#define MAX 100
int main() {
int m, n;
printf("Enter number of memory blocks:\n");
scanf("%d", &m);
int blockSize[MAX];
printf("Enter size of each block:\n");
for(int i = 0; i < m; i++)
scanf("%d", &blockSize[i]);
printf("Enter number of processes:\n");
scanf("%d", &n);
int processSize[MAX];
printf("Enter size of each process:\n");
for(int i = 0; i < n; i++)
scanf("%d", &processSize[i]);
int allocated[MAX] = {0};
for(int i = 0; i < n; i++) {
int bestIndex = -1;
for(int j = 0; j < m; j++) {
if(!allocated[j] && blockSize[j] >= processSize[i]) {
if(bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
bestIndex = j;
}
}
}
if(bestIndex != -1) {
int fragment = blockSize[bestIndex] - processSize[i];
printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d\n",
i + 1, processSize[i], bestIndex + 1,
blockSize[bestIndex], fragment);
allocated[bestIndex] = 1;
}
else {
printf("Process %d of size %d is not allocated\n",
i + 1, processSize[i]);
}
}
return 0;
}
