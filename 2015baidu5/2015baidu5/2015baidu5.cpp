#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
#define maxn 1100
#define inf 0x7fffffff
int dir[8][2] = { { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 } };
typedef struct node
{
	int x;
	int y;
}p;
int n, m, k;
int cnt[maxn][maxn];
int ans[maxn][maxn];
queue<p>q[2];
int bbs(int x)
{
	if (x < 0)
		return -x;
	return x;
}
int bfs()
{
	int te = 0;
	int cur = inf;
	p p1, p2;
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= k; i++)
	{
		while (!q[te].empty())
		{
			p1 = q[te].front();
			q[te].pop();
			for (int j = 0; j < 8; j++)
			{
				p2.x = p1.x + dir[j][0];
				p2.y = p1.y + dir[j][1];
				if (p2.x >= 1 && p2.x <= n&&p2.y >= 1 && p2.y <= m)
				{
					if (ans[p2.x][p2.y] == -1)
					{
						if (cnt[p2.x][p2.y] <= i)
						{
							return i;//能保证最小的时间，因为到i这个时间必然最小，如果有更短的时间早就return了
						}
						else
						{
							ans[p2.x][p2.y] = cnt[p2.x][p2.y];//到某个位置两者相遇时的最小值
							if ((cnt[p2.x][p2.y] - i) % 2)
								ans[p2.x][p2.y]++;
							cur = min(cur, ans[p2.x][p2.y]);
							q[!te].push(p2);
						}
					}
				}
			}
		}
		te = !te;//遍历下一个时刻才能到的位置
	}
	return cur;
}
int main()
{
	int t,ca=1;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		p p1;
		int x2, y2;
		scanf("%d%d", &x2, &y2);
		scanf("%d%d", &p1.x, &p1.y);
		while (!q[0].empty())
			q[0].pop();
		q[0].push(p1);
		while (!q[1].empty())
			q[1].pop();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == x2&&j == y2)
				{
					cnt[i][j] = 2;
				}
				else
				{
					cnt[i][j] = max(bbs(i - x2), bbs(j - y2));
				}
			}
		}
		int ant = bfs();
		printf("Case #%d:\n", ca++);
		if (ant == inf || ant>k)
		{
			printf("OH,NO!\n");
		}
		else
		{
			printf("%d\n", ant);
		}
	}
	system("pause");
	return 0;
}