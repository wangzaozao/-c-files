#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 101
int notvist[MAXN][MAXN][MAXN];
typedef struct node
{
	int s;
	int n;
	int m;
	int level;
}Node;

Node queue[1000];
int front, rear;
int s, n, m, s2;
int bfs()
{
	if (s % 2 == 1)
		return -1;

	s2 = s / 2;
	memset(notvist, 1, sizeof(notvist));

	Node f;
	f.s = s;
	f.n = 0;
	f.m = 0;
	f.level = 0;

	queue[rear++] = f;
	notvist[f.s][f.n][f.m] = 0;
	while (rear != front)
	{
		f = queue[front++];
		if ((f.m == f.n&&f.m == s2) || (f.n == f.s&&f.n == s2) || (f.m == f.s&&f.m == s2))
		{
			return f.level;
		}
		Node v;
		//s-->n
		if (f.s && (n - f.n > 0))
		{
			if (f.s > n - f.n)
			{
				v.s = f.s - (n - f.n);
				v.n = n;
				v.m = f.m;
			}
			else
			{
				v.s = 0;
				v.n = f.s + f.n;
				v.m = f.m;
			}
			if (notvist[v.s][v.n][v.m])
			{
				notvist[v.s][v.n][v.m] = 0;
				v.level = f.level + 1;
				queue[rear++] = v;
			}
		}
		//s-->m
		if (f.s && (m - f.m > 0))
		{
			if (f.s > m - f.m)
			{
				v.s = f.s - (m - f.m);
				v.m = m;
				v.n = f.n;
			}
			else
			{
				v.s = 0;
				v.m = f.s + f.m;
				v.n = f.n;
			}
			if (notvist[v.s][v.n][v.m])
			{
				notvist[v.s][v.n][v.m] = 0;
				v.level = f.level + 1;
				queue[rear++] = v;
			}
		}
		//n-->s
		if (f.n && (s - f.s > 0))
		{
			if (f.n > s - f.s)
			{
				v.n = f.n - (s - f.s);
				v.s = s;
				v.m = f.m;
			}
			else
			{
				v.n = 0;
				v.s = f.n + f.s;
				v.m = f.m;
			}
			if (notvist[v.s][v.n][v.m])
			{
				notvist[v.s][v.n][v.m] = 0;
				v.level = f.level + 1;
				queue[rear++] = v;
			}
		}
		//n-->m
		if (f.n && (m - f.m > 0))
		{
			if (f.n >m - f.m)
			{
				v.n = f.n - (m - f.m);
				v.m = m;
				v.s = f.s;
			}
			else
			{
				v.n = 0;
				v.m = f.m + f.n;
				v.s = f.s;
			}
			if (notvist[v.s][v.n][v.m])
			{
				notvist[v.s][v.n][v.m] = 0;
				v.level = f.level + 1;
				queue[rear++] = v;
			}
		}
		//m-->s
		if (f.m && (s - f.s > 0))
		{
			if (f.m > s - f.s)
			{
				v.m = f.m - (s - f.s);
				v.s = s;
				v.n = f.n;
			}
			else
			{
				v.m = 0;
				v.s = f.m + f.s;
				v.n = f.n;
			}
			if (notvist[v.s][v.n][v.m])
			{
				notvist[v.s][v.n][v.m] = 0;
				v.level = f.level + 1;
				queue[rear++] = v;
			}
		}
		//m-->n
		if (f.m && (n - f.n > 0))
		{
			if (f.m > n - f.n)
			{
				v.m = f.m - (n - f.n);
				v.n = n;
				v.s = f.s;
			}
			else
			{
				v.m = 0;
				v.n = f.m + f.n;
				v.s = f.s;
			}
			if (notvist[v.s][v.n][v.m])
			{
				notvist[v.s][v.n][v.m] = 0;
				v.level = f.level + 1;
				queue[rear++] = v;
			}
		}
	}
	return -1;
}
int main()
{
	while (scanf("%d%d%d", &s, &n, &m) != EOF) {
		if (s == 0 && n == 0 && m == 0)
			break;
		front = 0;
		rear = 0;
		int ans = bfs();

		if (ans < 0)
			printf("NO\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}