/**************************************************************
 * 二元搜索bsearch. 搜索前必需排序,采用qsort()
 *
 * author: 	gaochao
 * email:	gaoc@dsp.ac.cn
 * date:	2007/05/27
 *************************************************************/

#define NMEMB 7
#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b)
{
	int *aa=(int *)a, *bb=(int *)b;
	if(*aa > *bb)	
		return 1;
	else if(*aa == *bb) 	
		return 0;
	else 	
		return -1;
}

int main()
{
	int base[NMEMB]={3,102,5,-2,98,52,18};
	int i;
	for (i=0; i<NMEMB;i++)
		printf("%d\t", base[i]);
	printf("\n");

	qsort(base, NMEMB, sizeof(int), compar);

	for (i=0; i<NMEMB;i++)
		printf("%d\t", base[i]);
	printf("\n");
	return 0;
}
