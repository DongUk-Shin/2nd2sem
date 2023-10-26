#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define MAX_VERTICS 100
#define INF 1000

//배열 초기값 -1
//배열의 값은 연결된 노드의 인덱스
int parent[MAX_VERTICS];

//전역 정수 배열 parent 초기화
void set_init(int n) {
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

int set_find(int curr) {
    if (parent[curr] == -1 )
        return curr;
    while (parent[curr] == -1) { //-1 나올때 까지
        curr = parent[curr];   //부모 찾아서 올라감
    }
    return curr;
}

void set_union(int a, int b) {
    
    //cout << a << " " << b << endl;
    int root1 = set_find(a);
    int root2 = set_find(b);
    //cout << root1 << " " << root2 << endl;
    if (root1 != root2)
        parent[root1] = root2;
}

struct Edge {
    int start, end, weight;
};

typedef struct GraphType {
    int n; //간선개수
    int nvertex; //정점개수
    struct Edge edges[2 * MAX_VERTICS];
} GraphType;

void graph_init(GraphType *g) {
    g->n = g->nvertex = 0;
    for (int i = 0; i < 2 * MAX_VERTICS; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType* g, int start, int end, int w) {
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void *a, const void* b) {
    struct Edge *x = (struct Edge *)a;
    struct Edge *y = (struct Edge *)b;
    return (x->weight - y->weight);
}

/**
 * kruskal
 */
void kruskal(GraphType *g) {
    int edge_accpeted = 0;
    int uset, vset;
    struct Edge e;

    set_init(g->nvertex);
    qsort(g->edges, g->n, sizeof(struct Edge), compare);
    printf("kruskal \n");

    int i = 0;
    while (edge_accpeted < (g->nvertex - 1)) {
        e = g->edges[i]; //e로 꺼내옴
        uset = set_find(e.start); 
        vset = set_find(e.end); 
        if (uset != vset) {
            printf("간선 (%d, %d) %d 선택 \n", e.start, e.end, e.weight);
            edge_accpeted++;
            set_union(uset, vset);
        }
        i++;
    }
}

int main(void) {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    g->nvertex = 8;
    /*
    insert_edge(g, 0, 7, 1);
    insert_edge(g, 1, 5, 2);
    insert_edge(g, 3, 7, 3);
    insert_edge(g, 1, 2, 4);
    insert_edge(g, 4, 5, 5);
    insert_edge(g, 0, 3, 6);
    insert_edge(g, 2, 5, 7);
    insert_edge(g, 4, 7, 8);
    insert_edge(g, 5, 6, 9);
    insert_edge(g, 0, 1, 10);
    insert_edge(g, 2,3, 11);
    insert_edge(g, 6,7, 12);
*/
    insert_edge(g, 0, 1, 1);
    insert_edge(g, 1, 5, 2);

    kruskal(g);
    free(g);
}
