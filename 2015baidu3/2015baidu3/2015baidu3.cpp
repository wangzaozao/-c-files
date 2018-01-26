#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;
map<long long, int>m;

struct a
{
	int A, B, C, D;
}b[1010];
int main()
{
	int T;
	int i,j;
	int A, B, C, D;
	long long temp;
	int ans;
	int te = 1;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; i++)
			scanf("%d.%d.%d.%d", &b[i].A,&b[i].B,&b[i].C,&b[i].D);
		printf("Case #%d:\n", te++);
		for (i = 0; i < M; i++)
		{
			m.clear();
			ans = 0;
			scanf("%d.%d.%d.%d", &A, &B, &C, &D);
			for (j = 0; j < N; j++)
			{
				temp = 0;//trick
				temp = temp * 1000 + (b[j].A&A);
				temp = temp * 1000 + (b[j].B&B);
				temp = temp * 1000 + (b[j].C&C);
				temp = temp * 1000 + (b[j].D&D);
				if (!m[temp])
				{
					m[temp] = 1;
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	}
	system("pause");
	return 0;
}