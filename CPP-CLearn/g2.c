//�ڽӾ���
#include "stdio.h"
#include "stdlib.h"

#define Maxsize 100//������󳤶�Ϊ100
#define VertexMax 100 //��󶨵���Ϊ100

typedef int VertexType;
typedef int dataType;//����Ԫ������

int isVisited[VertexMax] = {0};

typedef struct mg {
    VertexType Vertex[VertexMax];//��Ŷ���Ԫ��
    int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά����
    int vexNum, arcNum;
} *MyGraph, myGraph;

typedef struct queue {//����ѭ�����нṹ��
    dataType *vertex;
    int front, rear;
} circularQueue, *cQueue;

void createQueue(cQueue q) {
    q->vertex = (dataType *) malloc(sizeof(dataType) * Maxsize);//�����ö���         //������malloc!!!
    q->front = q->rear = 0;//���׶�β����
}

void enQueue(cQueue q, dataType val) {//���
    if ((q->rear + 1) % Maxsize == q->front) {
        printf("Error! Queue is full\n");
        return;
    }
    q->vertex[q->rear] = val;
    q->rear = (q->rear + 1) % Maxsize;
}

void deQueue(cQueue q, dataType *val) {//����
    if (q->front == q->rear) {
        printf("Error! Queue is empty!\n");
        return;
    }
    *val = q->vertex[q->front];
    q->front = (q->front + 1) % Maxsize;
}

int is_empty(cQueue q) {//�����п�
    if (q->front == q->rear) {
        return 1;
    }
    return 0;
}

int LocateVex(MyGraph G, VertexType v) {//�Ҷ���Ԫ�ض�Ӧ�����±�
    for (int i = 0; i < G->vexNum; ++i) {
        if (v == G->Vertex[i]) {//�����һά�������ҵ���ӦԪ��
            return i;//���ظ�Ԫ�ص��±�
        }
    }
    printf("No Found\n");
    return -1;//û�ҵ�����ֵ-1
}

void create_Undirected_Graph(MyGraph G) {
    printf("���붥�����:\n");
    scanf("%d", &G->vexNum);
    printf("�������:\n");
    scanf("%d", &G->arcNum);
    printf("���붥��Ԫ��:\n");
    for (int i = 0; i < G->vexNum; ++i) {//ѭ��¼�붥��Ԫ��,����vexNum��
        scanf("%d", &G->Vertex[i]);
    }
    for (int i = 0; i < G->vexNum; ++i) {//��ʼ����ά����, ȫΪ0
        for (int j = 0; j < G->vexNum; ++j) {
            G->AdjMatrix[i][j] = 0;
        }
    }
    int firstArc, secondArc;
    VertexType v1, v2;
    printf("�������Ϣ(˭��˭����):\n");
    for (int i = 0; i < G->arcNum; ++i) {
        scanf("%d%d", &v1, &v2);//¼��Ҫ�ҵĶ���Ԫ��
        firstArc = LocateVex(G, v1);//�ҵ����������Ӧ�������±�
        secondArc = LocateVex(G, v2);
        if (firstArc == -1 || secondArc == -1) {//�����һ������û�ҵ�,�ͱ������
            printf("Error! No such vertex!\n");
            return;
        }
        G->AdjMatrix[firstArc][secondArc] = 1;//��������ͼ,�������߶�Ӧ��λ�ö�Ҫ���1,����ɶ�Ӧ��ϵ
        G->AdjMatrix[secondArc][firstArc] = 1;
    }
}

void graphPrint(MyGraph G) {//��ӡ���õ��ڽӾ���
    printf("\n==========�ڽӾ���==========\n");
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
    dataType outData;//�������ճ��ӵ�Ԫ��
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
    printf("\n������ȱ���:\n");
    DFS(&G, 4);
    clearVisited();
    printf("\n������ȱ���\n");
    BFS(&G, 4);
    return 0;
}