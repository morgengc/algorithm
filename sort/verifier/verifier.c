/************************************************
 * Test case tool.
 *
 * Generate arrays with dynamic dimension and 
 * fill it with random elements. 
 *
 * Sorting Algorithms should call this utility
 * to test as many cases as possible.
 *
 * Call Sequence:
 *   FillArray() 
 *   -> SROTING ALGORITHMS
 *   -> CheckArrayElement()
 *   -> ReleaseArray()
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "verifier.h"

static int rcount = 0;

/* generate number [p, r) */
static int RANDOM(int p, int r)
{
	if (rcount == 0)
	{
		srand((unsigned)time(0));
		rcount = 1;
	}

	if (p >= r)
		return p;
	else
		return rand()%(r-p)+p;
}

static unsigned int GetDimension()
{
	unsigned int dim = RANDOM(1, MAX_DIMENSION);
	return dim;
}

static void printArray(int Array[], const unsigned int size)
{
	int i = 0;
	for (; i<size; i++)
		printf("%d ", Array[i]);
	printf("\n");
}

int *FillArray(unsigned int *size)
{
	unsigned int dim = GetDimension();
	int *Array = (int *)malloc(dim*sizeof(int));
	if (!Array)
	{
		perror("malloc failed.");
		return NULL;
	}
	else
	{
		int i = 0;
		for (; i<dim; i++)
		{
			Array[i] = RANDOM(0, MAX_ELEMENT); 
		}
	}

	*size = dim;

	return Array;
}

void ReleaseArray(int *Array)
{
	free(Array);
	Array = NULL;
}

/* Check "ordered" elements whether are really ordered? 
 *
 * Is there any smart algorithms to check it?
 * */
void CheckArrayElement(int Array[], const unsigned int size)
{
	static int passed = 0;
	static int err_count = 0;

	int i;
	char output[128];

	for (i=0; i<size-1; i++)
	{
		if (Array[i] > Array[i+1])
		{
			printf("[ERROR]\n");
			err_count++;
			passed--;
			printArray(Array, size);
			break;
		}
	}

	sprintf(output, "SIZE %4d, PASSED %4d, EEROR %d.", size, ++passed, err_count);

	fputs("\r", stdout);
	fputs(output, stdout);
	fflush(stdout);
}

