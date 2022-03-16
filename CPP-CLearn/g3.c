//�ڽ�����
#include "stdio.h"
#include "stdlib.h"

#define VertexMax 20//��󶥵����
#define Maxsize 20

int isVisited[VertexMax] = {0};

typedef int dataType;
typedef int VertexType;

//�ڽ������췽ʽ��:
//ÿ��Ԫ�ض���һ��ͷ���, �����ӵĶ������ι��ں���A-B-C-D�������A-B,A-C,A-D������
//���е�ͷ���,Ҳ�������еĶ���Ҫ����һ��������,��Ϊһ������,��׼ȷ�ҵ��˴�[A,B,C,D];
typedef struct ArcNode {//�����߽ṹ��
    int adjvex;
    struct ArcNode *next;
} *Arc, arc;

typedef struct VertexNode {//��������ṹ��,�����ܹ������߽ṹ��, Ҳ���Ǳ��ܹ�����������
    VertexType vertex;
    struct ArcNode *firstArc;
} vnode;

typedef struct {//�������㼯�Ͻṹ��,�������ж���ļ���, �����û�����Ķ������ͱ���
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
    printf("���붥�����:\n");
    scanf("%d", &G->vexNum);
    printf("�������\n");
    scanf("%d", &G->arcNum);
    printf("���붥��Ԫ��:\n");
    for (int i = 0; i < G->vexNum; ++i) {
        scanf("%d", &G->AdjList[i].vertex);
        G->AdjList[i].firstArc = NULL;
    }
    int firstArc, secondArc;
    VertexType v1, v2;
    printf("�������Ϣ(˭������˭.����A������B����AB)\n");
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
        secondVertex->adjvex = secondArc;//�����Ǽ�¼�󶥵��ڼ����еı��
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
    printf("������ȱ���\n");
    DFS(&G, 0);
    clearVisited();
    printf("\n������ȱ���\n");
    BFS(&G, 0);
    return 0;
}