#include<stdio.h>
#include<stdlib.h>

#define M 40
void PartionGet(int s,int e,int*meter,int*max,int*min)
{
	int i;
	if (e - s <= 1)
	{
		if (meter[e] <= meter[s])
		{
			if (*min > meter[e])
				*min = meter[e];
			if (*max < meter[s])
				*max = meter[s];
		}
		else
		{
			if (*min > meter[s])
				*min = meter[s];
			if (*max < meter[e])
				*max = meter[e];
		}
		return;
	}
	i = s + (e - s) / 2;
	PartionGet(s, i, meter, max, min);
	PartionGet(i+1, e, meter, max, min);
}
int main()
{
	int meter[M],i;
	int max = INT_MIN;
	int min = INT_MAX;
	printf("The array's element as followed:\n\n");
	rand();
	for (i = 0; i < M; i++)
	{
		meter[i] = rand() % 10000;//随机生成四位数数字存入数组
		if ((i + 1) % 10 == 0)
		{
			printf("%d\n", meter[i]);
		}
		else
		{
			printf("%d ", meter[i]);
		}
	}
	PartionGet(0, M - 1, meter, &max, &min); /* 分治法获取最值 */
	printf("\nMax : %d\nMin : %d\n", max, min);
	system("pause");
	return 0;
}