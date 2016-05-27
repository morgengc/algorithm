/************************************************************
 * Bubble Sort.
 *
 * It uses the solution of "Introduction to Algorithms" v2.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.08
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../utils/numeric.h"

#ifdef VERIFIER
#include "verifier.h"
#endif

#ifdef PRINT_PROCESS
#include "printProcess.h"
#endif

void BUBBLESORT(int array[], const unsigned int size)
{
	int i,j,temp = 0;

	for(i=0; i<size; i++)
	{
		for (j=size-1; j>i; j--)
		{
			if (array[j] < array[j-1])
			{
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
#ifdef PRINT_PROCESS
				printProcess(array, size, j-1);
#endif
			}
		}
	}
}

void printArray(int A[], const unsigned int size)
{
	int i = 0;
	printf("\n");
	for (; i<size; i++)
		printf("%d ", A[i]);
	printf("\n\n");
}

int main()
{
#ifndef VERIFIER
	int input[] = {23,4,56,99,11,32,-1,-8};
	const unsigned int n = ARRSIZE(input);

	printArray(input, n);

	BUBBLESORT(input,n);

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

		BUBBLESORT(Array, size);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");

#endif

	return 0;
} 

