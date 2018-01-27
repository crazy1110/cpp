#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 #include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()52
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream> // cout,cin
 using namespace std;
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
 #define MAX_NAME 10 
 /* 顶点字符串的最大长度*/
 #define MAXCLASS 100
 int Z=0;
 int X=0;
 int xqzs,q=1,xfsx;
 typedef int InfoType;
 typedef char VertexType[MAX_NAME]; /* 字符串类型*/
 /* 图的邻接表存储表示*/
 #define MAX_VERTEX_NUM 100
 typedef enum{DG}GraphKind; /* {有向图,有向网,无向图,无向网} */
 typedef struct ArcNode
 {
   int adjvex; /* 该弧所指向的顶点的位置*/
   struct ArcNode *nextarc; /* 指向下一条弧的指针*/
   InfoType *info; /* 网的权值指针）*/
 }ArcNode; /* 表结点*/
 typedef struct
 {
   VertexType data; /* 顶点信息*/
   ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针*/
 }VNode,AdjList[MAX_VERTEX_NUM]; /* 头结点*/

 typedef struct
 {
   AdjList vertices,verticestwo;
   int vexnum,arcnum; /* 图的当前顶点数和弧数*/
   int kind; /* 图的种类标志*/
 }ALGraph;
/*  图的邻接表存储的基本操作*/
 int LocateVex(ALGraph G,VertexType u)
{ /* 初始条件: 图G存在,u和G中顶点有相同特征*/
   /* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vertices[i].data)==0)
       return i;
   return -1;
}
Status CreateGraph(ALGraph *G)
 { /* 采用邻接表存储结构,构造没有相关信息的图G(用一个函数构造种图) */
   int i,j,k;
   VertexType va,vb;
   ArcNode *p;
   
   printf("请输入教学计划的课程数: ");
   scanf("%d",&(*G).vexnum);
   printf("请输入拓扑排序所形成的课程先修关系的边数: ");
   scanf("%d",&(*G).arcnum);
   printf("请输入%d个课程的代表值(<%d个字符):\n",(*G).vexnum,MAX_NAME);
   for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量*/
   { scanf("%s",(*G).vertices[i].data);
     (*G).vertices[i].firstarc=NULL;
   }
   printf("请输入%d个课程的学分值(<%d个字符):\n",(*G).vexnum,MAX_NAME);
   for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量*/
   {scanf("%s",(*G).verticestwo[i].data);
   }
   printf("请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n");
   for(k=0;k<(*G).arcnum;++k) /* 构造表结点链表*/
   { scanf("%s%s",va,vb);
     i=LocateVex(*G,va); /* 弧尾*/
     j=LocateVex(*G,vb); /* 弧头*/
     p=(ArcNode*)malloc(sizeof(ArcNode));
     p->adjvex=j;
     p->info=NULL; /* 图*/
     p->nextarc=(*G).vertices[i].firstarc; /* 插在表头*/

     (*G).vertices[i].firstarc=p;
    }
   return OK;
 }
void Display(ALGraph G)
 { /* 输出图的邻接矩阵G */
   int i;
   ArcNode *p;
   switch(G.kind)
   {case DG: printf("有向图\n");
   }
   printf("%d个顶点：\n",G.vexnum);
   for(i=0;i<G.vexnum;++i)
     printf("%s ",G.vertices[i].data);
   printf("\n%d条弧(边):\n",G.arcnum);
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertices[i].firstarc;
     while(p)
     {printf("%s→%s  ",G.vertices[i].data,G.vertices[p->adjvex].data);
      p=p->nextarc;
     }
     printf("\n");
   }
 }
void FindInDegree(ALGraph G,int indegree[])
 { /* 求顶点的入度，算法调用*/
   int i;
   ArcNode *p;
   for(i=0;i<G.vexnum;i++)
     indegree[i]=0; /* 赋初值*/
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertices[i].firstarc;
     while(p)
     { indegree[p->adjvex]++;
       p=p->nextarc;
     }
   }
 }
 typedef int SElemType; /* 栈类型*/
 /*栈的顺序存储表示*/
 #define STACK_INIT_SIZE 10 /* 存储空间初始分配量*/
 #define STACKINCREMENT 2 /* 存储空间分配增量*/

 typedef struct SqStack
 {
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针*/
   int stacksize; /* 当前已分配的存储空间，以元素为单位*/
 }SqStack; /* 顺序栈*/
 /* 顺序栈的基本操作*/
 Status InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* 存储分配失败*/
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
}

void ClearStack(SqStack *S)  //清空栈的操作
{
	S->top=S->base;
}

Status StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
}
 Status Pop(SqStack *S,SElemType *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
   if((*S).top==(*S).base)
     return ERROR;
   *e=*--(*S).top;
   return OK;
 }


 
 Status Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素*/
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间*/
   {


     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof

(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* 存储分配失败*/
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return OK;
 }
typedef int pathone[MAXCLASS];
typedef int pathtwo[MAXCLASS];
Status TopologicalSort(ALGraph G)
 { /* 有向图G采用邻接表存储结构。若G无回路,则输出G的顶点的一个拓扑序列并返回OK, */
   /* 否则返回ERROR。*/
   int i,k,j=0,count,indegree[MAX_VERTEX_NUM];
   bool has=false;
   SqStack S;
   pathone a;
   pathtwo b;
   ArcNode *p;
   FindInDegree(G,indegree); /* 对各顶点求入度indegree[0..vernum-1] */
   InitStack(&S); /* 初始化栈*/
   for(i=0;i<G.vexnum;++i) /* 建零入度顶点栈S */
     if(!indegree[i])
	 { Push(&S,i); 
		//cout<<*G.vertices[i].data<<endl;
	 }
	 /* 入度为者进栈*/
   count=0; /* 对输出顶点计数*/
   while(!StackEmpty(S))
   { /* 栈不空*/
     Pop(&S,&i);
     a[i]=*G.vertices[i].data;
     b[i]=*G.verticestwo[i].data;
     printf("课程%s→学分%s  ",G.vertices[i].data,G.verticestwo[i].data); 
  /* 输出i号顶点并计数*/
     ++count;
     for(p=G.vertices[i].firstarc;p;p=p->nextarc)
     { /* 对i号顶点的每个邻接点的入度减*/
       k=p->adjvex;

       if(!(--indegree[k])) /* 若入度减为,则入栈*/
	   {Push(&S,k);
		//cout<<*G.vertices[i].data<<endl;
	   }
     }
   }
   if(count<G.vexnum)
   {printf("此有向图有回路\n");
    return ERROR;
   }
   else
   {printf("为一个拓扑序列。\n");
	has=true;
   }
	  
     FindInDegree(G,indegree); /* 对各顶点求入度indegree[0..vernum-1] */
	 ClearStack(&S);
	 cout<<"======================课程计划如下==============================="<<endl;
	 int qq=1; //学期数
	 int xxf;
	 while(qq<=xqzs)
	 {		
		 int result[20];
		 int rtop=0;
		 int nn=0;
		 //int ccount=0;
		   // 学期学分计算
		 xxf=0;
		 for(i=0;i<G.vexnum;++i) /* 建零入度顶点栈S */
		 {	 if(0==indegree[i])
			 { 
				Push(&S,i); 
			 }
		 }
		 while(!StackEmpty(S))
		 {
			int bb;
			Pop(&S,&i);
			bb=atoi(G.verticestwo[i].data);
			xxf=xxf+bb;
			if(xxf>xfsx)
			{
				break;

			}
			indegree[i]--;
			for(p=G.vertices[i].firstarc;p;p=p->nextarc)
			{ /* 对i号顶点的每个邻接点的入度减*/
				k=p->adjvex;
				indegree[k]--;
				/* if(!(--indegree[k])) 若入度减为,则入栈
				{
					Push(&S,k);
				}*/
			}
			result[rtop]=i;
			rtop++;
		 }
		 cout<<"第"<<qq<<"个"<<"学期的课程为："<<endl;
		 for(nn=0;nn<rtop;nn++)
		 {
			cout<<"课程"<<G.vertices[result[nn]].data<<endl;
		 }
		 qq++;
	 }
return OK;
}
int main()
{  ALGraph f;
   printf("教学计划编制问题的数据模型为拓扑排序AOV-网结构。\n");
   printf("以下为教学计划编制问题的求解过程:\n");
   printf("请输入学期总数:");
   scanf("%d",&xqzs);
   printf("请输入学期的学分上限:");
   scanf("%d",&xfsx);
   CreateGraph(&f);
   Display(f);
   TopologicalSort(f);
}


