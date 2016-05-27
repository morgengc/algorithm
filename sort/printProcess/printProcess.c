/************************************************
 * Print Sort Process Step by Step.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.09
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "printProcess.h"

#define cNO "\033[00m"     // 还原
#define cFR "\033[01;31m"  // 红色前景
#define cFG "\033[01;32m"  // 绿色前景
#define cFY "\033[01;33m"  // 黄色前景
#define cFB "\033[01;34m"  // 兰色前景
#define cFM "\033[01;35m"  // 艳红前景
#define cFC "\033[01;36m"  // 浅兰前景
#define cFL "\033[01;37m"  // 亮白前景

#define cBR "\033[01;41m"  // 红色背景
#define cBG "\033[01;42m"  // 绿色背景
#define cBY "\033[01;43m"  // 黄色背景
#define cBB "\033[01;44m"  // 兰色背景
#define cBM "\033[01;45m"  // 艳红背景
#define cBC "\033[01;46m"  // 浅兰背景
#define cBL "\033[01;47m"  // 亮白背景

void printProcess(int A[], const unsigned int size, unsigned int colorposition)
{
	int i = 0;
	if (colorposition == 0)
	{
		printf("%s%d %s", cFR, A[colorposition], cNO);
		printf("%s%d %s", cFG, A[colorposition+1], cNO);
		i++;
	}
	else if (colorposition == size-1)
	{
		for (i=0; i<colorposition; i++)
			printf("%d ", A[i]);

		printf("%s%d %s", cFR, A[colorposition], cNO);
	}
	else
	{
		for (i=0; i<colorposition; i++)
			printf("%d ", A[i]);

		printf("%s%d %s", cFR, A[colorposition], cNO);
		printf("%s%d %s", cFG, A[colorposition+1], cNO);
		i++;
	}

	for (i++; i<size; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

#if 0
	sleep(1000);
	fflush(stdout);
#endif
}

