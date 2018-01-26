#include <stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

char s[maxn];
int dp[maxn];

int solve1(int len, char s[]) {
	int Max = 0;
	for (int i = 0; i < len; i++)
		dp[i] = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] == ')') {
			int j = i - 1 - dp[i - 1];
			if (j >= 0 && s[j] == '(') {
				dp[i] = dp[i - 1] + 2;
				if (j - 1 >= 0)
					dp[i] += dp[j - 1];
			}
		}
		if (Max < dp[i]) Max = dp[i];
	}
	return Max;
}

int solve2(int len, char s[]) {
	int Max = 0;
	for (int i = 0; i < len; i++)
		dp[i] = 0;
	for (int i = len - 2; i >= 0; i--) {
		if (s[i] == '(') {
			int j = i + 1 + dp[i + 1];
			if (j < len && s[j] == ')') {
				dp[i] += dp[i + 1] + 2;
				if (j + 1 < len)
					dp[i] += dp[j + 1];
			}
			if (Max < dp[i]) Max = dp[i];

		}
	}
	return Max;
}

int main(){
	scanf("%s", s);
	int len = strlen(s);
	printf("%d\n", solve1(len, s));
	system("pause");
	return 0;
}