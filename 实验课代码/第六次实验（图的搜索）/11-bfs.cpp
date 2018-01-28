#include<iostream>
#include<cstdlib>
# define MAX 10
using namespace std;
int front = -1;  //指向队列的前端
int rear = -1;//指向队列的后端
struct list  //图顶点结构声明 
{
	int x;//顶点数据
	struct list *next;//指向下一个顶点的指针 
};
typedef struct list node;
typedef node *link;
struct GraphLink{
	link first;
	link last;
};
int run[9]; //用来记录各个顶点是否被遍历过
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
 //队列数据的存入
 void enqueue (int value)
 {
 	if(rear>=MAX)
 	return;
 	rear++;
 	queue[rear]=value;
  } 
  //队列数据的取出
  int dequeue()
  {
  	if(front==rear)
  	return -1;
  	front++;
  	return queue[front];
  } 
  //广度优先搜索
  void bfs (int current)
  {
  	link tempnode;//临时的顶点指针
	enqueue(current);//将第一个顶点存入队列
	run[current]=1;//遍历过的顶点设为1
	cout<<"["<<current<<"] ";
	while(front!=rear)
	{
		current=dequeue();//将顶点从队列中取出
		tempnode = Head[current].first;   //先记录目前顶点的位置
		while(tempnode!=NULL)
		{
			if(run[tempnode->x]==0)
			{
				enqueue(tempnode->x);
				run[tempnode->x]=1;//记录遍历过
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
	cout<<"图的邻接表内容："<<endl;
	for(int i=1;i<9;i++)
	{
		run[i]=0;
		cout<<"顶点"<<i<<"=>";
		Head[i].first=NULL;
		Head[i].last=NULL;
		for(j=0;j<18;j++)
		{
			if(Data[j][0]==i)
			{
				//如果起点和链表头相等，就把顶点加入链表
				Datanum = Data[j][1];
				insert(&Head[i],Datanum); 
			}
		}
		print(Head[i]);
	}
	cout<<endl<<endl;
	cout<<"图的广度优先搜索序列为："<<endl;
	for(int i=1;i<=8;i++)
	cout<<"["<<i<<"] ";
	bfs[1];
	cout<<endl;
	return 0;
}
