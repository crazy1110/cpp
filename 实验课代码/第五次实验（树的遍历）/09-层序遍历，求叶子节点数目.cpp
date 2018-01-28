#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 30
typedef char ElemType;
typedef struct TNode *BiTree;
struct TNode{
	char data;
	BiTree lchild;
	BiTree rchild;
}; 
int IsEmpty(BiTree *T){
	if(*T == NULL)
	return 1;
	else return 0;
}
void CreatTree(BiTree *T){
	char ch;
	ch = getchar();
	if(ch == '#')
	*T = NULL;
	//创建结点
	else{
		*T = (BiTree)malloc(sizeof(struct TNode));
		//创建结点 
		(*T)->data=ch;
		//生成左子树
		CreatTree(&(*T)->lchild);
		//生成右子树
		CreatTree(&(*T)->rchild);
	} 
} 

int LeafNumber(BiTree T,int &num){
	if(T){
		if(T->lchild == NULL && T->rchild==NULL)
		{
			num++;
			cout<<T->data<<" ";
		}
		LeafNumber(T->lchild,num);
		LeafNumber(T->rchild,num);
	}
	return num;
}
//层序遍历要使用队列 
void LevelOrder(BiTree T){
	int front = 0;
	int rear = 0;
	BiTree queue[MAX];
	BiTree tempNode;
	if(!IsEmpty(&T)){
		queue[rear++] = T;
		while(front != rear){
			tempNode = queue[front++];
			if(!IsEmpty(&(tempNode->lchild)))
			queue[rear++] = tempNode->lchild; 
			
			if(!IsEmpty(&(tempNode->rchild)))
			queue[rear++] = tempNode->rchild;
			cout<<tempNode->data<<" ";
		}
	}
}  
int main()
{
	BiTree T;
	BiTree *p=(BiTree*)malloc(sizeof(BiTree));
	int num=0;
	CreatTree(&T);
	cout<<"层序遍历的输出序列为："<<endl;
	LevelOrder(T);
	cout<<endl;
	cout<<"叶子结点如下："<<endl;
	LeafNumber(T,num);
	cout<<endl;
	cout<<"叶子结点的个数为："<<num<<endl;
	return 0;
}
