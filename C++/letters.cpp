#include <stdio.h> 
#include <malloc.h> 
typedef char Element; 
typedef struct linknode 
{ 
    Element data; 
    struct linknode *next; 
}LinkNode,LinkList; 

void insert(LinkList *linklist,Element e,int i)//插入节点 
{ 
    int j=0; 
    LinkNode *newnode=(LinkNode *)malloc(sizeof(LinkNode)); 
    newnode->data=e; 
    if(i==1) 
    { 
        newnode->next=linklist->next; 
        linklist->next=newnode; 
    } 
    else 
    { 
        for(j=1;j<i && linklist;j++) 
            linklist=linklist->next; 
        if(!linklist) 
            printf("无法插入元素！\n"); 
        else 
        { 
            newnode->next=linklist->next; 
            linklist->next=newnode; 
        } 
    } 
} 

int delet(LinkList *linklist,int i)//删除元素 
{ 
    int j; 
    LinkNode *denode; 
    for(j=1;j<i && linklist->next;j++) 
        linklist=linklist->next; 
    if(!linklist->next) 
        return 0; 
    else 
    { 
        denode=linklist->next; 
        linklist->next=denode->next; 
        free(denode); 
        return 1; 
    } 
} 

int locate(LinkList *linklist,int i)//查找元素 
{ 
    int j; 
    for(j=1;j<=i && linklist;j++) 
        linklist=linklist->next; 
    if(!linklist) return 0; 
    else return linklist->data; 
} 

int getLength(LinkList *linklist)//求长度 
{ 
    int length; 
    for(length=0;linklist->next;length++) 
        linklist=linklist->next; 
    return length; 
} 

void display(LinkList *linklist)//打印表 
{ 
    linklist=linklist->next; 
    for(;linklist;linklist=linklist->next) 
        printf("%c\n",linklist->data); 
} 

int main() 
{ 
    LinkList letters; 
    LinkNode head={0,0}; 
    char i,ch; 
     
    letters=head; 
    for(i='a';i<='z';i++) 
        insert(&letters,i,(int)(i-'a'+1)); 
    printf("表长度：%d\n",getLength(&letters)); 
    insert(&letters,'A',2); 
    if(!delet(&letters,27)) 
        printf("删除失败，请检查位置变量。\n"); 
    if(ch=locate(&letters,1)) 
        printf("找到元素：%c\n",ch); 
    else  
        printf("查找元素失败，请检查位置变量。\n"); 
    printf("表长度：%d\n",getLength(&letters)); 
    display(&letters); 
}
