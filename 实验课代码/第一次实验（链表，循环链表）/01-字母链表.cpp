#include<bits/stdc++.h>
using namespace std;
#define null 0
typedef char Element; 
typedef struct Node
{ 
    Element data; 
    struct Node *next; 
}List,LNode; 
//���� 
void insert(List *linklist,Element e,int i)
{ 
    int j=0; 
    LNode *addnode=(LNode *)malloc(sizeof(LNode)); 
    addnode->data=e; 
    if(i==1) 
    { 
        addnode->next=linklist->next; 
        linklist->next=addnode; 
    } 
    else 
    { 
        for(j=1;(j<i && linklist);j++) 
            linklist=linklist->next; 
        if(!linklist) 
            cout<<"����ʧ��"<<endl;
        else 
        { 
            addnode->next=linklist->next; 
            linklist->next=addnode; 
        } 
    } 
} 
//ɾ�� 
bool deletenode(List *linklist,int i)
{ 
    int j; 
    LNode *denode; 
    for(j=1;(j<i && linklist->next);j++) 
        linklist=linklist->next; 
    if(!linklist->next) 
        return false; 
    else 
    { 
        denode=linklist->next; 
        linklist->next=denode->next; 
        free(denode); 
        return true; 
    } 
} 
//��������ĳ��� 
int Length(List *linklist)
{ 
    int len; 
    for(len=0;linklist->next;len++) 
        linklist=linklist->next; 
    return len; 
} 
//���� 
int find(List *linklist,int i)
{ 
    int j; 
    for(j=1;(j<=i && linklist);j++) 
        linklist=linklist->next; 
    if(!linklist) 
	return 0; 
    else return linklist->data; 
} 

//��������� 
void show(List *linklist)
{ 
    linklist=linklist->next; 
    for(;linklist;linklist=linklist->next)
	cout<<linklist->data<<" "; 
} 

int main() 
{ 
	char i,ch; 
    List letters; 
    LNode head={0,null}; 
    letters=head; 
    for(i='a';i<='z';i++) 
    insert(&letters,i,(int)(i-'a'+1)); 
    
    cout<<"��ĸ��ĳ���Ϊ��"<<Length(&letters)<<endl;

    insert(&letters,'B',2); 
    
    deletenode(&letters,3);
    
   /* if(!deletenode(&letters,3)) 
    cout<<"��ɾ�������޷����У��������Ҫɾ���Ľڵ��Ƿ����:"<<endl;*/
    
    if(ch=find(&letters,6)) 
    cout<<"��Ҫ���ҵĽڵ�Ԫ����:"<<ch<<endl;
    else  
    cout<<"���Ҳ���ʧ�ܣ�����Ҫ���ҵ�Ԫ��λ���Ƿ����"<<endl; 

	cout<<"���в���֮��ı�ĳ���Ϊ��"<<Length(&letters)<<endl;

    cout<<"���ڱ��еĸ���Ԫ�����£�"<<endl; 
	show(&letters); 
}
