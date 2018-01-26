#include <stdio.h>
#include<stdlib.h>
#include<algorithm>
#define MAXN 9
#define MAXINT 32767

using namespace std;
void print_books(int s[], int start, int end)
{
	int i;
	for (i = start; i <= end; i++)
		printf(" %d ", s[i - 1]);
	printf("\n");
	return;
}
int reconstruct_partition(int *s, int d[MAXN + 1][MAXN + 1], int n, int k)
{
	if (k == 1)
		print_books(s, 1, n);
	else
	{
		reconstruct_partition(s, d, d[n][k], k - 1);//递归，需要仔细体会
		print_books(s, d[n][k] + 1, n);//看不懂时可以把这行注释一下看看打印的结果
	}
	return 0;
}
void partition(int*s,int n,int k)
{
	int i, j,cost;
	int p[MAXN + 1];
	int m[MAXN + 1][MAXN + 1], d[MAXN + 1][MAXN + 1];
	p[0] = 0;
	for (i = 1; i <= n; i++)
		p[i] = p[i - 1] + s[i - 1];
	for (i = 1, j = 1; j <= k; j++)
		m[i][j] = s[0];
	for (i = 1, j = 1; i <= n; i++)
		m[i][j] = p[i];
	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= k; j++)
		{
			m[i][j] = MAXINT;
			for (int x = 1; x <= i - 1; x++)
			{
				cost = max(m[x][j - 1], p[i]-p[x]);
				if (m[i][j] > cost)
				{
					m[i][j] = cost;
					d[i][j] = x;
				}
			}
		}
	}
	reconstruct_partition(s, d, n, k);
}

int main() {
	int a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int b[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("first:\n");
	partition(a, 9, 3);
	printf("\nsecond:\n");
	partition(b, 9, 3);
	system("pause");
	return 0;
}