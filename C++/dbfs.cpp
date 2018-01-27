#include<stdio.h>  
#include<stdlib.h>  
  
int visited[20];  
  
typedef struct ArcNode{  
    int adjvex;  //邻接点域   
    struct ArcNode * nextarc;  //指向下一个邻接点的指针域   
};  
  
typedef struct VNode{ //表头节点   
    int data;  //顶点信息   
    ArcNode *firstarc;   //指向第一条依附该顶点的弧的指针   
}VNode, AdjList[20];  
  
typedef struct{  
    AdjList vertices;  
    int vexnum, arcnum;  
}ALGraph;  
  
typedef struct{  
    int start;  
    int end;  
}Arc;  
  
Arc BSet[20];    //广度优先搜索生成的边的边集  
Arc DSet[20];   //深度优先搜索生成的边的边集  
int b = 0;  //广度优先搜索边集的index  
int d = 0;  //深度优先搜索边集的index  
  
void createGraph(ALGraph &G){  
    printf("请输入图的顶点的个数。\n");  
    scanf("%d", &G.vexnum);  
    printf("请输入图的边的个数。\n");  
    scanf("%d", &G.arcnum);  
    printf("请输入顶点的信息。\n");  
    for (int i = 0; i<G.vexnum; i++){  
        scanf("%d", &((G.vertices[i]).data));  
        G.vertices[i].firstarc = NULL;  
    }  
    printf("请输入边的信息\n");  
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
    printf("邻接表创建完成。\n");  
}  
  
//深度优先遍历  
void DFS(ALGraph G, int i){  
    //以i为开始开始遍历  
    printf("%d   ", i);  
    ArcNode *p,*q;  
    visited[i] = 1; //0为假，1为真  
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
    printf("请输入从哪个点开始进行深度优先搜索。\n");  
    scanf("%d", &j);  
    printf("深度优先搜索遍历顺序为：");  
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
    printf("深度生成树的边集为：");  
    for (; i < G.vexnum - 1; i++){  
        printf("(%d,%d)\t",DSet[i].start,DSet[i].end);  
    }  
    printf("\n");  
}  
//广度优先遍历  
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
    Q.front->next = NULL;  //不要忘了把头结点的next手动定义为null   
    //  printf("success in initializating.\n");  
    return 0;  
}  
  
int enQue(LinkQue &Q, int e){  
    QNode *p = (QNode*)malloc(sizeof(QNode));  
    if (!p) return -1;  
    p->data = e;  
    p->next = NULL;  //别忘了null  
    Q.rear->next = p;  
    Q.rear = p;  
    return 0;  
}  
  
int deQue(LinkQue &Q, int &e){  
    if (Q.front == Q.rear){  
        printf("The queue is empty now.\n");  
        return -1;  
    }  
    QNode* p = Q.front->next;  //Q.front 是一个没有存放任何东西的头结点   
    e = p->data;  
    //printf("The data is %d\n",e);  
    Q.front->next = p->next;  
    if (Q.rear == p) Q.rear = Q.front; //队列中只有一个元素的情况 先把rear挪到前面来 要不然删的话把rear也一起删掉了   
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
    printf("请输入从哪个点开始进行广度优先搜索。\n");  
    scanf("%d", &j);  
    printf("广度优先搜索遍历顺序为：\n");  
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
    printf("广度生成树的边集为：\n");  
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
