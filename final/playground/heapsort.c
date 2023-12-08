#include <stdio.h>

#define ARRAY_SIZE 14

void heapify(int array[], int n, int i);
void heapsort(int array[], int n);
void swap(int *pointerA, int *pointerB);

int main() {
	int array[] = {9,5,8,5,4,3,7,6,4,2,1,3,9,8};

	heapsort(array, ARRAY_SIZE);
	
	printf("Array: ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

void heapsort(int array[], int n) {
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(array, n, i);
	}

	// Heap sort
	for (int i = n -1; i >=0; i--) {
		// "Remove" root from heap by swapping it with the
		// last element in the heap, then heapify to get
		// largest element at the root again, repeat until heap
		// is gone.
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}

void heapify(int array[], int n, int i) {
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;

	if (left < n && array[left] > array[largest]) {
		largest = left;
	}
	if (right < n && array[right] > array[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}
}
	
void swap(int *pointerA, int *pointerB) {
	*pointerA += *pointerB;
	*pointerB = *pointerA - *pointerB;
	*pointerA -= *pointerB;
}

