#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define INF 100000
#define n 3 //用于找零的硬币种数
typedef struct {
	int nCoin; //使用硬币数量
	//以下两个成员是为了便于构造出求解过程的展示
	int lastSum;//上一个状态
	int addCoin;//从上一个状态达到当前状态所用的硬币种类
} state;
int main()
{
	int i, j,count,total;
	int coin[] = { 1, 5, 10 };
	scanf("%d", &count);
	getchar();
	while (count--)
	{
		scanf("%d", &total);
		state *sum = (state *)malloc(sizeof(state)*(total + 1));
		//init
		for (i = 0; i <= total; i++)
			sum[i].nCoin = INF;
		sum[0].nCoin = 0;
		sum[0].lastSum = 0;

		for (i = 1; i <= total; i++)
		for (j = 0; j < n; j++)
		if (i - coin[j] >= 0 && sum[i - coin[j]].nCoin + 1 < sum[i].nCoin)
		{
			sum[i].nCoin = sum[i - coin[j]].nCoin + 1;
			sum[i].lastSum = j;
			sum[i].addCoin = coin[j];
		}

		if (sum[total].nCoin == INF)
		{
			printf("can't make change.\n");
			return 0;
		}
		else
		{
			printf("%d\n", sum[total].nCoin);
			//printf("找零的硬币分别是：");

		}
	}
	system("pause");
	return 0;

}