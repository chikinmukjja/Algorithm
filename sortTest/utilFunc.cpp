#include "sortTest.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	
}

void printArray(int *array, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool makeRandomArray(int *array, int size)
{
	int i = 0;

	srand(time(NULL));
	for (i = 0; i < size; i++) {

		array[i] = rand()%10;
		//printf("%d\n", array[i]);

	}
	return true;
}

bool copyArray(int *inputArray, int *outputArray,int size)
{
	int i;

	for (i = 0; i < size; i++) {

		outputArray[i] = inputArray[i];
		//printf("%d\n", array[i]);

	}
	return true;
}