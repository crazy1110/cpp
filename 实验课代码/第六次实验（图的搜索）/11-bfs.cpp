#include<iostream>
#include<cstdlib>
# define MAX 10
using namespace std;
int front = -1;  //ָ����е�ǰ��
int rear = -1;//ָ����еĺ��
struct list  //ͼ����ṹ���� 
{
	int x;//��������
	struct list *next;//ָ����һ�������ָ�� 
};
typedef struct list node;
typedef node *link;
struct GraphLink{
	link first;
	link last;
};
int run[9]; //������¼���������Ƿ񱻱�����
int queue[MAX];
struct GraphLink Head[9];
void print(struct GraphLink temp)
{
	link current = temp.first;
	while(current!=NULL)
	{
		cout<<"["<<current->x<<"] ";
		current=current->next;
	}
	cout<<endl;
 } 
 void insert(struct GraphLink *temp,int x)
 {
 	link newNode;
 	newNode = new node;
 	newNode->x=x;
 	newNode->next=NULL;
 	if(temp->first==NULL)
 	{
 		temp->first=newNode;
 		temp->last=newNode;
	 }
	 else 
	 {
	 	temp->last->next=newNode;
	 	temp->last=newNode;
	  } 
 }
 //�������ݵĴ���
 void enqueue (int value)
 {
 	if(rear>=MAX)
 	return;
 	rear++;
 	queue[rear]=value;
  } 
  //�������ݵ�ȡ��
  int dequeue()
  {
  	if(front==rear)
  	return -1;
  	front++;
  	return queue[front];
  } 
  //�����������
  void bfs (int current)
  {
  	link tempnode;//��ʱ�Ķ���ָ��
	enqueue(current);//����һ������������
	run[current]=1;//�������Ķ�����Ϊ1
	cout<<"["<<current<<"] ";
	while(front!=rear)
	{
		current=dequeue();//������Ӷ�����ȡ��
		tempnode = Head[current].first;   //�ȼ�¼Ŀǰ�����λ��
		while(tempnode!=NULL)
		{
			if(run[tempnode->x]==0)
			{
				enqueue(tempnode->x);
				run[tempnode->x]=1;//��¼������
				cout<<"["<<tempnode->x<<"] "; 
			}
			tempnode=tempnode->next;
		 } 
	 } 
   } 
int main()
{
	int Data[18][2]={
	{1,2},{2,1},{1,3},{3,1},
	{2,4},{4,2},{2,5},{5,2},
	{3,6},{6,3},{3,7},{7,3},
	{4,8},{8,4},{5,8},{8,5},
	{6,7},{7,6}};
	int Datanum;
	int i,j;
	cout<<"ͼ���ڽӱ����ݣ�"<<endl;
	for(int i=1;i<9;i++)
	{
		run[i]=0;
		cout<<"����"<<i<<"=>";
		Head[i].first=NULL;
		Head[i].last=NULL;
		for(j=0;j<18;j++)
		{
			if(Data[j][0]==i)
			{
				//�����������ͷ��ȣ��ͰѶ����������
				Datanum = Data[j][1];
				insert(&Head[i],Datanum); 
			}
		}
		print(Head[i]);
	}
	cout<<endl<<endl;
	cout<<"ͼ�Ĺ��������������Ϊ��"<<endl;
	for(int i=1;i<=8;i++)
	cout<<"["<<i<<"] ";
	bfs[1];
	cout<<endl;
	return 0;
}
