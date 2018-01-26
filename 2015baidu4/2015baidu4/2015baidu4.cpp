#include<stdio.h>
#include<stdlib.h>
#define PI 3.141592
#include<math.h>
int  main()
{
	int T;
	int n;
	int ca = 1;
	double a, r;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%lf%lf", &n, &a, &r);
		printf("Case #%d:\n", ca++);
		a = a / 2 * cos(PI / n) / sin(PI / n);
		if (a < r)
			printf("I want to kiss you!\n");
		else
			printf("Give me a kiss!\n");
	}
	system("pause");
	return 0;
}