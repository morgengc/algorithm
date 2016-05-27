/**************************************************************
 * 线性搜索lfind, lsearch. 未搜索到,前者返回NULL,后者会追加.
 * 需要包含头文件<search.h>
 *
 * bsearch只需要包含<stdlib.h>
 *
 * author: 	gaochao
 * email:	gaoc@dsp.ac.cn
 * date:	2007/05/27
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define NMEMB 5
#define SIZE 10


int compar (const void *a, const void *b)
{
	return (strcmp((char *) a, (char *) b));
}

int main()
{
	char data[50][SIZE]=
	{
		"freebsd",
		"linux",
		"solaris",
		"sunos",
		"windows",
		"hello"
	};
	char key[80],*base,*offset;
	int i, nmemb=NMEMB,size=SIZE;

	while(1)
	{
		printf(">");
		fgets(key,sizeof(key),stdin);
		key[strlen(key)-1]='\0';

		if(!strcmp(key,"exit"))
			break;
		if(!strcmp(key,"list"))
		{
			// 这里打印出来的,并没有按照从小到大的顺序排列
			// 莫非qsort()并没有影响原数据排列,而维持了一个备份?
			for(i=0;i<nmemb;i++)
				printf("%s\n", data[i]);
			continue;
		}

		base = data[0];
		// lfind找不到就返回NULL
		offset = (char *)lfind(key,base,(size_t *)&nmemb,size,compar);
		if(offset ==NULL)
		{
			printf("%s not found!\n", key);
			// lsearch找不到就追加
			offset=(char *) lsearch(key,base,(size_t *)&nmemb,size,compar);
			printf("Add %s to data array\n", offset);
		}
		else
		{
			printf("found: %s, offset %d\n", 
					offset,
					(offset-base)/(size*sizeof(char)));
		}
	}

	return 0;
}

