/************************************************************
 * Merge Sort.
 *
 * It uses the solution of "Introduction to Algorithms" v2.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.08
 ***********************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <limits.h> // INT_MAX defined here.

#ifdef VERIFIER
#include "verifier.h"
#endif

void MERGE(int A[], const unsigned int p, const unsigned int q, const unsigned int r) 
{ 
	int i, j, k, n1, n2; 

	n1 = q - p + 1; 
	n2 = r - q; 

	int L[n1+1]; 
	int R[n2+1]; 

	for(i = 0; i < n1; i++) 
	{
		L[i] = A[p+i]; 
		// A[p+i] = 0;
	}
	for(j = 0; j < n2; j++) 
	{
		R[j] = A[q+j+1]; 
		// A[q+j+1] = 0;
	}

	/* must need a sentinel at the end. */
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	i = 0;
	j = 0;

	for(k = p; k <= r; k++) 
	{ 
		if(L[i] <= R[j]) /* if no sentinel at L[n1] or R[n2], it may overflow. */ 
		{ 
			A[k] = L[i]; 
			i++; 
		} 
		else 
		{ 
			A[k] = R[j]; 
			j++; 
		} 
	}
}

void MERGE_SORT(int A[], const unsigned int p, const unsigned int r) 
{ 
	if(p < r) 
	{ 
		int q = (p + r) / 2; 
		MERGE_SORT(A, p, q); 
		MERGE_SORT(A, q + 1, r);

		MERGE(A, p, q, r); 
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
	int data[] = {44, 12, 145, -123, -1, 0, 121, 88}; 
	const unsigned int n = sizeof(data)/sizeof(int);

	printArray(data, n);

	MERGE_SORT(data, 0, n-1); 

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

		MERGE_SORT(Array, 0, size-1);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");
#endif

	return 0; 
} 

