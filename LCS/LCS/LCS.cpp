#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
int string_lcs(char*p,char*t)
{
	unsigned int i, j;
	int m[100][100];
	char p1[100] = " ";
	char t1[100] = " ";
	strcat_s(p1, p);
	strcat_s(t1, t);
	for (i = 0; i < strlen(p1); i++)
	{
		for (j = 0; j < strlen(t1); j++)
		{
			if (i == 0 || j == 0)
				m[i][j] = 0;
			else if (p1[i] == t1[j])
				m[i][j] = m[i - 1][j - 1] + 1;
			else if (m[i - 1][j]>m[i][j - 1])
				m[i][j] = m[i - 1][j];
			else
				m[i][j] = m[i][j - 1];
		}
	}
	return m[i - 1][j - 1];
}
int main()
{
	char p[100] = "ABCBDABAB";
	char t[100] = "BDCABAAB";
	int n = string_lcs(p, t);
	printf("%d\n", n);
	system("pause");
	return 0;
}