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
		//������maxendinghere�������array[i]
		//��maxendinghere>0��array[i]>0��maxendinghere����Ϊ���ߺ�
		//��maxendinghere>0��array[i]<0��maxendinghere����Ϊ���ߺ�
		//��maxendinghere<0��array[i]<0��maxendinghere����Ϊarray[i]
		//��maxendinghere<0��array[i]>0��maxendinghere����Ϊarray[i]
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