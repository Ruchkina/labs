#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_VALUE 50
#define MIN_VALUE -50

#define UP   1
#define DOWN 0

void inputArray(int *arr, int n) {
    srand(time(0));
    for (int i=0; i<n; i++)
        arr[i]=rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
}

void outputArray(int *arr, int n) {
    for (int i=0; i<n; i++)
        // printf("%d: %d\n", i, arr[i]);
        printf("%d ", arr[i]);
    printf("\n");

}

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void bubbleSort(int* l, int* r, int direction) {
	if (r - l <= 1) return;
	int b = 1;
	while (b) {
		b = 0;
		for (int* i = l; i < r; i++) {
            if (direction == UP) {
                if (*i > *(i + 1)) {
                    swap(i, i + 1);
                    b = 1;
                }
            }
            else {
                if (*i < *(i + 1)) {
                    swap(i, i + 1);
                    b = 1;
                }
            }
		}
		r--;
	}
}

 
// void shakersort(int* l, int* r) {
// 	int sz = r - l;
// 	if (sz <= 1) return;
// 	bool b = true;
// 	int* beg = l - 1;
// 	int* end = r - 1;
// 	while (b) {
// 		b = false;
// 		beg++;
// 		for (int* i = beg; i < end; i++) {
// 			if (*i > *(i + 1)) {
// 				swap(*i, *(i + 1));
// 				b = true;
// 			}
// 		}
// 		if (!b) break;
// 		end--;
// 		for (int* i = end; i > beg; i--) {
// 			if (*i < *(i - 1)) {
// 				swap(*i, *(i - 1));
// 				b = true;
// 			}
// 		}
// 	}
// }