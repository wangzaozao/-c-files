/**
* 两个大数相加，且这两个大数是正整数
* 暂时不考虑负数，不考虑输入不合法的情况
* 要保证输入是正确的才能保证程序正常运行
*/

#include <stdio.h>  
#include <string.h>  

#include<algorithm>
#define MAXSIZE 1000 


int main()
{
	char number1[MAXSIZE + 1];
	char number2[MAXSIZE + 1];
	char sum[MAXSIZE + 2];
	char temp1[MAXSIZE + 1];
	char temp2[MAXSIZE + 1];
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	int j = 0;
	int maxLen = 0;
	int nSum = 0;
	int nCarryBit = 0;
	int nOverFlow = 0;

	gets(number1);
	gets(number2);

	//1.反转字符串，便于从低位到高位相加和最高位的进位导致和的位数增加  
	len1 = strlen(number1);
	len2 = strlen(number2);

	j = 0;
	for (i = len1 - 1; i >= 0; --i)
	{
		temp1[j++] = number1[i];
	}
	temp1[j] = '\0';
	j = 0;
	for (i = len2 - 1; i >= 0; --i)
	{
		temp2[j++] = number2[i];
	}

	//2.把两个字符串补齐，即短字符串的高位用‘0’补齐  
	maxLen = (len1 > len2) ? len1 : len2;
	if (len1 < len2)
	{
		for (i = len1; i < len2; ++i)
			temp1[i] = '0';
		temp1[len2] = '\0';
	}
	else if (len1 > len2)
	{
		for (i = len2; i < len1; ++i)
			temp2[i] = '0';
		temp2[len1] = '\0';
	}

	//3.把两个正整数相加，一位一位的加并加上进位  
	for (i = 0; i < maxLen; i++)
	{
		nSum = temp1[i] - '0' + temp2[i] - '0' + nCarryBit;

		if (nSum > 9)
		{
			if (i == (maxLen - 1))
			{
				nOverFlow = 1;
			}

			nCarryBit = 1;

			sum[i] = nSum - 10 + '0';
		}
		else
		{
			nCarryBit = 0;
			sum[i] = nSum + '0';
		}

	}

	//如果溢出的话表示位增加了  
	if (nOverFlow == 1)
	{
		sum[maxLen++] = nCarryBit + '0';
	}
	sum[maxLen] = '\0';

	//从后向前输出，即是相加后的值  
	for (i = maxLen - 1; i >= 0; --i)
		putchar(sum[i]);

	printf("\n");
	system("pause");
	return 0;
}