//DFSģ���� HDU 1181

#include <iostream>
#include <string.h>
#include <queue>
#include <string>
using namespace std;
string str[300];
int vis[300], i;//������飬��һ��·���У������ҹ��Ľڵ㲻�ܱ��ٴβ��ң���Ȼ�ͻ�ʹ·������ѭ��
int flag = 0;//�����ж������Ƿ���ҵ�·��
void dfs(string use)
{
	char last = use[use.length() - 1];//����ַ�����β���ַ�
	//if (flag == 1)//����Ѿ��ҵ��˾�ֱ�ӽ��������ٲ���Ҫ����������
	//	return;     //����ⲻ��Ҫ
	for (int k = 0; k<i; k++)//����ӵ�ǰuse�ַ���Ϊ��ǰ�ڵ㣬��ôforѭ����Ӧ�ñ�����һ������п��ܽڵ�
	{
		if (vis[k] == 0 && str[k][0] == last)//���δ�����ʣ��������ַ��ϱ��ڵ�ĩ�ַ�ƥ�䣬�Ϳ�����Ϊ�������ķ�֧�ڵ�
		{
			vis[k] = 1;//ÿȷ��·���е�һ���ڵ㣬�ͱ������
			if (str[k][str[k].length() - 1] == 'm')//���������Ľ�������������flag���˳�
			{
				flag = 1;
				return;
			}
			else
				dfs(str[k]);//���������������
			//vis[k]=0
			//�󲿷�DFS��һ��·������ʧ�ܺ���Ҫ���ݵ���һ״̬
			//ͨ����Ҫ�Ѵӱ��ڵ������ı�Ƕ�����
			//ʵ�����Ƿ���Ҫ���ñ�ǣ�Ӧ�ÿ�·����Դ�Ƿ��Խڵ��ܷ񵽴���ڲ���Ӱ��
			//�ڱ����С����str[k]�ǵ�����·���е�һ���ڵ㣬���ܴ�ʲô;����������str[k]������Ӱ���������յ㡣
		}
	}
}
int main() {

	while (cin >> str[i])
	{
		if (str[i] == "0")
		{
			memset(vis, 0, sizeof(vis));
			flag = 0;
			for (int j = 0; j<i; j++)
			{
				if (str[j][0] == 'b')//���������ʼ�����ͽ�����������
				{
					vis[j] = 1;
					dfs(str[j]);
				}
			}
			i = 0;//�ж������������ÿ���һ�飬����i
			if (flag == 1)
				cout << "Yes." << endl;
			else
				cout << "No." << endl;
		}
		else
			i++;
	}
	return 0;
}