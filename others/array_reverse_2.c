#include <stdio.h>
#include <stdlib.h>

int hashf(int index) 
{
	// 返回 index处在调整后应该放的元素的下标
	if( index < 3 )
		return(5 - 3 + index);
	else
		return(index - 3);
}

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

int main()
{
	int a[5] = {1,2,3,4,5};
	int tempi, swap, i=0;

	disp_array(a, 5);

	for(; i<5; i++)
	{
		tempi = hashf(i);

		//若 tempi小于i ，说明要交换的位置的元素已经调整过
		//则，进行再次哈希，直到找到要交换的位置。
		while( tempi < i)
		{ 
			tempi = hashf( tempi);
		}
		swap = a[i];
		a[i] = a[tempi];
		a[tempi] = swap;
	}

	disp_array(a, 5);
	return 0;
}

