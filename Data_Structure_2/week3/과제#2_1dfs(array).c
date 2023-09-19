#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

int visted[MAX_VERTICES];

typedef struct {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType *g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType* g, int v) {
    if ((g->n) > MAX_VERTICES) {
        fprintf(stderr, "Exceeding the number of vertices");
        return;
    }
    g->n++;
}

int insert_edge(GraphType* g, int start, int end) {

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

void print_adj_mat(GraphType* g) {
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

void dfs_mat(GraphType* g, int v) {
    int w;
    char a = 'A';
    a = a + v;
    visted[v] = TRUE;
    printf("%c ", a);
    for (w = 0; w < g->n; w++) {
        if (g->adj_mat[v][w] && !visted[w])
            dfs_mat(g, w);
    }
}

int main() {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
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
    printf("DFS: ");
    dfs_mat(g, 0);
    printf("\n\n");
    free(g);
    return 0;
}
