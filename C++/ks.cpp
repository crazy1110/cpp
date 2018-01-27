#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 #include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()52
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream> // cout,cin
 using namespace std;
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 #define MAX_NAME 10 
 /* �����ַ�������󳤶�*/
 #define MAXCLASS 100
 int Z=0;
 int X=0;
 int xqzs,q=1,xfsx;
 typedef int InfoType;
 typedef char VertexType[MAX_NAME]; /* �ַ�������*/
 /* ͼ���ڽӱ�洢��ʾ*/
 #define MAX_VERTEX_NUM 100
 typedef enum{DG}GraphKind; /* {����ͼ,������,����ͼ,������} */
 typedef struct ArcNode
 {
   int adjvex; /* �û���ָ��Ķ����λ��*/
   struct ArcNode *nextarc; /* ָ����һ������ָ��*/
   InfoType *info; /* ����Ȩֵָ�룩*/
 }ArcNode; /* ����*/
 typedef struct
 {
   VertexType data; /* ������Ϣ*/
   ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��*/
 }VNode,AdjList[MAX_VERTEX_NUM]; /* ͷ���*/

 typedef struct
 {
   AdjList vertices,verticestwo;
   int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ���*/
   int kind; /* ͼ�������־*/
 }ALGraph;
/*  ͼ���ڽӱ�洢�Ļ�������*/
 int LocateVex(ALGraph G,VertexType u)
{ /* ��ʼ����: ͼG����,u��G�ж�������ͬ����*/
   /* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vertices[i].data)==0)
       return i;
   return -1;
}
Status CreateGraph(ALGraph *G)
 { /* �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼG(��һ������������ͼ) */
   int i,j,k;
   VertexType va,vb;
   ArcNode *p;
   
   printf("�������ѧ�ƻ��Ŀγ���: ");
   scanf("%d",&(*G).vexnum);
   printf("�����������������γɵĿγ����޹�ϵ�ı���: ");
   scanf("%d",&(*G).arcnum);
   printf("������%d���γ̵Ĵ���ֵ(<%d���ַ�):\n",(*G).vexnum,MAX_NAME);
   for(i=0;i<(*G).vexnum;++i) /* ���춥������*/
   { scanf("%s",(*G).vertices[i].data);
     (*G).vertices[i].firstarc=NULL;
   }
   printf("������%d���γ̵�ѧ��ֵ(<%d���ַ�):\n",(*G).vexnum,MAX_NAME);
   for(i=0;i<(*G).vexnum;++i) /* ���춥������*/
   {scanf("%s",(*G).verticestwo[i].data);
   }
   printf("��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n");
   for(k=0;k<(*G).arcnum;++k) /* �����������*/
   { scanf("%s%s",va,vb);
     i=LocateVex(*G,va); /* ��β*/
     j=LocateVex(*G,vb); /* ��ͷ*/
     p=(ArcNode*)malloc(sizeof(ArcNode));
     p->adjvex=j;
     p->info=NULL; /* ͼ*/
     p->nextarc=(*G).vertices[i].firstarc; /* ���ڱ�ͷ*/

     (*G).vertices[i].firstarc=p;
    }
   return OK;
 }
void Display(ALGraph G)
 { /* ���ͼ���ڽӾ���G */
   int i;
   ArcNode *p;
   switch(G.kind)
   {case DG: printf("����ͼ\n");
   }
   printf("%d�����㣺\n",G.vexnum);
   for(i=0;i<G.vexnum;++i)
     printf("%s ",G.vertices[i].data);
   printf("\n%d����(��):\n",G.arcnum);
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertices[i].firstarc;
     while(p)
     {printf("%s��%s  ",G.vertices[i].data,G.vertices[p->adjvex].data);
      p=p->nextarc;
     }
     printf("\n");
   }
 }
void FindInDegree(ALGraph G,int indegree[])
 { /* �󶥵����ȣ��㷨����*/
   int i;
   ArcNode *p;
   for(i=0;i<G.vexnum;i++)
     indegree[i]=0; /* ����ֵ*/
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertices[i].firstarc;
     while(p)
     { indegree[p->adjvex]++;
       p=p->nextarc;
     }
   }
 }
 typedef int SElemType; /* ջ����*/
 /*ջ��˳��洢��ʾ*/
 #define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������*/
 #define STACKINCREMENT 2 /* �洢�ռ��������*/

 typedef struct SqStack
 {
   SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   SElemType *top; /* ջ��ָ��*/
   int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ*/
 }SqStack; /* ˳��ջ*/
 /* ˳��ջ�Ļ�������*/
 Status InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* �洢����ʧ��*/
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
}

void ClearStack(SqStack *S)  //���ջ�Ĳ���
{
	S->top=S->base;
}

Status StackEmpty(SqStack S)
 { /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
}
 Status Pop(SqStack *S,SElemType *e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if((*S).top==(*S).base)
     return ERROR;
   *e=*--(*S).top;
   return OK;
 }


 
 Status Push(SqStack *S,SElemType e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ��*/
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ�*/
   {


     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof

(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* �洢����ʧ��*/
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return OK;
 }
typedef int pathone[MAXCLASS];
typedef int pathtwo[MAXCLASS];
Status TopologicalSort(ALGraph G)
 { /* ����ͼG�����ڽӱ�洢�ṹ����G�޻�·,�����G�Ķ����һ���������в�����OK, */
   /* ���򷵻�ERROR��*/
   int i,k,j=0,count,indegree[MAX_VERTEX_NUM];
   bool has=false;
   SqStack S;
   pathone a;
   pathtwo b;
   ArcNode *p;
   FindInDegree(G,indegree); /* �Ը����������indegree[0..vernum-1] */
   InitStack(&S); /* ��ʼ��ջ*/
   for(i=0;i<G.vexnum;++i) /* ������ȶ���ջS */
     if(!indegree[i])
	 { Push(&S,i); 
		//cout<<*G.vertices[i].data<<endl;
	 }
	 /* ���Ϊ�߽�ջ*/
   count=0; /* ������������*/
   while(!StackEmpty(S))
   { /* ջ����*/
     Pop(&S,&i);
     a[i]=*G.vertices[i].data;
     b[i]=*G.verticestwo[i].data;
     printf("�γ�%s��ѧ��%s  ",G.vertices[i].data,G.verticestwo[i].data); 
  /* ���i�Ŷ��㲢����*/
     ++count;
     for(p=G.vertices[i].firstarc;p;p=p->nextarc)
     { /* ��i�Ŷ����ÿ���ڽӵ����ȼ�*/
       k=p->adjvex;

       if(!(--indegree[k])) /* ����ȼ�Ϊ,����ջ*/
	   {Push(&S,k);
		//cout<<*G.vertices[i].data<<endl;
	   }
     }
   }
   if(count<G.vexnum)
   {printf("������ͼ�л�·\n");
    return ERROR;
   }
   else
   {printf("Ϊһ���������С�\n");
	has=true;
   }
	  
     FindInDegree(G,indegree); /* �Ը����������indegree[0..vernum-1] */
	 ClearStack(&S);
	 cout<<"======================�γ̼ƻ�����==============================="<<endl;
	 int qq=1; //ѧ����
	 int xxf;
	 while(qq<=xqzs)
	 {		
		 int result[20];
		 int rtop=0;
		 int nn=0;
		 //int ccount=0;
		   // ѧ��ѧ�ּ���
		 xxf=0;
		 for(i=0;i<G.vexnum;++i) /* ������ȶ���ջS */
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
			{ /* ��i�Ŷ����ÿ���ڽӵ����ȼ�*/
				k=p->adjvex;
				indegree[k]--;
				/* if(!(--indegree[k])) ����ȼ�Ϊ,����ջ
				{
					Push(&S,k);
				}*/
			}
			result[rtop]=i;
			rtop++;
		 }
		 cout<<"��"<<qq<<"��"<<"ѧ�ڵĿγ�Ϊ��"<<endl;
		 for(nn=0;nn<rtop;nn++)
		 {
			cout<<"�γ�"<<G.vertices[result[nn]].data<<endl;
		 }
		 qq++;
	 }
return OK;
}
int main()
{  ALGraph f;
   printf("��ѧ�ƻ��������������ģ��Ϊ��������AOV-���ṹ��\n");
   printf("����Ϊ��ѧ�ƻ����������������:\n");
   printf("������ѧ������:");
   scanf("%d",&xqzs);
   printf("������ѧ�ڵ�ѧ������:");
   scanf("%d",&xfsx);
   CreateGraph(&f);
   Display(f);
   TopologicalSort(f);
}


