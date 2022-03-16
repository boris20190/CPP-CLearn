//邻接矩阵
#include "stdio.h"
#include "stdlib.h"

#define Maxsize 100//队列最大长度为100
#define VertexMax 100 //最大定点数为100

typedef int VertexType;
typedef int dataType;//队列元素类型

int isVisited[VertexMax] = {0};

typedef struct mg {
    VertexType Vertex[VertexMax];//存放定点元素
    int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组
    int vexNum, arcNum;
} *MyGraph, myGraph;

typedef struct queue {//创建循环队列结构体
    dataType *vertex;
    int front, rear;
} circularQueue, *cQueue;

void createQueue(cQueue q) {
    q->vertex = (dataType *) malloc(sizeof(dataType) * Maxsize);//建立好队列         //必须用malloc!!!
    q->front = q->rear = 0;//队首队尾归零
}

void enQueue(cQueue q, dataType val) {//入队
    if ((q->rear + 1) % Maxsize == q->front) {
        printf("Error! Queue is full\n");
        return;
    }
    q->vertex[q->rear] = val;
    q->rear = (q->rear + 1) % Maxsize;
}

void deQueue(cQueue q, dataType *val) {//出队
    if (q->front == q->rear) {
        printf("Error! Queue is empty!\n");
        return;
    }
    *val = q->vertex[q->front];
    q->front = (q->front + 1) % Maxsize;
}

int is_empty(cQueue q) {//队列判空
    if (q->front == q->rear) {
        return 1;
    }
    return 0;
}

int LocateVex(MyGraph G, VertexType v) {//找顶点元素对应数组下标
    for (int i = 0; i < G->vexNum; ++i) {
        if (v == G->Vertex[i]) {//如果在一维数组中找到对应元素
            return i;//返回该元素的下标
        }
    }
    printf("No Found\n");
    return -1;//没找到返回值-1
}

void create_Undirected_Graph(MyGraph G) {
    printf("输入顶点个数:\n");
    scanf("%d", &G->vexNum);
    printf("输入边数:\n");
    scanf("%d", &G->arcNum);
    printf("输入顶点元素:\n");
    for (int i = 0; i < G->vexNum; ++i) {//循环录入顶点元素,共有vexNum个
        scanf("%d", &G->Vertex[i]);
    }
    for (int i = 0; i < G->vexNum; ++i) {//初始化二维数组, 全为0
        for (int j = 0; j < G->vexNum; ++j) {
            G->AdjMatrix[i][j] = 0;
        }
    }
    int firstArc, secondArc;
    VertexType v1, v2;
    printf("输入边信息(谁和谁相连):\n");
    for (int i = 0; i < G->arcNum; ++i) {
        scanf("%d%d", &v1, &v2);//录入要找的顶点元素
        firstArc = LocateVex(G, v1);//找到两个顶点对应的数组下标
        secondArc = LocateVex(G, v2);
        if (firstArc == -1 || secondArc == -1) {//如果有一个顶点没找到,就报错结束
            printf("Error! No such vertex!\n");
            return;
        }
        G->AdjMatrix[firstArc][secondArc] = 1;//创建无向图,所以两边对应的位置都要变成1,代表成对应关系
        G->AdjMatrix[secondArc][firstArc] = 1;
    }
}

void graphPrint(MyGraph G) {//打印建好的邻接矩阵
    printf("\n==========邻接矩阵==========\n");
    printf("\t");
    for (int i = 0; i < G->vexNum; ++i) {
        printf("%d ", G->Vertex[i]);
    }
    printf("\n");
    for (int i = 0; i < G->vexNum; ++i) {
        printf("%d\t", G->Vertex[i]);
        for (int j = 0; j < G->vexNum; ++j) {
            printf("%d ", G->AdjMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(MyGraph G, int val) {
    printf("%d ", G->Vertex[val]);
    isVisited[val] = 1;
    for (int i = 0; i < G->vexNum; ++i) {
        if (G->AdjMatrix[val][i] == 1 && isVisited[i] == 0) {
            DFS(G, i);
        }
    }
    for (int i = 0; i < G->vexNum; ++i) {
        if (isVisited[i] == 0) {
            printf("%d ", G->Vertex[i]);
            isVisited[i] = 1;
        }
    }
}

void BFS(MyGraph G, int val) {
    circularQueue q;
    dataType outData;//用来接收出队的元素
    createQueue(&q);
    printf("%d ", G->Vertex[val]);
    isVisited[val] = 1;
    enQueue(&q, val);
    while (!is_empty(&q)) {
        deQueue(&q, &outData);
        for (int i = 0; i < G->vexNum; ++i) {
            if (G->AdjMatrix[outData][i] == 1 && isVisited[i] == 0) {
                printf("%d ", G->Vertex[i]);
                isVisited[i] = 1;
                enQueue(&q, i);
            }
        }
    }
}

void clearVisited() {
    for (int i = 0; i < VertexMax; ++i) {
        isVisited[i] = 0;
    }
}

int main() {
    myGraph G;
    create_Undirected_Graph(&G);
    graphPrint(&G);
    printf("\n深度优先遍历:\n");
    DFS(&G, 4);
    clearVisited();
    printf("\n广度优先遍历\n");
    BFS(&G, 4);
    return 0;
}