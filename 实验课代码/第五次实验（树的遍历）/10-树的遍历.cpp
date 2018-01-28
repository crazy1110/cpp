#include<iostream>
#include<iomanip>
using namespace std;
class tree		//�ڵ㶨�� 
{     
	public:
	int data;
	class tree *left,*right;
};
typedef class tree node;
typedef node *btree;
btree creat_tree(btree root,int val)//���������� 
{
	btree newnode,current,backup;
	newnode = new node;
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	else 
	{
		for(current=root;current!=NULL;)
		{
			backup=current;
			if(current->data > val)
			current=current->left;
			else
			current=current->right;
		}
		if(backup->data > val)
		backup->left=newnode;
		else
		backup->right=newnode;
	}
	return root;
}
void pre(btree ptr)
{
	if(ptr!=NULL)
	{
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		pre(ptr->left);
		pre(ptr->right);
	}
}
void in(btree ptr)
{
	if(ptr!=NULL)
	{
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}
void post(btree ptr)
{
	if(ptr!=NULL)
	{
		post(ptr->left);
		post(ptr->right);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
	}
}
int main()
{
	int arr[]={7,4,1,5,16,8,11,12,15,9,2};
	btree ptr=NULL;
	cout<<"[ԭʼ��������]"<<endl;
	for(int i=0;i<11;i++)
	{
		ptr=creat_tree(ptr,arr[i]);
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"[�������ı�����������]"<<endl;
	cout<<"ǰ����������"<<endl;
	pre(ptr);
	cout<<endl;
	cout<<"������������"<<endl;
	in(ptr);
	cout<<endl;
	cout<<"������������"<<endl;
	post(ptr);
	cout<<endl;
	return 0;
}
