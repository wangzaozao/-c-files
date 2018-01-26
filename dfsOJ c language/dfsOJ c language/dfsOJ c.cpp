#include<stdio.h>
#include<string.h>
char str[100][20];
int vis[300], i;
int flag = 0;
void dfs(char* use)
{
	char last = use[strlen(use) - 1];
	for (int k = 0; k < i; k++)
	{
		if (vis[k] == 0 && str[k][0] == last)
		{
			vis[k] = 1;
			if (str[k][strlen(str[k]) - 1] == 'm')
			{
				flag = 1;
				return;
			}
			else
				dfs(str[k]);
		}
	}
}
int main()
{
	while (gets(str[i]))
	{
		if (strcmp(str[i], "0") == 0)//字符串比较函数，若相同函数返回0
		{
			memset(vis, 0, sizeof(vis));
			flag = 0;
			for (int j = 0; j < i; j++)
			{
				if (str[j][0] == 'b')
				{
					vis[j] = 1;
					dfs(str[j]);
				}
			}
			i = 0;
			if (flag == 1)
				printf("Yes.\n");
			else
				printf("No.\n");
		}
		else
			i++;
	}
	return 0;
}