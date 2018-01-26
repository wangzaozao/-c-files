#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#define mod 1000000007
using namespace std;
long long sum = 0;
int x,y;
int a[1001],v[1001];
void jude(void)
{
	int i, j;
	for (i = 2; i <= x; i++)
	if (a[i]<a[i-1])
		return;
	sum++;
}
void dfs(int n)
{
	int i;
	if (n>x)
		jude();
	for (i = 1; i <= x; i++)
	if (v[i])
	{
		v[i] = 0;
		a[n] = i;
		dfs(n + 1);
		v[i] = 1;
	}
}
int main(void)
{
	int i;
	int T;
	int N, M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		sum = 0;
		x = min(N, M);
		y = max(N, M);

		for (i = 0; i <= y; i++)
			v[i] = 1;
		dfs(1);
		sum = sum%mod;
		printf("%I64d\n", sum);
	}
	return 0;
}

