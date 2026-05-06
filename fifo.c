#include <stdio.h>
#define MAX 100
int main() {
int n, frames;
printf("Enter number of pages in reference string: \n");
scanf("%d", &n);
int ref[MAX];
printf("Enter the reference string: \n");
for(int i = 0; i < n; i++)
scanf("%d", &ref[i]);
printf("Enter number of frames: \n");
scanf("%d", &frames);
int frame[MAX];
int front = 0; // Points to oldest page
int faults = 0, hits = 0;
// Initialize frames to -1
for(int i = 0; i < frames; i++)
frame[i] = -1;
for(int i = 0; i < n; i++) {
int found = 0;
// Check if page already in frame
for(int j = 0; j < frames; j++) {
if(frame[j] == ref[i]) {
found = 1;
hits++;
break;
}
}
// If not found → Page Fault
if(!found) {
frame[front] = ref[i];
front = (front + 1) % frames;
faults++;
}
}
printf("\nTotal Page Faults: %d\n", faults);
printf("Total Page Hits: %d\n", hits);
return 0;
}
