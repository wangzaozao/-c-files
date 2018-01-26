#include<stdio.h>
#include<stdlib.h>
struct Act
{
	int start;
	int end;
}act[10000];
int N;
void sort()
{
	int i, j;
	struct Act temp;
	for (i = 0; i < N-1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (act[i].end>act[j].end)
			{
				temp = act[i];
				act[i] = act[j];
				act[j] = temp;
			}
		}
	}
}
int greedy_activity_selector()
{
	int i=0,num=1,j;
	for (j = 1; j < N; j++)
	{
		if (act[j].start >= act[i].end)
		{
			i = j;
			num++;
		}
	}
	return num;
}
int main()
{
	int i,t;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &act[i].start, &act[i].end);
	}
	sort();
	t = greedy_activity_selector();
	printf("%d\n", t);
	system("pause");
	return 0;
}