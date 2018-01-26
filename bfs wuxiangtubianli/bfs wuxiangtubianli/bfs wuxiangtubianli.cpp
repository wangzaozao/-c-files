#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
typedef struct graph
{
	char vexs[MAX];//储存定点
	int vexnum;//顶点个数
	int edgnum;//边个数
	int matrix[MAX][MAX];
}Graph, *PGraph;

static int get_position(Graph g, char ch)
{
	int i;
	for (i = 0; i<g.vexnum; i++)
	if (g.vexs[i] == ch)
		return i;
	return -1;
}

PGraph create_graph()
{
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	char edges[][2] = { { 'A', 'C' }, { 'A', 'D' }, { 'A', 'F' }, { 'B', 'C' }, { 'C', 'D' }, { 'E', 'G' }, { 'F', 'G' } };
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	int  elen = sizeof(edges) / sizeof(edges[0]);
	int i, p1, p2;
	Graph *pG;
	if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
		return NULL;
	memset(pG, 0, sizeof(Graph));
	pG->vexnum = vlen;
	pG->edgnum = elen;
	for (i = 0; i<pG->vexnum; i++)
	{
		pG->vexs[i] = vexs[i];
	}
	for (i = 0; i<pG->edgnum; i++)
	{
		p1 = get_position(*pG, edges[i][0]);
		p2 = get_position(*pG, edges[i][1]);
		pG->matrix[p1][p2] = 1;
		pG->matrix[p2][p1] = 1;
	}
	return pG;
}

void print_graph(Graph G)
{
	int i, j;
	printf("matrix Graph:\n");
	for (i = 0; i<G.vexnum; i++)
	{
		for (j = 0; j<G.vexnum; j++)
			printf("%d ", G.matrix[i][j]);
		printf("\n");
	}
}

int first_vertex(Graph G, int v)//返回这一行第一次遇到1的位置
{
	int i;
	for (i = 0; i<G.vexnum; i++)
	if (G.matrix[v][i] == 1)
		return i;
	return -1;
}

int next_vertex(Graph G, int v, int w)//返回这一行在w位置之后遇到1的位置
{
	int i;
	for (i = w + 1; i<G.vexnum; i++)
	if (G.matrix[v][i] == 1)
		return i;
	return -1;
}

void BFS(Graph G)
{
	int visited[MAX];
	int queue[MAX];
	int front = 0;//队首下标
	int rear = 0;//队尾下标，加入元素通过队尾加加
	memset(visited, 0, sizeof(visited));
	int i=0, v, w;
	for (i = 0; i<G.vexnum; i++)//这个循环对于连通图来说没必要，只要连通肯定能通过后边不断遍历下一个节点遍历完全，但是i=0选择了从A开始遍历
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%c ", G.vexs[i]);
			queue[rear++] = i;
		}
		while (rear != front)//队列不为空
		{
			v = queue[front++];
			for (w = first_vertex(G, v); w >= 0; w = next_vertex(G, v, w))
			{
				if (visited[w] == 0)
				{
					visited[w] = 1;
					printf("%c ", G.vexs[w]);
					queue[rear++] = w;
				}
			}
		}
	}
}

int main()
{
	Graph *pG;
	pG = create_graph();
	print_graph(*pG);
	printf("\n");
	BFS(*pG);
	system("pause");
}