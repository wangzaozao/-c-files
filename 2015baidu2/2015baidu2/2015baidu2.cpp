#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100100];
int main()
{
	int t,k,n;
	int cur, cnt;
	int l,ca=1;
	scanf("%d", &t);
	getchar();//换行
	while (t--)
	{
		gets(s);
		n = strlen(s);
		scanf("%d", &k);
		getchar();//
		cur = n / k;
		cnt = n%k;
		if (cnt == 0)
			cnt = k;
		else
			cur++;
		printf("Case #%d:\n", ca++);
		for (int i = 0; i < cur; i++)
		{
			for (int j = i, l = 0; j < n;)
			{
				printf("%c", s[j]);
				if (l < cnt)
				{
					j = j + cur;
				}
				else
					j = j + cur - 1;
				l++;
				if (i == cur - 1 && l == cnt)//最后一行缺数的处理
					break;
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}