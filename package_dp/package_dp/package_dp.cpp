//0-1背包问题其实就是判断第k个元素要不要加进去
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void package_dp(int*v,int*w,int n,int total)
{
	int i, j,temp1,temp2;
	int **c = (int **)malloc((n + 1)*sizeof(int *));
	for (i = 0; i<n + 1; i++)
		c[i] = (int *)malloc((total + 1)*sizeof(int));
	for (j = 0; j <= total; j++)
		c[0][j] = 0;
	for (i = 0; i <= n; i++)
		c[i][0] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= total; j++)
		{
			if (w[i]>j)
				c[i][j] = c[i - 1][j];
			else
			{
				temp1 = v[i] + c[i - 1][j - w[i]];
				temp2 = c[i - 1][j];
				if (temp1 >= temp2)
					c[i][j] = temp1;
				else
					c[i][j] = temp2;
			}
		}
	}
	printf("c[%d][%d]:%d\n", n, total,c[n][total]);
}
int main() {
	int v[] = { 0, 10, 25, 40, 20, 10 };
	int w[] = { 0, 40, 50, 70, 40, 20 };
	int total = 140;
	package_dp(v, w, sizeof(v) / sizeof(int)-1, total);
	system("pause");
	return 0;
}