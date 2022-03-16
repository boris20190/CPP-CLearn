#include "stdio.h"
#include "stdlib.h"

//有向图的创建(邻接矩阵)
typedef struct graph {
    int num;
    struct graph *next;
} *g;

int isVisited[10] = {0};

int **createGraph() {
    int **gM;
    gM = (int **) malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; ++i) {
        gM[i] = (int *) malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; ++j) {
            gM[i][j] = 0;
        }
    }
    int association;
    printf("一次输入一个数,输入-1结束\n");
    for (int i = 0; i < 10; ++i) {
        printf("第%d行", i);
        while (1) {
            scanf("%d", &association);
            if (association == -1) {
                break;
            }
            gM[i][association] = 1;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", gM[i][j]);
        }
        printf("\n");
    }
    return gM;
}

int **createGraphDefault() {
    int **gM;
    gM = (int **) malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; ++i) {
        gM[i] = (int *) malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; ++j) {
            gM[i][j] = 0;
        }
    }
    gM[0][1] = 1;
    gM[0][2] = 1;
    gM[0][4] = 1;
    gM[1][0] = 1;
    gM[2][0] = 1;
    gM[4][0] = 1;
    gM[4][3] = 1;
    gM[3][4] = 1;
    gM[1][4] = 1;
    gM[4][1] = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ", gM[i][j]);
        }
        printf("\n");
    }
    return gM;
}

g *createGraphLinkList() {
    g *Link;
    Link = (g *) malloc(sizeof(g) * 5);
    for (int i = 0; i < 5; ++i) {
        Link[i] = (g) malloc(sizeof(g));
        Link[i]->next = NULL;
        Link[i]->num = i;
    }
    g m1 = (g) malloc(sizeof(g));
    m1->num = 1;
    m1->next = NULL;
    Link[0]->next = m1;
    g m2 = (g) malloc(sizeof(g));
    m2->num = 2;
    m2->next = NULL;
    m1->next = m2;
    g m3 = (g) malloc(sizeof(g));
    m3->next = NULL;
    m3->num = 4;
    m2->next = m3;
    g m4 = (g) malloc(sizeof(g));
    m4->next = NULL;
    m4->num = 0;
    Link[1]->next = m4;
    g m5 = (g) malloc(sizeof(g));
    m5->next = NULL;
    m5->num = 0;
    Link[2]->next = m5;
    g m6 = (g) malloc(sizeof(g));
    m6->next = NULL;
    m6->num = 3;
    Link[4]->next = m6;
    g m7 = (g) malloc(sizeof(g));
    m7->next = NULL;
    m7->num = 0;
    m6->next = m7;
    g m8 = (g) malloc(sizeof(g));
    m8->next = NULL;
    m8->num = 4;
    Link[3]->next = m8;
    g m9 = (g) malloc(sizeof(g));
    m9->next = NULL;
    m9->num = 1;
    m7->next = m9;
    g m10 = (g) malloc(sizeof(g));
    m10->next = NULL;
    m10->num = 4;
    m4->next = m10;
    return Link;
}

void DFS(int **graph, int val) {
    printf("%d\n", val);
    isVisited[val] = 1;
    for (int i = 0; i < 5; ++i) {
        if (isVisited[i] == 0 && graph[val][i] == 1) {
            DFS(graph, i);
        }
    }
}

void DFS2(g *graph, int val) {
    printf("%d\n", graph[val]->num);
    isVisited[graph[val]->num] = 1;
    g temp;
    temp = graph[val]->next;
    while (temp) {
        if (isVisited[temp->num] == 0) {
            DFS2(graph, temp->num);
        }
        temp = temp->next;
    }
}

void clear() {
    for (int i = 0; i < 10; ++i) {
        isVisited[i] = 0;
    }
}

//先就写一个邻接矩阵的,邻接链表的同理
void BFS(int **graph, int val) {
    int arr[5], j = 0;
    int in = 0;
    int out = 0;
    arr[in++] = val;
    isVisited[val] = 1;
    while (in > out) {
        printf("%d\n", arr[out++]);
        for (int i = 0; i < 5; ++i) {
            if (graph[val][i] == 1 && isVisited[i] == 0) {
                isVisited[i] = 1;
                arr[in++] = i;
            }
        }
    }
}

void BFSTraverse(int **graph) {
    for (int i = 0; i < 5; ++i) {
        if (isVisited[i] == 0) {
            BFS(graph, i);
        }
    }
}

int main() {
    int **graph1 = createGraphDefault();
    g *graph2 = createGraphLinkList();
    printf("*************\n");
    printf("邻接矩阵深度优先:\n");
    DFS(graph1, 4);
    clear();
    printf("邻接表深度优先:\n");
    DFS2(graph2, 0);
    clear();
    printf("*************\n");
    printf("邻接矩阵广度优先:\n");
    BFSTraverse(graph1);
    return 0;
}