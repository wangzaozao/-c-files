#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
void longestPalindrome(char*s)
{
	int i, j,len,maxlen=1,start=0;
	int n = strlen(s);
	int m[100][100];
	for (i = 0; i < n; i++)
	{
		m[i][i] = 1;
		if (i != n - 1)
		{
			if (s[i] == s[i + 1])
				m[i][i + 1] = 1;
			else
				m[i][i + 1] = 0;
		}
	}
	for (len = 2; len <= n - 1; len++)
	{
		for (i = 0; i + len < n; i++)
		{
			j = i + len;
			if (s[i] == s[j] && m[i + 1][j - 1] == 1)
			{
				m[i][j] = 1;
				maxlen = len + 1;
				start = i;
			}
			else
				m[i][j] = 0;
		}
	}
	printf("最大回文子串：\n");
	for (i = start; i < start + maxlen; i++)
		printf("%c ", s[i]);
}
int main()
{
	char s[] = "adffkfbfkf";
	//printf("%d\n", strlen(s));就等于原字符串长度
	longestPalindrome(s);
	system("pause");
	return 0;
}