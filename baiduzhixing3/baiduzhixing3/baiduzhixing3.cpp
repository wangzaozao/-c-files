#include<stdio.h>
#include<string.h>
struct BigNum
{
	int s[1000];
	int so;
	BigNum Add(BigNum b)
	{
		BigNum ret;
		memset(ret.s, 0, sizeof(ret.s));
		ret.so = 0;
		int i;
		for (i = 0; i<so&&i<b.so; i++)
		{
			ret.s[i] += s[i] + b.s[i];
			if (ret.s[i] >= 10)
			{
				ret.s[ret.so] -= 10;
				ret.s[++ret.so] = 1;
			}
			else ret.so++;
		}
		for (; i<so; i++)
		{
			ret.s[i] = s[i] + ret.s[i];
			if (ret.s[i] >= 10)
			{
				ret.s[ret.so] -= 10;
				ret.s[++ret.so] = 1;
			}
			else ret.so++;
		}
		//for (; i<b.so; i++)
		//{
		//	ret.s[i] = b.s[i] + ret.s[i];
		//	if (ret.s[i] >= 10)
		//	{
		//		ret.s[ret.so] -= 10;
		//		ret.s[++ret.so] = 1;
		//	}
		//	else ret.so++;
		//}
		if (ret.s[ret.so] != 0) ret.so++;
		return ret;
	}
	void get()
	{
		for (int i = so - 1; i >= 0; i--)
		{
			printf("%d", s[i]);
		}
	}
};
BigNum dp[210];
int main()
{
	dp[1].so = 1;
	dp[1].s[0] = 1;
	dp[2].so = 1;
	dp[2].s[0] = 2;
	for (int i = 3; i<201; i++)
	{
		dp[i] = dp[i - 1].Add(dp[i - 2]);
	}
	int n;
	while (scanf("%d", &n) != EOF)
	{
		dp[n].get();
		printf("\n");
	}
	return 0;
}
