#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int num,pw;
	struct Node *next;
}*head,*p,*q;
//先把n个密码输入，将密码存放在pw中 
void password(int n)
{
	int i,mm;
	cout<<"请把n个人的密码逐个输入："<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>mm;
		q->num=i;
		q->pw=mm;
		q=q->next;
	}
	q=p;
}
//建立一个循环链表 
void creatLinkList(int n)
{
	head=(struct Node*)malloc(sizeof(struct Node));
	p=head;
	for(int i=1;i<n;i++)
	{
		q=(struct Node*)malloc(sizeof(struct Node));
		p->next=q;
		p=q;
	}
	p->next=head;
	q=head;
} 
//将出环形队列的人的序号打印出来 
void print(int m,int n)
{
	int i,j;
	for(i=1;i<=n;i++)	//所有人均出列，因此循环n次 
	{
		for(j=1;j<m;j++)
		q=q->next;
		
		p=q->next;
		m=p->pw;
		cout<<p->num<<" ";
		q->next=p->next;
		free(p);
	}
 } 
 int main()
 {
 	int m,n;
 	cout<<"请输入初始密码m和总人数n："<<endl;
 	cin>>m>>n;
 	creatLinkList(n);
 	password(n);
 	cout<<"出队的顺序是："<<endl;
 	print(m,n);
 }
