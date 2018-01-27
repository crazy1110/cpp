#include<iostream>
using namespace std;
class list{
	public:
		int val;
		class list *next;
};
typedef class list node;
typedef node *link;
class list* head[9];
int run[9];
void dfs(int current)
{
	link ptr;
	run[current] = 1;
	cout<<"["<<current<<"] ";
	ptr=head[current]->next;
	while(ptr!=NULL)
	{
		if(run[ptr->val]==0)
		dfs(ptr->val);
		ptr=ptr->next;
	}
}
int main()
{
	link ptr,newnode;
	int data[18][2]={
	{1,2},{2,1},{1,3},{3,1},
	{2,4},{4,2},{2,5},{5,2},
	{3,6},{6,3},{3,7},{7,3},
	{4,8},{8,4},{5,8},{8,5},
	{6,7},{7,6}};
	for(int i=1;i<=8;i++)
	{
		run[i]=0;	//�������нڵ���δ�������� 
		head[i]=new node;
		head[i]->val=i;	//���ø�������ͷ�ĳ�ֵ 
		head[i]->next=NULL;
		ptr=head[i];    //����ָ��Ϊ����ͷ 
		for(int j=0;j<18;j++)
		{
			if(data[j][0]==i)		//�����������ͷ��ͬ���ͰѶ����������
			{
				newnode = new node;
				newnode->val = data[j][1];
				newnode->next = NULL;
				do{
					ptr->next = newnode;      //�����¶���
					ptr=ptr->next; 
				}while(ptr->next!=NULL);
			 } 
		}
	}
	cout<<"ͼ���ڽӱ����ݣ�"<<endl;
	for(int i=1;i<=8;i++)
	{
		ptr = head[i];
		cout<<"���㣺"<<i<<"=> ";
		ptr=ptr->next;
		while(ptr!=NULL)
		{
			cout<<"["<<ptr->val<<"] ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
	cout<<endl<<endl; 
	cout<<"�����������ͼ�Ľ������Ϊ��"<<endl;
	dfs(1);
	cout<<endl;
}
