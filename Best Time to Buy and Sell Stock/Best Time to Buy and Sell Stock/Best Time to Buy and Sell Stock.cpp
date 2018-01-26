#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int computer(int*s)
{
	
	int i,len;
	int n = sizeof(s)/sizeof(int);
	int m[100][100];
	for (i = 0; i < n - 1; i++)
	{
		if (s[i] < s[i + 1])
			m[i][i + 1] = s[i + 1] - s[i];
		else
			m[i][i + 1] = 0;
	}
	for (len = 2; len <= n - 1; len++)
	{
		for (i = 0; i + len < n; i++)
		{
			if (s[i + len]>s[i])
				m[i][i + len] = s[i + len] - s[i];
			else
				m[i][i + len] = 0;
			if (m[i][i + len - 1] > m[i][i + len])
				m[i][i + len] = m[i][i + len - 1];
			if (m[i + 1][i + len] > m[i][i + len])
				m[i][i + len] = m[i + 1][i + len];
		}
	}
	return m[i - 1][i + len - 2];
}
int main()
{
	unsigned int i, j=0;
	int s[1000] = {0};
//	computer(s);
	char c[1000];
	scanf("%s", c);
	for (i = 1; i < strlen(c) - 1; i++)
	{
		if (c[i] != ',')
		{
			s[j] = s[j] * 10 + c[i] - '0';
		}
		else
			j++;
	}
	int a = computer(s);
	printf("%d\n", a);
	system("pause");
	return 0;
}