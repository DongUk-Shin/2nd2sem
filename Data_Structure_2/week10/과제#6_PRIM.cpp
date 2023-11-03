#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];


// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}


void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;

		printf("셀렉티드 selected[%d] -> %d\n", i, selected[i]);

		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					printf("디스턴스 distance[%d] = %d\n", distance[v], g->weight[u][v]);
					distance[v] = g->weight[u][v];

				}
	}
	int sum = 0;
	for (int i = 0; i < g->n; i++) {
		sum += distance[i];
	}
	printf("합 %d", sum);
}

int main(void)
{
	GraphType g = { 9,{
	{ 0,    35,  INF, INF, 245, INF, INF , INF, INF},
	{ 35,   0,   123, INF, INF, 154, INF , INF, INF},
	{ INF,  123, 0,   117, INF, 165, 222 , INF, INF},
	{ INF,  INF, 117, 0,   INF, INF, INF , INF, INF},
	{ 245,  INF, INF, INF, 0  , 87 , INF , INF, 98 },
	{ INF,  154, 165, INF, 87 , 0  , 155 , INF, 122},
	{ INF,  INF, 222, INF, INF, 155,   0 , 164, INF},
	{ INF,  INF, INF, INF, INF, INF, 164 , 0,   INF},
	{ INF,  INF, INF, INF, 98 , 122, INF , INF,  0 }
	}};
	prim(&g, 0);
	return 0;
}
