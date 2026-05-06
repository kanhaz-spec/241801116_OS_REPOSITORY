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
int frame[MAX], time[MAX];
int faults = 0, hits = 0;
int counter = 0;
// Initialize frames
for(int i = 0; i < frames; i++) {
frame[i] = -1;
time[i] = 0;
}
for(int i = 0; i < n; i++) {
int found = -1;
// Check for hit
for(int j = 0; j < frames; j++) {
if(frame[j] == ref[i]) {
found = j;
break;
}
}
if(found != -1) {
hits++;
counter++;
time[found] = counter; // Update recent usage
}
else {
faults++;
counter++;
int empty = -1;
// Check for empty frame
for(int j = 0; j < frames; j++) {
if(frame[j] == -1) {
empty = j;
break;
}
}
if(empty != -1) {
frame[empty] = ref[i];
time[empty] = counter;
}
else {
// Find least recently used
int lru = 0;
for(int j = 1; j < frames; j++) {
if(time[j] < time[lru])
lru = j;
}
}}
}
