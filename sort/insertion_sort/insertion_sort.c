/************************************************************
 * Insertion Sort.
 *
 * It uses the solution of "Introduction to Algorithms" v2.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.08
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifdef VERIFIER
#include "verifier.h"
#endif

void INSERTION_SORT(int A[], const unsigned int size)
{
	int i = 0, j = 0;
	int key = 0;

	for(j=1; j<size; j++)
	{
		key = A[j];
		i = j-1;

		for(; (i>=0) && (key < A[i]); i--)
		{
			A[i+1] = A[i];
		}
		A[i+1] = key;
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
	const unsigned int n = sizeof(input)/sizeof(int);

	printArray(input, n);

	INSERTION_SORT(input, n);

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

		INSERTION_SORT(Array, size);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");
#endif

	return 0; 
}

