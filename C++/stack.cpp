#include<bits/stdc++.h>
using namespace std;
#define OVERFLOW -2
typedef struct sqstack
{
	int *base;
	int *top;
	int size;
}sqstack;
//构建一个栈 
void Initstack(sqstack &s)
{
	s.base = (int *)malloc(100*sizeof(int));
	if(!s.base)
	exit (OVERFLOW);
	s.top=s.base;
	s.size=100;
}
//入栈操作
int push(sqstack &s,int e)
{
	if(s.top-s.base>=s.size)
	{
		s.base=(int *)realloc(s.base,(s.size+100)*sizeof(int));
		if(!s.base)
		return 0;
		s.top=s.base+s.size;
		s.size+=100; 
		}
		//试试看	
		*s.top=e;
		s.top++;
		
	//	*s.top++ = e;
		return 1;
} 
//出栈操作
int pop(sqstack &s,int *e)
{
	if(s.top==s.base)
	return 0;
	*e = *--s.top;
	return 1;
 } 
 //判断栈是否为空
int stackEmpty(sqstack &s)
{
	if(s.base==s.top)
	return 1;
	else
	return 0;
}
//进制转化函数
void conversion(sqstack s)
{
	int n,e;
	Initstack(s);
	cout<<"请输入一个十进制整数："<<endl;
	cin>>n;
	while(n)
	{
		push(s,n%2);
		n/=2;
	}
	while(!stackEmpty(s))
	{
		pop(s,&e);
		cout<<e;
	}
 } 
//主函数
int main()
{
	sqstack *s;
	s = (sqstack*) malloc(sizeof(sqstack));
	conversion(*s);
	free(s);
	return 0;
 } 
