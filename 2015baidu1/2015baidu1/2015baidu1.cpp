#include<stdio.h>
#include<stdlib.h>
#define maxn 1000000
#define mod 1000000007
long long dp[maxn];
int main()
{
	int T,N,i;
	scanf("%d", &T);
	dp[1] = 1;
	dp[2] = 2;
	for (i = 3; i <= maxn; i++)
	{
		dp[i] = (dp[i - 2] * (i - 1) + dp[i - 1]) % mod;
	}
	i = 1;
	while (T--)
	{
		scanf("%d", &N);
		printf("Case #%d:\n", i++);
		printf("%d\n", dp[N]);
	}
	system("pause");
	return 0;
}