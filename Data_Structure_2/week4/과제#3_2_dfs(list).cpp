/*
20204101 �ŵ���
�����ͱ���2 
����#3_2_dfs(list).c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

int visted_mat[MAX_VERTICES];
int visted_list[MAX_VERTICES];

typedef struct { //�迭
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

    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Error\n");
        return FALSE;
    }


    g->adj_mat[start][end] = 1;
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


typedef struct GraphNode { //����Ʈ
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
        fprintf(stderr, "�׷���: ������ ���� �ʰ�");
        return;
    }

    g->n++;
}

int insert_list_edge(GraphType* g, int u, int v) {

    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷���: ���� ��ȣ ����");
        return FALSE;
    }


    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    if (!node) {
        fprintf(stderr, "�޸� �Ҵ� ����");
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
        printf("���� %d �� ���� ����Ʈ ", i);
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

   
    for (int i = 0; i < 7; i++) {
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 0, 5);
    insert_edge(g, 0, 6);
    insert_edge(g, 1, 0);
    insert_edge(g, 1, 6);
    insert_edge(g, 2, 0);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 2);
    insert_edge(g, 2, 4);
    insert_edge(g, 2, 5);
    insert_edge(g, 2, 6);
    insert_edge(g, 3, 2);
    insert_edge(g, 3, 4);

    insert_edge(g, 4, 2);
    insert_edge(g, 4, 3);
    insert_edge(g, 4, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 5, 2);
    insert_edge(g, 5, 5);
    insert_edge(g, 5, 6);

    insert_edge(g, 6, 1);
    insert_edge(g, 6, 2);
    insert_edge(g, 6, 3);
    insert_edge(g, 6, 4);
    insert_edge(g, 6, 5);


    print_adj_mat(g);
    printf("���� ��� DFS: ");
    dfs_mat(g, 0);
    printf("\n-------------------------------------------\n");


    GraphType* gg;
    gg = (GraphType*)malloc(sizeof(GraphType));
    init_list(gg);

    for (int i = 0; i < g->n; i++) { //�� ����� ���� ���� ��ŭ
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
    printf("\n���� ����Ʈ DFS: ");
    dfs_list(gg, 0);
    printf("\n");
    free(g);
    free(gg);
    return 0;
}