#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAX 26   
using namespace std;

typedef struct TrieNode                     //Trie�������    
{
	int num;                            //��Ǹý�㴦�Ƿ񹹳ɵ��ʣ�Ҳ���Ը�����Ҫ�仯   
	struct TrieNode *next[MAX];            //���ӷ�֧    
}Trie;

void insert(Trie *root, const char *s)     //������s���뵽�ֵ�����    
{
	if (root == NULL || *s == '\0')
		return;
	int i;
	Trie *p = root;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)        //��������ڣ��������    
		{
			Trie *temp = (Trie *)malloc(sizeof(Trie));
			for (i = 0; i<MAX; i++)
			{
				temp->next[i] = NULL;
			}
			temp->num=0;
			p->next[*s - 'a'] = temp;
			p = p->next[*s - 'a'];
		}
		else
		{
			p = p->next[*s - 'a'];
		}
		s++;
	}
	p->num++;                       //���ʽ����ĵط���Ǵ˴����Թ���һ������    
	printf("%d\n", p->num-1);
}



void del(Trie *root)                      //�ͷ������ֵ���ռ�Ķ����ռ�    
{
	int i;
	for (i = 0; i<MAX; i++)
	{
		if (root->next[i] != NULL)
		{
			del(root->next[i]);
		}
	}
	free(root);
}

int main(void)
{
	int i;
	int n;                              //nΪ����Trie������ĵ�������mΪҪ���ҵĵ�����    
	char s[100];
	Trie *root = (Trie *)malloc(sizeof(Trie));
	for (i = 0; i<MAX; i++)
	{
		root->next[i] = NULL;
	}
	root->num= 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i<n; i++)                 //�Ƚ����ֵ���    
	{
		scanf("%s", s);
		sort(s, s + strlen(s));
		insert(root, s);
	}
	
	del(root);                         //�ͷſռ����Ҫ    
	system("pause");
	return 0;
}