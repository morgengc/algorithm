/************************************************************
 * Counting Sort.
 *
 * It uses the solution of "Introduction to Algorithms" v2.
 *
 * NOTE: unlike other algorithms, ordered elements are stored
 *       in array B, not in A !!!
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#ifdef VERIFIER
#include "verifier.h"
#define VALUE_UPPER_LIMIT MAX_ELEMENT
#else
#define VALUE_UPPER_LIMIT 100
#endif

void COUNTING_SORT(int A[], int B[], int k, const unsigned int length)
{
	int *c = (int *)malloc((k+1)*sizeof(int));
	int i = 0, j = 0;

	for(i=0; i<=k; i++)
		c[i] = 0;

	for(j=0; j<length; j++)
		c[A[j]] = c[A[j]]+1;

	for(i=1; i<=k; i++)
		c[i] += c[i-1];

	for(j=length-1; j>=0; j--)
	{
		B[c[A[j]]-1] = A[j];
		c[A[j]] = c[A[j]]-1;
	}
	free(c);
}

int main()
{
#ifndef VERIFIER
	int a[] = {19,5,2,6,7,12,10,3,8,4,11,18,17};
	const unsigned int n = sizeof(a)/sizeof(int);
	int *b = (int *)malloc(n*sizeof(int));
	if (!b)
		return 0;

	COUNTING_SORT(a, b, VALUE_UPPER_LIMIT, n);

	int i = 0;
	for(; i<n; i++)
		printf("%d ",b[i]);
	printf("\n");

	free(b);
#else
	int *Array = NULL;
	int size = 0;
	int test_case = 0;
	for (; test_case<MAX_TEST_CASE; test_case++)
	{
		Array = FillArray(&size);
		if (!Array)
			return 0;

		int *b = (int *)malloc(size*sizeof(int));
		if (!b)
			return 0;

		COUNTING_SORT(Array, b, VALUE_UPPER_LIMIT, size);

		CheckArrayElement(b, size);

		free(b);
		ReleaseArray(Array);
	}
	printf("\n");
#endif
	return 0;
} 

