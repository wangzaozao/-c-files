#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define INF 100000
#define n 3 //���������Ӳ������
typedef struct {
	int nCoin; //ʹ��Ӳ������
	//����������Ա��Ϊ�˱��ڹ���������̵�չʾ
	int lastSum;//��һ��״̬
	int addCoin;//����һ��״̬�ﵽ��ǰ״̬���õ�Ӳ������
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
			//printf("�����Ӳ�ҷֱ��ǣ�");

		}
	}
	system("pause");
	return 0;

}