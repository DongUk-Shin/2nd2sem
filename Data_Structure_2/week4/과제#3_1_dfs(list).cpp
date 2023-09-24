
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

int visted_mat[MAX_VERTICES];
int visted_list[MAX_VERTICES];

typedef struct { 
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType1;

void init_mat(GraphType1* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType1* g, int v) {
    if ((g->n) > MAX_VERTICES) {
        fprintf(stderr, "Exceeding the number of vertices");
        return;
    }
    g->n++;
}

int insert_edge(GraphType1* g, int start, int end) {

    if (start == end) {
        return FALSE;
    }

    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Error\n");
        return FALSE;
    }

    if (g->adj_mat[start][end] == 1 || g->adj_mat[end][start] == 1) {
        return FALSE;
    }

    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
    return TRUE;
}

void print_adj_mat(GraphType1* g) {
    char a = 'A';
    for (int i = 0; i < g->n; i++) {
        printf("%c  ", a);
        a++;
        for (int j = 0; j < g->n; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void dfs_mat(GraphType1* g, int v) {
    int w;
    char a = 'A';
    a = a + v;
    visted_mat[v] = TRUE;
    printf("%c ", a);
    for (w = 0; w < g->n; w++) {
        if (g->adj_mat[v][w] && !visted_mat[w])
            dfs_mat(g, w);
    }
}


typedef struct GraphNode { 
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;


void init_list(GraphType* g) {
    int v;
    g->n = 0;

    for (v = 0; v < MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
    }
}


void dfs_list(GraphType* g, int v) {
    GraphNode* w;
    char c = 'A';
    c = c + v;
    visted_list[v] = TRUE;
    printf("%c ", c);
    for (w = g->adj_list[v]; w; w = w->link) {
        if (!visted_list[w->vertex])
            dfs_list(g, w->vertex);
    }
}

void insert_list_vertex(GraphType* g, int v) {
    if (g->n >= MAX_VERTICES) {
        fprintf(stderr, "Exceeding the number of vertices");
        return;
    }

    g->n++;
}

int insert_list_edge(GraphType* g, int u, int v) {

    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "Error");
        return FALSE;
    }


    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    if (!node) {
        fprintf(stderr, "Error");
        return FALSE;
    }

    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
    return TRUE;
}


void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf(" %d ㅇㅇㅇ ", i);
        while (p != NULL) {
            printf("-> %d", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main() {
    GraphType1* g;
    g = (GraphType1*)malloc(sizeof(GraphType1));
    init_mat(g);
    srand(time(NULL));

    printf("Please enter the number of vertices: ");
    int ver;
    scanf("%d", &ver);

    for (int i = 0; i < ver; i++) {
        insert_vertex(g, i);
    }
    printf("Generate a random connected graph\n");

    int max_edge = ver * (ver - 1) / 2;
    printf("Number of edges (less then %d): ", max_edge);
    int edge;
    scanf("%d", &edge);

    int i = 0;
    while (i < edge) {
        int randomX = rand() % ver;
        int randomY = rand() % ver;
        if (!insert_edge(g, randomX, randomY)) {
            continue;
        }

        i++;
    }

    print_adj_mat(g);
    printf("인접 행렬 DFS: ");
    dfs_mat(g, 0);

    printf("\n-------------------------------------------\n");

    GraphType* gg;
    gg = (GraphType*)malloc(sizeof(GraphType));
    init_list(gg);

    for (int i = 0; i < g->n; i++) { 
        insert_list_vertex(gg, i);
    }

    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (g->adj_mat[i][j] == 1) {
                insert_list_edge(gg, i, j);
            }
        }
    }

    print_adj_list(gg);
    printf("\n인접 연결 리스트 DFS: ");
    dfs_list(gg, 0);
    printf("\n");
    free(g);
    free(gg);
    return 0;
}