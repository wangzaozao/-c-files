#include<stdio.h>
#include<math.h>

#include<algorithm>
using namespace std;
int main()
{
	int apple[3][4] = { 6, 5, 3, 5, 3, 1, 3, 1, 1, 1, 2, 3 };
	int M[3][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
				M[i][j] = apple[i][j];
			else if (i == 0 && j != 0)
				M[i][j] = M[i][j - 1] + apple[i][j];
			else if (i != 0 && j == 0)
				M[i][j] = M[i - 1][j] + apple[i][j];
			else
				M[i][j] = max(M[i - 1][j], M[i][j - 1]) + apple[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}