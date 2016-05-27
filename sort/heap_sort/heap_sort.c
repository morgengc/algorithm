/************************************************************
 * Heap Sort.
 *
 * It uses the solution of "Introduction to Algorithms" v2.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // must link -lm.

#ifdef VERIFIER
#include "verifier.h"
#endif

int PARENT(int i) 
{
	return (int)floor(i/2); 
}

int LEFT(int i)
{
	return 2*i; 
}

int RIGHT(int i)
{
	return 2*i+1; 
}

void MAX_HEAPIFY(int A[], int i, int heap_size) 
{
	int largest;
	int temp;

	int l = LEFT(i);
	int r = RIGHT(i);

	if((l<heap_size) && (A[l]>A[i]))
		largest = l; 
	else
		largest = i; 

	if((r<heap_size) && (A[r]>A[largest]))
		largest = r; 

	if(largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp; 
		MAX_HEAPIFY(A, largest, heap_size); 
	}
}

void BUILD_MAX_HEAP(int A[], const unsigned int heap_size)
{
	int i = heap_size;
	for(; i >= 0;i--)
	{
		MAX_HEAPIFY(A, i, heap_size); 
	} 
}

void HEAPSORT(int A[], const unsigned int heap_size)
{
	int temp = 0;
	int this_heap_size = heap_size;
	int i = this_heap_size - 1;

	BUILD_MAX_HEAP(A, this_heap_size);

	for(; i >= 1; i--)
	{ 
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		this_heap_size--;
		MAX_HEAPIFY(A, 0, this_heap_size); 
	}
}

void printArray(int A[], const unsigned int size)
{
	int i = 0;
	printf("\n");
	for (; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
#ifndef VERIFIER
	int A[] = {3, 1, 10, -2, 16, 4, 7, 9, 0, 2, 8, 5, 11, 90, 25, 33};
	unsigned int n = sizeof(A)/sizeof(int);
	
	printArray(A, n);

	HEAPSORT(A, n);

	printArray(A, n); 
#else
	int *Array = NULL;
	int size = 0;
	int test_case = 0;
	for (; test_case<MAX_TEST_CASE; test_case++)
	{
		Array = FillArray(&size);
		if (!Array)
			return 0;

		HEAPSORT(Array, size);

		CheckArrayElement(Array, size);

		ReleaseArray(Array);
	}
	printf("\n");

#endif

	return 0;
}

