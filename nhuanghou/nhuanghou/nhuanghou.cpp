#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int *a, *v;//��̬����Ķ�ά�����������ȫ�ֻ�
int n, count = 0;
void judge()
{
	int i, j;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (abs(j - i) == abs(a[j] - a[i]))
				return;
		}
	}
	count++;
}
void dfs(int x)
{
	int i;
	if (x > n)
		judge();
	for (i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			v[i] = 1;
			a[x] = i;
			dfs(x+1);
			v[i] = 0;
		}
	}
};
int main()
{
	int i;
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*(n+1));
	v = (int*)malloc(sizeof(int)*(n + 1));
	for (i = 1; i <= n; i++)
		v[i] = 0;
	dfs(1);
	printf("%d\n", count);
	system("pause");
	return 0;
}