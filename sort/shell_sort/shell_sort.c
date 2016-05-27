/************************************************************
 * Shell Sort.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************************/

/*
23 4 56 12 13 11 19 7 5 6 3 7 32 27 
3 4 5 6 7 7 11 12 13 19 23 27 32 56 
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef VERIFIER
#include "verifier.h"
#endif

void SHELL_SORT(int a[], const unsigned int n)
{
	int i, j, gap, temp;
	gap = n / 2; 
	while (gap > 0) 
	{
		for ( i = gap; i < n; i++ )
		{
			j = i - gap;
			temp = a[i];             
			while (( j >= 0 ) && ( a[j] > temp ))
			{
				a[j + gap] = a[j];
				j = j - gap;
			}
			a[j + gap] = temp;
		}
		gap = gap / 2;
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
	int n = 0;
	int a[] = {23,4,56,12,13,11,19,7,5,6,3,7,32,27}; 
	n = sizeof(a)/sizeof(int);

	printArray(a, n);

	SHELL_SORT(a, n);

	printArray(a, n);
#else
	int *Array = NULL;
	int size = 0;
	int test_case = 0;
	for (; test_case<MAX_TEST_CASE; test_case++)
	{
		Array = FillArray(&size);
		if (!Array)
			return 0;

		SHELL_SORT(Array, size);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");
#endif

	return 0;
}

