#include <stdio.h>  
#include <iostream>   
#include<stdlib.h>   
using namespace std;  
#define size 100     
typedef struct {          //定义队列    
 char data[size];     
 int  front;     
 int  rear;     
}queue;      
    
void initq(queue *q)      //初始化队列    
{     
  q->front=q->rear=0;                                
}                              
     
void inq(queue *q,char e)            //入队    
{    
    q->data[q->rear]=e;                    
    q->rear=(q->rear+1);                  
}                         
     
char outq(queue *q)         //出队列   
{     
  char f;     
  if(q->front==q->rear)                     
   {     
     printf("队列为空\n");        
     return 0;     
   }     
   else     
   {     
     f=q->data[q->front];       
     q->front=(q->front+1);                
     return f;     
   }     
}                      
      
typedef struct          //定义栈    
 {     
  char data[size];     
  int  top;     
}strack;        
    
void inits(strack *s)      //初始化栈    
{     
  s->top=0;     
}                             
    
int judge(strack *s)        //判断栈是否为空    
{     
  if(s->top==0)                                
    return 0;       
  else       
    return 1;                  
}                            
void ins(strack *s,char x)  //入栈    
{                                                    
     s->data[++s->top]=x;                     
}                           
    
char outs(strack *s)        //出栈    
{     
  char y;     
  if(s->top==0)                              
  {     
    printf("栈空\n");        
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
  cout<<"输入一个字符串，注意以.结束："<<endl;                                 
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
  while(judge(s)) //当栈不为空时             
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
    cout<<"输入的字符串为回文数！"<<endl;    
  else     
    cout<<"输入的字符串不是回文数！"<<endl;   
  return 0;    
}     
