#include<stdio.h>
#include<string.h>
#include<map>
#include <algorithm>
using namespace std;

struct Node
{
	char s[35];
	int l, r;
	bool flag;
};

Node a[1010][35];
int ao[1010];
bool ff[1010];
map<string, int> m[1010];

int mo;
void solve(int pos, char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] <= 'z'&&s[i] >= 'a')
		{
			char t[35];
			int j;
			for (j = i; s[j]; j++)
			{
				if (s[j] <= 'z'&&s[j] >= 'a') t[j - i] = s[j];
				else break;
			}
			t[j - i] = 0;
			int to;
			if (m[pos].find(t) == m[pos].end())
			{
				m[pos][t] = ++mo;
				strcpy(a[pos][mo].s, t);
				a[pos][mo].l = -10000;
				a[pos][mo].r = 10000;
				a[pos][mo].flag = 1;
				to = mo;
				ao[pos] = mo;
			}
			else to = m[pos][t];
			int flag = 0;
			for (; s[j]; j++)
			{
				if (s[j] == '<'&&s[j + 1] == '=') flag = 2;
				else if (s[j] == '<') flag = 1;
				else if (s[j] == '>'&&s[j + 1] == '=') flag = 4;
				else if (s[j] == '>') flag = 3;
				else if (s[j] == '='&&s[j + 1] == '=') flag = 5;
				if (flag != 0) break;
			}
			int k = 0, fu = 1;
			for (j++; s[j]; j++)
			{
				if (s[j] == '-')
				{
					fu = -1;
				}
				else if (s[j] <= '9'&&s[j] >= '0')
				{
					k = k * 10 + s[j] - '0';
				}
				else if (s[j] == ',') break;
			}
			k = k*fu;
			if (flag == 1) k--;
			else if (flag == 3) k++;
			if (flag == 1 || flag == 2)
			{
				a[pos][to].r = min(k, a[pos][to].r);
			}
			else if (flag == 3 || flag == 4)
			{
				a[pos][to].l = max(k, a[pos][to].l);
			}
			else if (flag == 5)
			{
				if (a[pos][to].l>k || a[pos][to].r<k) a[pos][to].flag = 0;
				else
				{
					a[pos][to].l = k;
					a[pos][to].r = k;
				}
			}
			if (a[pos][to].l>a[pos][to].r) a[pos][to].flag = 0;
			if (a[pos][to].flag == 0) ff[pos] = 1;
			i = j - 1;
		}
	}
}

int main()
{
	int n;
	char s[100];
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		memset(ff, 0, sizeof(ff));
		for (int i = 0; i<n; i++)
		{
			mo = 0;
			gets(s);
			solve(i, s);
		}
		for (int i = 0; i<n; i++)
		{
			bool flag = 0;
			for (int u = 0; u<i; u++)
			{
				if (ff[i] == 1) continue;
				if (ff[u] == 1) continue;
				int j;
				for (j = 1; j <= ao[i]; j++)
				{
					int pos = m[u][a[i][j].s];
					if (pos == 0) break;
					if (a[i][j].r<a[u][pos].l || a[i][j].l>a[u][pos].r);
					else break;
				}
				if (j>ao[i]);
				else
				{
					if (flag == 1) printf(" ");
					flag = 1;
					printf("%d", u + 1);
				}
			}
			if (flag == 0) printf("unique\n");
			else printf("\n");
		}
	}
	return 0;
}

