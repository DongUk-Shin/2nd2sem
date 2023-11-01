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

//
//
void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);

		selected[u] = TRUE;
		for (int i = 0; i < g->n; i++) {
			printf("selected[%d]:%d ", i, selected[i]);

		}
		printf("\n");
		for (int i = 0; i < g->n; i++) {
			printf("distance[%d]:%d ", i, distance[i]);

		}
		printf("\n");
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
	int a = 0;
	for (int i = 0; i <= g->n; i++) { // 거리값 합산
		a += distance[i];
	}
	printf("거리는: %d", a);
}


int main(void)
{
	GraphType g = { 7,
	{{0,7,INF,5,INF,INF,INF},
	{7,0,8,9,7,INF,INF},
	{INF,8,0,INF,5,INF,INF},
	{5,9,INF,0,15,6,INF},
	{INF,7,5,15,0,8,9},
	{INF,INF,INF,6,8,0,11},
	{INF,INF,INF,INF,9,11,0}}
	};
	prim(&g, 0);

	return 0;
}