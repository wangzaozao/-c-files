#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
int m[100][100];
int string_compare(char*t,char*p)
{
	unsigned int i, j,mini=10000;
	char t1[100] = " ";
	char p1[100] = " ";
	strcat_s(t1, t);
	strcat_s(p1, p);
	for (i = 0; i < strlen(t1); i++)
	{
		for (j = 0; j < strlen(p1); j++)
		{
			if (i == 0 && j == 0)
				m[i][j] = 0;
			else if (i == 0 && j != 0)
				m[i][j] = j;
			else if (i != 0 && j == 0)
				m[i][j] = i;
			else
			{
				if (t1[i] == p1[j])
					mini = m[i - 1][j - 1];
				else
					mini = m[i - 1][j - 1] + 1;
				if (mini > (min(m[i - 1][j] + 1, m[i][j - 1] + 1)))
					m[i][j] = min(m[i - 1][j] + 1, m[i][j - 1] + 1);
				else
					m[i][j] = mini;
			}
		}
	}
	return m[i-1][j-1];//×¢ÒâÊÇi-1,j-1
};
int main()
{
	char t[] = "you should not a dog";
	char p[] = "thou shalt not a cat";
	int n=string_compare(t, p);
	printf("%d\n", n);
	system("pause");
	return 0;
}