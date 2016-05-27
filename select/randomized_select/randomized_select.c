#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LEN 1000

static int srcount = 0;

int RANDOM(int p, int r)
{
	if (srcount == 0)
		srand((unsigned)time(0));
	else
		srcount = 1;

	return rand()%(r-p+1)+p; 
}

int PARTITION(int arr[LEN], int p, int r)
{ 
	int x, i, j, t;
	x = arr[r];
	i = p-1;
	for(j=p; j<r; j++)
	{
		if(arr[j] <= x)
		{
			++i;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t; 
		}
	}
	t = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = t;

	return i+1; 
}

int RANDOMIZED_PARTITION(int arr[LEN], int p, int r)
{
	int i, t;
	i = RANDOM(p, r);
	t = arr[i];
	arr[i] = arr[r];
	arr[r] = t;

	return PARTITION(arr, p, r);
}

/*求中位点*/
int RANDOMIZED_SELECT(int arr[LEN], int p, int r, int i)
{
	int q, k;

	if(p==r) 
		return arr[p];

	q = RANDOMIZED_PARTITION(arr, p, r);
	k = q-p+1;

	if(i==k) 
		return arr[q];
	else if(i<k)
		return RANDOMIZED_SELECT(arr, p, q-1, i);
	else 
		return RANDOMIZED_SELECT(arr, q+1, r, i-k);
}

int main()
{
	int arr[] = {2, 2, 3, 0, 3, 9, 1, 10, 20};
	int size = sizeof(arr)/sizeof(int);

	printf("%d\n", RANDOMIZED_SELECT(arr, 0, size-1, 2));

	/* after selected, arr is not ordered! */
	int i = 0;
	for(i=0; i<size; i++)
		printf("%5d", arr[i]);
	printf("\n");

	return 0;
}

