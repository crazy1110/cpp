#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define TOTAL 10
 
//�������Ķ�������洢��ʾ
typedef int TElemType;
typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode,*BiTree;
BiTree SearchBST1(BiTree T, TElemType key)
{
    if (!T)                     //����������ʧ��
        return NULL;
    else if (key == T->data) //���ҳɹ�
        return T;
    else if (key < T->data)       //���������м�������
        return SearchBST1(T->lchild, key);
    else                        //���������м�������
        return SearchBST1(T->rchild, key);
}
/*
 * ɾ��*Tָ��Ľ��
 */
bool Delete(BiTree *T)
{
    BiTree L;
 
    //*T��û�����ӣ���û���Һ��ӣ�ΪҶ�ӽ��
    if (!(*T)->lchild && !(*T)->rchild)
        *T = NULL;
    //*Tֻ���Һ���
    else if (!(*T)->lchild)
        *T = (*T)->rchild;
    //*Tֻ������
    else if (!(*T)->rchild)
        *T = (*T)->lchild;
    //*T�������ӣ������Һ���
    else
    {
        L = (*T)->lchild;//Lָ��ɾ������������
 
        //Ѱ��L�����Һ���
        while (L->rchild)
            L = L->rchild;
 
        //��*T���������ӵ����������Һ��ӵ��������ϡ�
        L->rchild = (*T)->rchild;
        //*T��������ֱ����Ϊ*T����������
        *T = (*T)->lchild;
    }
    return true;
}
bool SearchBST2(BiTree T, BiTree F, TElemType key, BiTree *p)
{
    //�����У�ֻ�ܶ�*p�����޸ģ���������ͼ�޸�p��ֵ��
    //��ΪpΪ�βΣ��βεĸı䲢����Ӱ��ʵ�Ρ�
    if (!T)
    {
        //TΪ��������ʱ�����F����ΪNULL������Ϊ����·���ϵ����һ����㡣
        //����ʧ��
        *p = F;
        return false;
    }
    else if (key == T->data) //���ҳɹ�
    {
        *p = T;
        return true;
    }
    else if (key < T->data)
    {
        return SearchBST2(T->lchild, T, key, p);
    }
    else
    {
        return SearchBST2(T->rchild, T, key, p);
    }
}
 
/*
 * ����*T�в�����key��ͬ�Ľ�㡣
 * ������ڷ���FALSE������keyֵ���뵽���С�
 */
bool InsertBST(BiTree *T, TElemType key)
{
    BiTree p, n;
    if (SearchBST2(*T, NULL, key, &p))
        return false;
    else
    {
        n = (BiTree)malloc(sizeof(BiNode));
        n->data = key;
        n->lchild = NULL;
        n->rchild = NULL;
 
        //ע�ⲻҪ©��pΪNULL�������
        //��ʱ����*TΪ���������½��ֱ����Ϊ����㡣
        if (!p)
            *T = n;
        //key�Ȳ���·���ϵ����һ�����С����n��Ϊp����������
        else if (key < p->data)
        {
            p->lchild = n;
        }
        //key�Ȳ���·���ϵ����һ��������n��Ϊp����������
        else
        {
            p->rchild = n;
        }
        return true;
    }
}
bool DeleteBST(BiTree *T, TElemType key)
{
    if (!*T)        //���������޴˽�㡣
        return false;
    else if (key == (*T)->data)
    {
        Delete(T);
        return true;
    }
    else if (key < (*T)->data)
    {
        return DeleteBST(&((*T)->lchild), key);
    }
    else
    {
        return DeleteBST(&((*T)->rchild), key);
    }
}
 
bool InOrderTraverse_Recursive(BiTree T, bool(*Visit)(TElemType e))
{
    if (T)
    {
        if (InOrderTraverse_Recursive(T->lchild, Visit))
            if (Visit(T->data))
                if (InOrderTraverse_Recursive(T->rchild, Visit))
                    ;
    }
    return true;
}
 
/*
 * ��������
 */
bool PrintElement(TElemType e)
{
    printf("%-3d ",e);
    return true;
}
int main()
{
    BiTree T = NULL;//ע��һ��Ҫ�Ƚ�T��ʼ��Ϊ����
    int i, num;
 
    //ʹ�ò����������������������(����������Ѽ�����Һ���SearchBST2())
    printf("����Tȫ���ڵ㹹��������������\n");
    for (i = 0; i < TOTAL; i++)
    {
        scanf("%d", &num);
        InsertBST(&T, num);
    }
 
    //�������Ч����������������������Ϊ��С���󣬱�������ɹ���
    printf("�����������:\n");
    InOrderTraverse_Recursive(T, PrintElement);
    putchar('\n');
 
    //ɾ������
    printf("�����ɾ������:");
    scanf("%d", &num);
    DeleteBST(&T, num);
 
    //����ɾ������
    printf("���������������:\n");
    InOrderTraverse_Recursive(T, PrintElement);
    putchar('\n');
     
    //������Ҳ���SearchBST1()
    printf("��������ҵ���:");
    scanf("%d", &num);
    if (SearchBST1(T, num))
        printf("Yes\n");
    else
        printf("No\n");
 
    return 0;
}
