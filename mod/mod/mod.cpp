#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int Kcase=0;
	int t;
	scanf("%d", &t);
	int x, m, k, c;
	int ans[10000 + 1];
	int top,sum;
	int i,l;
	bool flag,flag_end;
	while (t--)
	{
		scanf("%d%d%d%d", &x, &m, &k, &c);
		ans[1] = x; top = 1; sum = x; flag = false;
		for (;;)
		{
			sum = (sum * 10 + x) % k;
			for (i = 1; i <= top; i++)
			{
				if (sum == ans[i])
				{
					l = i-1;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			ans[++top] = sum;
			if (top == m)
				break;
		}
		if (top == m)
		{
			flag_end = (ans[m] == c);
		}
		else
		{
			m = m - l; m = m % (top - l);
			if (m == 0)
				m = top-1;
			flag_end = (ans[m + 1] == c);
		}
		printf("Case #%d:\n", ++Kcase);
		if (flag_end == true)
			printf("Yes\n");
		else
			printf("No\n");
	}
	system("pause");
	return 0;
}