#include<stdio.h>
char s[100010];
int a[100010];
int exGcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = exGcd(b, a%b, x, y);
	int t = x;
	x = y;
	y = t - a / b*y;
	return r;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%s", s + 1);
		a[0] = 1;
		for (int i = 1; s[i]; i++)
		{
			a[i] = a[i - 1] * (s[i] - 28) % 9973;
		}
		int x, y;
		while (n--)
		{
			scanf("%d%d", &x, &y);
			int l, r;
			exGcd(a[x - 1], 9973, l, r);
		//	l = (l % 9973 + 9973) % 9973;
			printf("%d\n", a[y] * l % 9973);
		}
	}
	return 0;
}

