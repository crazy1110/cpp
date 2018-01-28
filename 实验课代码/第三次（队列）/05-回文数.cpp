#include <stdio.h>  
#include <iostream>   
#include<stdlib.h>   
using namespace std;  
#define size 100     
typedef struct {          //�������    
 char data[size];     
 int  front;     
 int  rear;     
}queue;      
    
void initq(queue *q)      //��ʼ������    
{     
  q->front=q->rear=0;                                
}                              
     
void inq(queue *q,char e)            //���    
{    
    q->data[q->rear]=e;                    
    q->rear=(q->rear+1);                  
}                         
     
char outq(queue *q)         //������   
{     
  char f;     
  if(q->front==q->rear)                     
   {     
     printf("����Ϊ��\n");        
     return 0;     
   }     
   else     
   {     
     f=q->data[q->front];       
     q->front=(q->front+1);                
     return f;     
   }     
}                      
      
typedef struct          //����ջ    
 {     
  char data[size];     
  int  top;     
}strack;        
    
void inits(strack *s)      //��ʼ��ջ    
{     
  s->top=0;     
}                             
    
int judge(strack *s)        //�ж�ջ�Ƿ�Ϊ��    
{     
  if(s->top==0)                                
    return 0;       
  else       
    return 1;                  
}                            
void ins(strack *s,char x)  //��ջ    
{                                                    
     s->data[++s->top]=x;                     
}                           
    
char outs(strack *s)        //��ջ    
{     
  char y;     
  if(s->top==0)                              
  {     
    printf("ջ��\n");        
    return '0';       
  }    
  else                                     
  {         
    y=s->data[s->top];                       
    s->top--;                           
    return y;     
  }     
}                       
    
int  main()                 
{     
  cout<<"����һ���ַ�����ע����.������"<<endl;                                 
  char c;     
  int flag=0;     
  strack *s=(strack *)malloc(sizeof(strack));     
  queue *q=(queue *)malloc(sizeof(queue));     
  inits(s);         initq(q);        
  while((c=getchar())!='.')     
  {    
    ins(s,c);                
    inq(q,c);     
  }     
  while(judge(s)) //��ջ��Ϊ��ʱ             
   {     
     if(outs(s)==outq(q))     
     {     
      flag=1;                     
      continue;                
     }     
     else                       
     {     
      flag=0;     
      break;                     
     }     
   }     
   if(flag==1)     
    cout<<"������ַ���Ϊ��������"<<endl;    
  else     
    cout<<"������ַ������ǻ�������"<<endl;   
  return 0;    
}     
