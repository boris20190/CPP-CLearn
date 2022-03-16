//邻接链表
#include "stdio.h"
#include "stdlib.h"

#define VertexMax 20//最大顶点个数
#define Maxsize 20

int isVisited[VertexMax] = {0};

typedef int dataType;
typedef int VertexType;

//邻接链表创造方式是:
//每个元素都是一个头结点, 相连接的顶点依次挂在后面A-B-C-D代表存在A-B,A-C,A-D三条边
//所有的头结点,也就是所有的顶点要放在一个数组中,作为一个集合,能准确找到彼此[A,B,C,D];
typedef struct ArcNode {//创建边结构体
    int adjvex;
    struct ArcNode *next;
} *Arc, arc;

typedef struct VertexNode {//创建顶点结构体,其中能够包含边结构体, 也就是边能够往顶点后面挂
    VertexType vertex;
    struct ArcNode *firstArc;
} vnode;

typedef struct {//创建顶点集合结构体,容纳所有顶点的集合, 还有用户输入的定点数和边数
    vnode AdjList[VertexMax];
    int vexNum, arcNum;
} *ALGraph, algraph;

typedef struct queue {
    dataType *vertex;
    int front, rear;
} circularQueue, *cQueue;

void createQueue(cQueue q) {
    q->vertex = (dataType *) malloc(sizeof(dataType) * Maxsize);
    q->front = q->rear = 0;
}

void enQueue(cQueue q, dataType val) {
    if ((q->rear + 1) % Maxsize == q->front) {
        printf("Error! Queue is full\n");
        return;
    }
    q->vertex[q->rear] = val;
    q->rear = (q->rear + 1) % Maxsize;
}

void deQueue(cQueue q, dataType *val) {
    if (q->front == q->rear) {
        printf("Error! Queue is empty\n");
        return;
    }
    *val = q->vertex[q->front];
    q->front = (q->front + 1) % Maxsize;
}

int is_empty(cQueue q) {
    if (q->front == q->rear) {
        return 1;
    }
    return 0;
}

int LocateVex(ALGraph G, VertexType v) {
    for (int i = 0; i < G->vexNum; ++i) {
        if (v == G->AdjList[i].vertex) {
            return i;
        }
    }
    printf("No Found\n");
    return -1;
}

void create_Undirected_Graph(ALGraph G) {
    printf("输入顶点个数:\n");
    scanf("%d", &G->vexNum);
    printf("输入边数\n");
    scanf("%d", &G->arcNum);
    printf("输入顶点元素:\n");
    for (int i = 0; i < G->vexNum; ++i) {
        scanf("%d", &G->AdjList[i].vertex);
        G->AdjList[i].firstArc = NULL;
    }
    int firstArc, secondArc;
    VertexType v1, v2;
    printf("输入边信息(谁后面连谁.比如A后面连B就是AB)\n");
    for (int i = 0; i < G->arcNum; ++i) {
        scanf("%d%d", &v1, &v2);
        firstArc = LocateVex(G, v1);
        secondArc = LocateVex(G, v2);
        if (firstArc == -1 || secondArc == -1) {
            printf("Error! No such vertex!\n");
            return;
        }
        Arc firstVertex, secondVertex;
        firstVertex = (Arc) malloc(sizeof(Arc));
        secondVertex = (Arc) malloc(sizeof(Arc));
        secondVertex->adjvex = secondArc;//这里是记录后顶点在集合中的编号
        secondVertex->next = G->AdjList[firstArc].firstArc;
        G->AdjList[firstArc].firstArc = secondVertex;
        firstVertex->adjvex = firstArc;
        firstVertex->next = G->AdjList[secondArc].firstArc;
        G->AdjList[secondArc].firstArc = firstVertex;
    }
}

void DFS(ALGraph G, int val) {
    Arc p;
    printf("%d ", G->AdjList[val].vertex);
    isVisited[val] = 1;
    p = G->AdjList[val].firstArc;
    while (p) {
        int q = p->adjvex;
        if (isVisited[q] == 0) {
            DFS(G, q);
        }
        p = p->next;
    }
}

void BFS(ALGraph G, int val) {
    circularQueue q;
    dataType outData;
    Arc p;
    createQueue(&q);
    printf("%d ", G->AdjList[val].vertex);
    isVisited[val] = 1;
    enQueue(&q, val);
    while (!is_empty(&q)) {
        deQueue(&q, &outData);
        p = G->AdjList[outData].firstArc;
        while (p) {
            int serial_vertex = p->adjvex;
            if (isVisited[serial_vertex] == 0) {
                printf("%d ", G->AdjList[serial_vertex].vertex);
                isVisited[serial_vertex] = 1;
                enQueue(&q, serial_vertex);
            }
            p = p->next;
        }
    }
}

void clearVisited() {
    for (int i = 0; i < VertexMax; ++i) {
        isVisited[i] = 0;
    }
}

int main() {
    algraph G;
    create_Undirected_Graph(&G);
    printf("深度优先遍历\n");
    DFS(&G, 0);
    clearVisited();
    printf("\n广度优先遍历\n");
    BFS(&G, 0);
    return 0;
}