#include "../inc/bubblesort.h"

void bubbleSort(int* arr, int size) {
	for (int m = size - 1; m > 0; m--) { //loop through the entire array backwards
		for (int n = 0; n < m; n++) { //for every step through array, loop through array and move number towards back if it's larger than the next value
			if (arr[n] > arr[n + 1]) {
				int temp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = temp;
			}
		}
	}
}
void bubbleSort(char* arr, int size) {
	for (int m = size - 1; m > 0; m--) { //loop through the entire array backwards
		for (int n = 0; n < m; n++) { //for every step through array, loop through array and move number towards back if it's larger than the next value
			if (arr[n] > arr[n + 1]) {
				char temp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = temp;
			}
		}
	}
}