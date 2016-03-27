#include "sortTest.h"
#define SIZE 10000

int main()
{
	int a[SIZE];
	int b[SIZE];
	double quick;
	double ins;
	bool err;
	
	{
		makeRandomArray(a, SIZE);
		copyArray(a, b, SIZE);
		//printArray(a, SIZE);
		//printArray(b, SIZE);

		CHECK_TIME_START;
		quickSort(a, 0, SIZE - 1);
		CHECK_TIME_END(quick, err);
		printf("quick time : %.6f\n", quick);
	}
	


	{
		
		CHECK_TIME_START;
		insertionSort(b, SIZE);
		CHECK_TIME_END(ins, err);
		printf("insertion time : %.6f\n", ins);
	}
	
	

}


void insertionSort(int *array,int size)
{
	int key = 0;
	int j = 0;

	for (int i = 1; i < size; i++) {
		key = array[i];                      
		j = i - 1;
		while (j >= 0 && array[j]>key){
		
			swap(&array[j + 1], &array[j]);
			j = j - 1;
		}
		array[j + 1] = key;

	}

}

void quickSort(int *array, int p, int r)
{
	int q;
	if (p < r){
		q = partition(array,p,r);
		quickSort(array, p, q -1);
		quickSort(array, q + 1, r);
	}
}

int partition(int *array, int p, int q)
{
	int x = array[p];
	int i = p;

	for (int j = p + 1; j <= q; j++){
		if (array[j] <= x) {
			i = i + 1;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[p], &array[i]);
	return i;
}

