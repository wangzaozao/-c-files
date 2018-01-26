#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
int string_lis(int*p)
{
	unsigned int i, j;
	int len[100],maxlen=1;

	for (i = 0; i<30; i++)
	{
		len[i] = 1;
	}
	for (i = 0;i<30; i++)//竟然不能写成p[i]!='\0'和整数数组中的0冲突
	{
		for (j = 0; j < i; j++)
		{
			if (p[i]>p[j] && len[i] < len[j] + 1)
			{
				len[i] = len[j] + 1;
				if (maxlen < len[i])
					maxlen = len[i];
			}
		}
	}
	return maxlen;
}
int main()
{
	int p[100] = { 1, -1, 2, 3, 12, 14,0, 23, 29, 1, 25, 67, 34, 7, 8, 9, 10, 11, 12, 13, 14 };
	int n = string_lis(p);
	printf("%d\n", n);
	system("pause");
	return 0;
}