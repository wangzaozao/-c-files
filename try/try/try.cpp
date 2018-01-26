#include<stdio.h>
#include<map>
#include<stdlib.h>
using  namespace std;
map<long long, int>m;
int main()
{
	printf("%d\n", m[1000]);
	printf("%d\n", m[11000]);
	printf("%d\n", m[10]);
	system("pause");
	return 0;
}