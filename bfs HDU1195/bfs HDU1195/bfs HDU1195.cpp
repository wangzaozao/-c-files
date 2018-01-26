#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 4

typedef struct node
{
	char num[MAXN + 1];
	int a;
	int level;
}Node,*PNode;
Node start;
Node queue[10000];//10000就够了，因为最多只有9*9*9*9个数字
int b;
int front=0, rear = 0;
int notvist[10000];
int myatoi(char*s)
{
	int m=0;
	while (*s)//因为此题中四位数没有0，所以可以这么用
	{
		m = m * 10 + *s;
		s++;
	}
	return m;
}
int bfs()
{
	int i, temp = start.a;
	for (i=MAXN-1; i >=0; i--)
	{
		start.num[i] = temp % 10;
		temp = temp / 10;
	}
	start.num[MAXN] = '\0';
	start.level = 0;
	memset(notvist, 1, sizeof(notvist));
	queue[rear++] = start;
	notvist[start.a] = 0;
	while (rear != front)
	{
		Node front1 = queue[front++];
		if (front1.a == b)
		{
			return front1.level;
		}
		Node v;

		//exchange
		for (i = 0; i < MAXN - 1; i++)
		{
			strcpy(v.num, front1.num);
			int t = v.num[i];
			v.num[i] = v.num[i + 1];
			v.num[i + 1] = t;
			v.a = myatoi(v.num);
			if (notvist[v.a])
			{
				notvist[v.a] = 0;
				v.level = front1.level + 1;
				queue[rear++] = v;
			}
		}

		//plus 1
		for (i = 0; i < MAXN; i++)
		{
			strcpy(v.num, front1.num);
			v.num[i]++;
			if (v.num[i] == 10)
				v.num[i] = 1;
			v.a = myatoi(v.num);
			if (notvist[v.a])
			{
				notvist[v.a] = 0;
				v.level = front1.level + 1;
				queue[rear++] = v;
			}
		}

		//minus 1
		for (i = 0; i < MAXN; i++)
		{
			strcpy(v.num, front1.num);
			v.num[i]--;
			if (v.num[i] == 0)
				v.num[i] = 9;
			v.a = myatoi(v.num);
			if (notvist[v.a])
			{
				notvist[v.a] = 0;
				v.level = front1.level + 1;
				queue[rear++] = v;
			}
		}
	}
	return 0;
}
int main()
{
	int x,ans;
	scanf("%d", &x);
	while (x--)
	{
		front = 0;
		rear = 0;
		scanf("%d", &start.a);
		getchar();
		scanf("%d", &b);
		ans = bfs();
		printf("%d\n", ans);
	}
//	system("pause");
	return 0;
}