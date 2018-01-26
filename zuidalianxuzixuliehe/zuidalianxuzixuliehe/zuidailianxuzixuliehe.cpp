#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int string_process(int *p)
{
	int i,maxendinghere=0,maxsofar=0;
	for (i = 0; i < 30; i++)
	{
		maxendinghere = max(maxendinghere + p[i], p[i]);
		//分析：maxendinghere必须包含array[i]
		//当maxendinghere>0且array[i]>0，maxendinghere更新为两者和
		//当maxendinghere>0且array[i]<0，maxendinghere更新为两者和
		//当maxendinghere<0且array[i]<0，maxendinghere更新为array[i]
		//当maxendinghere<0且array[i]>0，maxendinghere更新为array[i]
		maxsofar = max(maxendinghere, maxsofar);
	}
	return maxsofar;
}
int main()
{
	int p[100] = { 1, -1, 2, 3, 12, 14, 0, 23,-29, 1, 25,-67, -34, 7, 8, 9, 10, 11, 12, 13, 14 };
	int n = string_process(p);
	printf("%d\n", n);
	system("pause");
	return 0;
}