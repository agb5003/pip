#include <stdio.h>

#define LEN 5

void maxmin_array(int array[], int *pmax, int *pmin);

int main() {
	int max,min;
	int array[LEN];
	int i;
	// assign array
	for(i=0; i < LEN; i++){
		printf("array[%d] = ",i);
		scanf("%d", &array[i]);
	}
	/* find max-min value from array */
	maxmin_array(array, &max, &min);
	printf("max:%d min:%d\n", max, min);
	return 0;
}

void maxmin_array(int array[], int *pmax, int *pmin) {
	// This function modifies max and min by using the pointers pmax and pmin.
	// For the array, we are essentially passing the pointer to the first element
	// by passing int array[] as an argument. Note that this can essentially be 
	// replaced by passing int *array, but it's less readable in this context.
	
	// First set max and min to the first element
	*pmax = array[0]; *pmin = array[0];

	// The for loop can start from i=1 since initial value is index 0
	for (int i = 1; i < LEN; i++) {
		if (array[i] > *pmax) {
			*pmax = array[i];  // array[i] is the same as *(array+i).
		} else if (array[i] < *pmin) {
			*pmin = array[i];
		}
	}
}
