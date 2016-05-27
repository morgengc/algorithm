#include <stdio.h>
#include <stdlib.h>

#define BUCKET_NUM 10 /*10个桶*/

void insertion_sort(int array[], unsigned int n)
{
	int i,j;
	int temp;
	for(i=1; i<n; i++)
	{
		//store the original sorted array in temp
		temp = array[i];

		//compare the new array with temp
		for(j=i; (j>0) && (temp < array[j-1]); j--)
		{
			//all larger elements are moved one pot to the right
			array[j] = array[j-1];
		}
		array[j] = temp;
	}
}

/*
 * 暂时用数组替代链表
 * d: 元素位数
*/
void bucket_sort(int *array, int length, int d)
{
	int **list_array = NULL, i, j, base, index;

	list_array = (int **)malloc(sizeof(int) * BUCKET_NUM);  

	for(i=0; i<BUCKET_NUM; i++)
	{
		list_array[i] = (int *)malloc(sizeof(int)*(length+1));
		list_array[i][length] = 0;  /*用最后一个元素记录桶中元素个数*/
	}

	base = 1;
	for(i=1; i<d; i++)
		base *= BUCKET_NUM;

	for(i=0; i<length; i++)
	{
		index = array[i]/base;
		list_array[index][list_array[index][length]] = array[i];
		list_array[index][length]++;
	}

	index = 0;

	for(i=0; i<BUCKET_NUM; i++)
	{   
		insertion_sort(list_array[i], list_array[i][length]);

		for(j=0; j<list_array[i][length]; j++)
			array[index++] = list_array[i][j];

		free(list_array[i]);
		list_array[i] = NULL;
	}

	free(list_array);
	list_array = NULL;
}

int main()
{
	int input[] = {23,4,56,12,13,11,19,7,5,6,3,7,32,-1};
	int n = sizeof(input)/sizeof(int);
	int i;

	bucket_sort(input, n, 2);

	for(i=0; i<n; i++)
		printf("%d ", input[i]);
	printf("\n");
	return 0;
} 

