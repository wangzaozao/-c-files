#include<stdio.h>
#include<stdlib.h>
int a[10], vis[10] = { 0 };
int count=0;
int k;//表示输入的数据
int sum(int x,int y)
{
	int i, s = 0;
	for (i = x; i <= y; i++)
	{
		s = s*10 + a[i];
	}
	return s;
}
void judge()
{
	int i, j, x, y, z;
	for (i = 1; i<8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			x = sum(1, i);
			y = sum(i + 1, j);
			z = sum(j + 1, 9);
			if ((k - x)*z == y)
				count++;
		}
	}
}
void dfs(int x)
{
	int i;
	if (x > 9)
		judge();
	for (i = 1; i <= 9; i++)
	{
		if (vis[i] == 0)
		{
			vis[i] = 1;
			a[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &k);
	dfs(1);
	printf("%d\n", count);
	system("pause");
	return 0;
}