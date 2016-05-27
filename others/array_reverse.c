//问题描述：
//整型数组a[] 大小N，设计一个算法将数组后面M（M<N）个数
//移到数组的前面 ，例如a＝{1,2,3,4,5}，M＝3，则移动后
//应该是a={3,4,5,1,2}。要求用时间复杂度O（n），空间复杂度
//O(1) 
//
//解决方案：
//先翻转前面N-M个元素，再翻转后面M个元素，再翻转全部.
//{1,2,3,4,5} --> {2,1,3,4,5} --> {2,1,5,4,3} --> {3,4,5,1,2}
//

#include <stdio.h>
#include <stdlib.h>

void disp_array(int a[], int n)
{
	int i = 0;
	printf("{");
	for(; i<n-1; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("%d", a[i]);
	printf("}\n");

}

void array_reverse(int a[],int n,int m)
{
	if(m==0||m==n) 
		return;

	int blockSize = n - m;
	int buf = 0, i = 0;

	disp_array(a, n);

	for(;i<blockSize/2;i++) 
	{
		buf=a[i];
		a[i]=a[blockSize-1-i];
		a[blockSize-1-i]=buf;
	}

	disp_array(a, n);

	for(i=blockSize;i<blockSize+m/2;i++) 
	{
		buf=a[i];
		a[i]=a[blockSize+n-1-i];
		a[blockSize+n-1-i]=buf;
	}

	disp_array(a, n);

	for(i=0;i<n/2;i++) 
	{
		buf=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=buf;
	}

	disp_array(a, n);
}

int main()
{
	int a[5] = {1,2,3,4,5};

	array_reverse(a, 5, 3);

	return 0;
}

