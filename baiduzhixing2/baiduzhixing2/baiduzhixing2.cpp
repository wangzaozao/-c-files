#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct Node
{
	int num;
	Node *fa;
	Node*next[26];
}; 
Node root;
void init()
{
	root.num = 0;
	for (int i = 0; i < 26; i++)
	{
		root.next[i] = NULL;
	}
}
Node *create(Node*fa)
{
	Node*s = (Node*)malloc(sizeof(Node));
	s->fa = fa;
	s->num = 0;
	for (int i = 0; i < 26; i++)
	{
		s->next[i] = NULL;
	}
	return s;
}
void Add(char*s)
{
	Node *p = &root;
	for (int i = 0; s[i];i++)
	{
		int pos = s[i] - 'a';
		if (p->next[pos] == NULL)
		{
			p->next[pos] = create(p);
		}
		p = p->next[pos];
		if (p->num == 0)
		{
			for (int j = 0; j < 26; j++)
			{
				if (p->next[i] != NULL)
				{
					p->next[j]->num = 0;
				}
			}
		}
		p->num++;
	}
}
void del(char*s)
{
	Node *p = &root;
	for (int i = 0; s[i]; i++)
	{
		int pos = s[i] - 'a';
		if (p->next[pos] == NULL)return;
		else p = p->next[pos];
		if (p->num == 0)
			return;
	}
	int tmp = p->num;
	while (p != &root)
	{
		p->num -= tmp;
		p = p->fa;
	}
}
bool find(char *s)
{
	Node *p = &root;
	for (int i = 0; s[i]; i++)
	{
		int pos = s[i] - 'a';
		if (p->next[pos] == NULL)
			return false;
		else
			p = p->next[pos];
		if (p->num == 0)return false;
	}
	return true;
}
int main()
{
	int n;
	char s[41], s1[10];
	scanf("%d", &n);
	init();
	while (n--)
	{
		scanf("%s%s", s1, s);
		if (s1[0] == 'i')
		{
			Add(s);
		}
		else if (s1[0] == 's')
		{
			if (find(s))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			del(s);
		}
	}
	system("pause");
	return 0;
}
