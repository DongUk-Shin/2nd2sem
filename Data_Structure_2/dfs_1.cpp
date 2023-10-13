
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
} GraphType_mat;

void init_mat(GraphType_mat* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_mat_vertex(GraphType_mat* g, int v) {
    if ((g->n) > MAX_VERTICES) {
        fprintf(stderr, "Exceeding the number of vertices");
        return;
    }
    g->n++;
}

int insert_mat_edge(GraphType_mat* g, int start, int end) {

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

void print_adj_mat(GraphType_mat* g) {
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

void dfs_mat(GraphType_mat* g, int v) {
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

typedef struct GraphType_list {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
}GraphType_list;


void init_list(GraphType_list* g) {
    int v;
    g->n = 0;

    for (v = 0; v < MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
    }
}


void dfs_list(GraphType_list* g, int v) {
    GraphNode* w;
    char c = 'A';
    c = c + v;
    visted_list[v] = TRUE;
    printf("%c ", c);
    w = g->adj_list[v];
    for (w; w; w = w->link) {
        if (!visted_list[w->vertex])
            dfs_list(g, w->vertex);
    }
}

void insert_list_vertex(GraphType_list* g, int v) {
    if (g->n >= MAX_VERTICES) {
        fprintf(stderr, "Exceeding the number of vertices");
        return;
    }

    g->n++;
}

int insert_list_edge(GraphType_list* g, int u, int v) {

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


void print_adj_list(GraphType_list* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("Adjacency list of vertex %d:", i);
        while (p != NULL) {
            printf(" -> %d", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main() {
    GraphType_list* g_l;
    g_l = (GraphType_list*)malloc(sizeof(GraphType_list));
    init_list(g_l);

    for (int i = 0; i < 4; i++)
        insert_list_vertex(g_l, i);


    insert_list_edge(g_l, 0, 1);
    insert_list_edge(g_l, 0, 2);

    

    print_adj_list(g_l);
    printf("\nadjacency list DFS: ");
    dfs_list(g_l, 0);
    printf("\n");
    free(g_l);
    printf("\n");
    return 0;
}