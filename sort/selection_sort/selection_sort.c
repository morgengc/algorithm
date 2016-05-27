/************************************************************
 * Selection Sort.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifdef VERIFIER
#include "verifier.h"
#endif

void SELECTION_SORT(int data[], const unsigned int size)
{
	int i, j, min, temp;
	for (i=0; i<size-1; i++) 
	{
		/* find the minimum */
		min = i;
		for (j=i+1; j<size; j++) 
		{
			if (data[j] < data[min]) 
				min = j;
		}

		/* swap data[i] and data[min] */
		temp = data[i];
		data[i] = data[min];
		data[min] = temp;
	}
}

void printArray(int A[], const unsigned int size)
{
	int i = 0;
	for (; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
#ifndef VERIFIER
	int input[] = {23,4,56,12,13,11,19,7,5,6,3,7,32,27};
	int n = sizeof(input)/sizeof(int);

	printArray(input, n);

	SELECTION_SORT(input, n);

	printArray(input, n);
#else
	int *Array = NULL;
	int size = 0;
	int test_case = 0;
	for (; test_case<MAX_TEST_CASE; test_case++)
	{
		Array = FillArray(&size);
		if (!Array)
			return 0;

		SELECTION_SORT(Array, size);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");


#endif

	return 0;
} 
