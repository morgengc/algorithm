/************************************************************
 * Quick Sort.
 *
 * It uses the solution of "Introduction to Algorithms" v2.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifdef VERIFIER
#include "verifier.h"
#endif

int PARTITION(int A[], int p, int r)
{ 
	int x, i, j, t;
	x = A[r];
	i = p-1;
	for(j=p; j<r; j++)
	{
		if(A[j] <= x)
		{
			++i;
			t = A[i];
			A[i] = A[j];
			A[j] = t; 
		}
	}
	t = A[i+1];
	A[i+1] = A[r];
	A[r] = t;

	return i+1; 
}

void QUICKSORT(int A[], int p, int r)
{
	int q;
	if(p < r)
	{
		q = PARTITION(A, p, r);
		QUICKSORT(A, p, q-1);
		QUICKSORT(A, q+1, r);
	}
}

void printArray(int A[], const unsigned int size)
{
	int i = 0;
	for (; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(int argc, char* argv[])
{
#ifndef VERIFIER
	int data[] = {44, 12, 145, -123, -1, 0, 121, 88}; 
	const unsigned int n = sizeof(data)/sizeof(int);

	printArray(data, n);

	QUICKSORT(data, 0, n-1); 

	printArray(data, n);
#else
	int *Array = NULL;
	int size = 0;
	int test_case = 0;
	for (; test_case<MAX_TEST_CASE; test_case++)
	{
		Array = FillArray(&size);
		if (!Array)
			return 0;

		QUICKSORT(Array, 0, size-1);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");
#endif

	return 0;
}

