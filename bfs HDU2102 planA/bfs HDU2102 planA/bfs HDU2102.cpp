#include <iostream>   
#include <cstring> 

using namespace std;
#define MAXN 12
int M, N, T;
char a[MAXN][MAXN][MAXN];//输入的总地图
struct direction
{
	int y;
	int z;
};
typedef struct node
{
	int x, y, z, level;
}Node;
Node queue[10000];
int front = 0, rear = 0;
struct direction direct[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int bfs()
{
	Node start, f;
	start.x = 0;
	start.y = 1;
	start.z = 1;
	start.level = 0;
	queue[rear++] = start;
	while (front != rear)
	{
		f = queue[front++];
		if (a[f.x][f.y][f.z] == 'P')
			return 1;
		else if (a[f.x][f.y][f.z] == '*')
			continue;
		a[f.x][f.y][f.z] = '*';
		Node v;
		for (int i = 0; i < 4; i++)
		{
			v.x = f.x;
			v.y = f.y + direct[i].y;
			v.z = f.z + direct[i].z;
			v.level = f.level + 1;
			if (v.level>T)
				break;//可以return？
			if (a[v.x][v.y][v.z] == '*')
				continue;
			if (a[v.x][v.y][v.z] == '#')
			{
				v.x = 1 - v.x;
				if (a[v.x][v.y][v.z] == '#' || a[v.x][v.y][v.z] == '*')
				{
					a[v.x][v.y][v.z] = '*';
					a[1 - v.x][v.y][v.z] = '*';
					continue;
				}
			}
			queue[rear++] = v;
		}
	}
	return 0;
}
int main()
{
	int t, ans;

	cin >> t;
	while (t--) {
		cin >> M >> N >> T;
		front = 0;
		rear = 0;
		memset(a, '*', sizeof(a));

		for (int i = 0; i<2; i++)
		for (int j = 1; j <= M; j++)
		for (int k = 1; k <= N; k++)
			cin >> a[i][j][k];

		ans = bfs();

		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
