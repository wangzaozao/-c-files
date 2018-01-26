//DFS模板题 HDU 1181

#include <iostream>
#include <string.h>
#include <queue>
#include <string>
using namespace std;
string str[300];
int vis[300], i;//标记数组，在一条路径中，被查找过的节点不能被再次查找，不然就会使路径出现循环
int flag = 0;//用于判定搜索是否查找到路径
void dfs(string use)
{
	char last = use[use.length() - 1];//标记字符串结尾的字符
	//if (flag == 1)//如果已经找到了就直接结束，减少不必要的搜索过程
	//	return;     //这道题不必要
	for (int k = 0; k<i; k++)//如果视当前use字符串为当前节点，那么for循环就应该遍历下一层的所有可能节点
	{
		if (vis[k] == 0 && str[k][0] == last)//如果未被访问，且其首字符合本节点末字符匹配，就可以作为搜索树的分支节点
		{
			vis[k] = 1;//每确定路径中的一个节点，就标记起来
			if (str[k][str[k].length() - 1] == 'm')//满足搜索的结束条件就设置flag并退出
			{
				flag = 1;
				return;
			}
			else
				dfs(str[k]);//否则继续向下搜索
			//vis[k]=0
			//大部分DFS在一条路径搜索失败后都需要回溯到上一状态
			//通常需要把从本节点后产生的标记都重置
			//实际上是否需要重置标记，应该看路径来源是否会对节点能否到达出口产生影响
			//在本题中。如果str[k]是到所求路径中的一个节点，不管从什么途径搜索到了str[k]，都不影响他到达终点。
		}
	}
}
int main() {

	while (cin >> str[i])
	{
		if (str[i] == "0")
		{
			memset(vis, 0, sizeof(vis));
			flag = 0;
			for (int j = 0; j<i; j++)
			{
				if (str[j][0] == 'b')//如果满足起始条件就进入搜索过程
				{
					vis[j] = 1;
					dfs(str[j]);
				}
			}
			i = 0;//有多组测试样例，每完成一组，重置i
			if (flag == 1)
				cout << "Yes." << endl;
			else
				cout << "No." << endl;
		}
		else
			i++;
	}
	return 0;
}