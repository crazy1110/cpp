#include <stdio.h> 
#include <malloc.h> 
typedef char Element; 
typedef struct linknode 
{ 
    Element data; 
    struct linknode *next; 
}LinkNode,LinkList; 

void insert(LinkList *linklist,Element e,int i)//����ڵ� 
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
            printf("�޷�����Ԫ�أ�\n"); 
        else 
        { 
            newnode->next=linklist->next; 
            linklist->next=newnode; 
        } 
    } 
} 

int delet(LinkList *linklist,int i)//ɾ��Ԫ�� 
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

int locate(LinkList *linklist,int i)//����Ԫ�� 
{ 
    int j; 
    for(j=1;j<=i && linklist;j++) 
        linklist=linklist->next; 
    if(!linklist) return 0; 
    else return linklist->data; 
} 

int getLength(LinkList *linklist)//�󳤶� 
{ 
    int length; 
    for(length=0;linklist->next;length++) 
        linklist=linklist->next; 
    return length; 
} 

void display(LinkList *linklist)//��ӡ�� 
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
    printf("���ȣ�%d\n",getLength(&letters)); 
    insert(&letters,'A',2); 
    if(!delet(&letters,27)) 
        printf("ɾ��ʧ�ܣ�����λ�ñ�����\n"); 
    if(ch=locate(&letters,1)) 
        printf("�ҵ�Ԫ�أ�%c\n",ch); 
    else  
        printf("����Ԫ��ʧ�ܣ�����λ�ñ�����\n"); 
    printf("���ȣ�%d\n",getLength(&letters)); 
    display(&letters); 
}
