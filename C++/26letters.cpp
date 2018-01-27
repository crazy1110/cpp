#include<bits/stdc++.h>
using namespace std;
#define null 0
typedef char Element; 
typedef struct Node
{ 
    Element data; 
    struct Node *next; 
}List,LNode; 
//插入 
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
            cout<<"插入失败"<<endl;
        else 
        { 
            addnode->next=linklist->next; 
            linklist->next=addnode; 
        } 
    } 
} 
//删除 
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
//返回链表的长度 
int Length(List *linklist)
{ 
    int len; 
    for(len=0;linklist->next;len++) 
        linklist=linklist->next; 
    return len; 
} 
//查找 
int find(List *linklist,int i)
{ 
    int j; 
    for(j=1;(j<=i && linklist);j++) 
        linklist=linklist->next; 
    if(!linklist) 
	return 0; 
    else return linklist->data; 
} 

//将链表输出 
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
    
    cout<<"字母表的长度为："<<Length(&letters)<<endl;

    insert(&letters,'B',2); 
    
    deletenode(&letters,3);
    
   /* if(!deletenode(&letters,3)) 
    cout<<"该删除操作无法进行，请您检查要删除的节点是否合理:"<<endl;*/
    
    if(ch=find(&letters,6)) 
    cout<<"您要查找的节点元素是:"<<ch<<endl;
    else  
    cout<<"查找操作失败，请检查要查找的元素位置是否合理："<<endl; 

	cout<<"进行操作之后的表的长度为："<<Length(&letters)<<endl;

    cout<<"现在表中的各个元素如下："<<endl; 
	show(&letters); 
}
