#include <stdio.h>
#define MAX 100
int main() {
int m, n;
printf("Enter number of memory blocks: \n");
scanf("%d", &m);
int blockSize[MAX];
printf("Enter size of each block: \n");
for(int i = 0; i < m; i++)
scanf("%d", &blockSize[i]);
printf("Enter number of processes: \n");
scanf("%d", &n);
int processSize[MAX];
printf("Enter size of each process: \n");
for(int i = 0; i < n; i++)
scanf("%d", &processSize[i]);
int allocated[MAX] = {0}; // 0 means block is free
for(int i = 0; i < n; i++) {
int allocatedFlag = 0;
for(int j = 0; j < m; j++) {
if(!allocated[j] && blockSize[j] >= processSize[i]) {
int fragment = blockSize[j] - processSize[i];
printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d\n",
i + 1, processSize[i], j + 1, blockSize[j], fragment);
allocated[j] = 1;
allocatedFlag = 1;
break;
}
}
if(!allocatedFlag) {
printf("Process %d of size %d is not allocated\n",
i + 1, processSize[i]);
}
}
return 0;
}
