#include<stdio.h>
#include<stdlib.h>
int main()
{
		int t, n;
		scanf("%d", &t);
		for (int te = 1; te <= t; te++)
		{
			scanf("%d", &n);
			double ans1 = 1 + ((n - 2) * 19)*1.0 / 27.0;
			double ans2 = (46 - 38.0 / n)*1.0 / ((19 - 11.0 / n)*1.0);
			printf("Case #%d:\n", te);
			printf("%.6f %.6f\n", ans1, ans2);
		}
		system("pause");
		return 0;
}