#include<stdio.h>  
#include<stdlib.h>  
  
int visited[20];  
  
typedef struct ArcNode{  
    int adjvex;  //�ڽӵ���   
    struct ArcNode * nextarc;  //ָ����һ���ڽӵ��ָ����   
};  
  
typedef struct VNode{ //��ͷ�ڵ�   
    int data;  //������Ϣ   
    ArcNode *firstarc;   //ָ���һ�������ö���Ļ���ָ��   
}VNode, AdjList[20];  
  
typedef struct{  
    AdjList vertices;  
    int vexnum, arcnum;  
}ALGraph;  
  
typedef struct{  
    int start;  
    int end;  
}Arc;  
  
Arc BSet[20];    //��������������ɵıߵı߼�  
Arc DSet[20];   //��������������ɵıߵı߼�  
int b = 0;  //������������߼���index  
int d = 0;  //������������߼���index  
  
void createGraph(ALGraph &G){  
    printf("������ͼ�Ķ���ĸ�����\n");  
    scanf("%d", &G.vexnum);  
    printf("������ͼ�ıߵĸ�����\n");  
    scanf("%d", &G.arcnum);  
    printf("�����붥�����Ϣ��\n");  
    for (int i = 0; i<G.vexnum; i++){  
        scanf("%d", &((G.vertices[i]).data));  
        G.vertices[i].firstarc = NULL;  
    }  
    printf("������ߵ���Ϣ\n");  
    int a, b;  
    for (int j = 0; j<G.arcnum; j++){  
        scanf("%d%d", &a, &b);  
        ArcNode* s = (ArcNode*)malloc(sizeof(ArcNode));  
        s->adjvex = a;  
        s->nextarc = G.vertices[b].firstarc;  
        G.vertices[b].firstarc = s;  
        s = (ArcNode*)malloc(sizeof(ArcNode));  
        s->adjvex = b;  
        s->nextarc = G.vertices[a].firstarc;  
        G.vertices[a].firstarc = s;  
    }  
    printf("�ڽӱ�����ɡ�\n");  
}  
  
//������ȱ���  
void DFS(ALGraph G, int i){  
    //��iΪ��ʼ��ʼ����  
    printf("%d   ", i);  
    ArcNode *p,*q;  
    visited[i] = 1; //0Ϊ�٣�1Ϊ��  
    p = G.vertices[i].firstarc;  
    while (p){  
        if (!visited[p->adjvex]){  
            DSet[d].start = i;  
            DSet[d].end = p->adjvex;  
            d++;  
            DFS(G, p->adjvex);  
        }  
        p = p->nextarc;  
    }  
}  
  
void DFSTraverse(ALGraph G){  
    int j, i;  
    printf("��������ĸ��㿪ʼ�����������������\n");  
    scanf("%d", &j);  
    printf("���������������˳��Ϊ��");  
//  DSet[d] = j;  
    for (i = 0; i<G.vexnum; i++){  
        visited[i] = 0;  
    }  
    for (i = j; i<G.vexnum; i++){  
        if (!visited[i]){  
            DFS(G, i);  
        }  
    }  
    for (i = 0; i<j; i++){  
        if (!visited[i]){  
            DFS(G, i);  
        }  
    }  
    printf("\n");  
}  
  
void PrintDFTree(ALGraph G){  
    int i = 0;  
    printf("����������ı߼�Ϊ��");  
    for (; i < G.vexnum - 1; i++){  
        printf("(%d,%d)\t",DSet[i].start,DSet[i].end);  
    }  
    printf("\n");  
}  
//������ȱ���  
typedef struct QNode{  
    int data;  
    struct QNode* next;  
}QNode, *QuePtr;  
  
typedef  struct {  
    QuePtr front;  
    QuePtr rear;  
}LinkQue;  
  
  
int Init(LinkQue &Q){  
    Q.front = Q.rear = (QuePtr)malloc(sizeof(QNode));  
    if (!Q.front) return -1;  
    Q.front->next = NULL;  //��Ҫ���˰�ͷ����next�ֶ�����Ϊnull   
    //  printf("success in initializating.\n");  
    return 0;  
}  
  
int enQue(LinkQue &Q, int e){  
    QNode *p = (QNode*)malloc(sizeof(QNode));  
    if (!p) return -1;  
    p->data = e;  
    p->next = NULL;  //������null  
    Q.rear->next = p;  
    Q.rear = p;  
    return 0;  
}  
  
int deQue(LinkQue &Q, int &e){  
    if (Q.front == Q.rear){  
        printf("The queue is empty now.\n");  
        return -1;  
    }  
    QNode* p = Q.front->next;  //Q.front ��һ��û�д���κζ�����ͷ���   
    e = p->data;  
    //printf("The data is %d\n",e);  
    Q.front->next = p->next;  
    if (Q.rear == p) Q.rear = Q.front; //������ֻ��һ��Ԫ�ص���� �Ȱ�rearŲ��ǰ���� Ҫ��Ȼɾ�Ļ���rearҲһ��ɾ����   
    free(p);  
    return 0;  
}  
  
void BFS(ALGraph G, int i){  
    printf("%d  ", i);  
    visited[i] = 1;  
    LinkQue Q;  
    int e;  
    Init(Q);  
    enQue(Q, i);  
    while (Q.front != Q.rear){  
        deQue(Q, i);  
        ArcNode *p = G.vertices[i].firstarc;  
        while (p){  
            if (!visited[p->adjvex]){  
                printf("%d  ", p->adjvex);  
                visited[p->adjvex] = 1;  
                enQue(Q, p->adjvex);  
                BSet[b].start = i;  
                BSet[b].end = p->adjvex;  
                b++;  
            }  
            p = p->nextarc;  
        }  
    }  
}  
  
void BFSTraverse(ALGraph G){  
    int i, j;  
    printf("��������ĸ��㿪ʼ���й������������\n");  
    scanf("%d", &j);  
    printf("���������������˳��Ϊ��\n");  
    for (i = 0; i<G.vexnum; i++){  
        visited[i] = 0;  
    }  
    for (i = j; i<G.vexnum; i++){  
        if (!visited[i]){  
            BFS(G, i);  
        }  
    }  
    for (i = 0; i<j; i++){  
        if (!visited[i]){  
            BFS(G, i);  
        }  
    }  
    printf("\n");  
}  
  
void PrintBFTree(ALGraph G){  
    int i = 0;  
    printf("����������ı߼�Ϊ��\n");  
    for (; i < G.vexnum - 1; i++){  
        printf("(%d,%d)\t", BSet[i].start, BSet[i].end);  
    }  
    printf("\n");  
}  
  
  
int main(){  
    ALGraph G;  
    createGraph(G);  
    DFSTraverse(G);  
    PrintDFTree(G);  
    BFSTraverse(G);  
    PrintBFTree(G);  
    getchar();  
    return 0;
    } 
