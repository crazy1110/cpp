#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int num,pw;
	struct Node *next;
}*head,*p,*q;
//�Ȱ�n���������룬����������pw�� 
void password(int n)
{
	int i,mm;
	cout<<"���n���˵�����������룺"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>mm;
		q->num=i;
		q->pw=mm;
		q=q->next;
	}
	q=p;
}
//����һ��ѭ������ 
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
//�������ζ��е��˵���Ŵ�ӡ���� 
void print(int m,int n)
{
	int i,j;
	for(i=1;i<=n;i++)	//�����˾����У����ѭ��n�� 
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
 	cout<<"�������ʼ����m��������n��"<<endl;
 	cin>>m>>n;
 	creatLinkList(n);
 	password(n);
 	cout<<"���ӵ�˳���ǣ�"<<endl;
 	print(m,n);
 }
