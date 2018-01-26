#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAX 26   
using namespace std;

typedef struct TrieNode                     //Trie结点声明    
{
	int num;                            //标记该结点处是否构成单词，也可以根据需要变化   
	struct TrieNode *next[MAX];            //儿子分支    
}Trie;

void insert(Trie *root, const char *s)     //将单词s插入到字典树中    
{
	if (root == NULL || *s == '\0')
		return;
	int i;
	Trie *p = root;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)        //如果不存在，则建立结点    
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
	p->num++;                       //单词结束的地方标记此处可以构成一个单词    
	printf("%d\n", p->num-1);
}



void del(Trie *root)                      //释放整个字典树占的堆区空间    
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
	int n;                              //n为建立Trie树输入的单词数，m为要查找的单词数    
	char s[100];
	Trie *root = (Trie *)malloc(sizeof(Trie));
	for (i = 0; i<MAX; i++)
	{
		root->next[i] = NULL;
	}
	root->num= 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i<n; i++)                 //先建立字典树    
	{
		scanf("%s", s);
		sort(s, s + strlen(s));
		insert(root, s);
	}
	
	del(root);                         //释放空间很重要    
	system("pause");
	return 0;
}