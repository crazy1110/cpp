#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define TOTAL 10
 
//二叉树的二叉链表存储表示
typedef int TElemType;
typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode,*BiTree;
BiTree SearchBST1(BiTree T, TElemType key)
{
    if (!T)                     //空树，查找失败
        return NULL;
    else if (key == T->data) //查找成功
        return T;
    else if (key < T->data)       //在左子树中继续查找
        return SearchBST1(T->lchild, key);
    else                        //在右子树中继续查找
        return SearchBST1(T->rchild, key);
}
/*
 * 删除*T指向的结点
 */
bool Delete(BiTree *T)
{
    BiTree L;
 
    //*T既没有左孩子，又没有右孩子，为叶子结点
    if (!(*T)->lchild && !(*T)->rchild)
        *T = NULL;
    //*T只有右孩子
    else if (!(*T)->lchild)
        *T = (*T)->rchild;
    //*T只有左孩子
    else if (!(*T)->rchild)
        *T = (*T)->lchild;
    //*T既有左孩子，又有右孩子
    else
    {
        L = (*T)->lchild;//L指向被删除结点的左子树
 
        //寻找L的最右孩子
        while (L->rchild)
            L = L->rchild;
 
        //把*T的右子树接到左子树最右孩子的右子树上。
        L->rchild = (*T)->rchild;
        //*T的左子树直接作为*T父结点的子树
        *T = (*T)->lchild;
    }
    return true;
}
bool SearchBST2(BiTree T, BiTree F, TElemType key, BiTree *p)
{
    //函数中，只能对*p进行修改，而不能试图修改p的值。
    //因为p为形参，形参的改变并不会影响实参。
    if (!T)
    {
        //T为空树，此时父结点F或者为NULL，或者为查找路径上的最后一个结点。
        //查找失败
        *p = F;
        return false;
    }
    else if (key == T->data) //查找成功
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
 * 在树*T中查找与key相同的结点。
 * 如果存在返回FALSE，否则将key值插入到树中。
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
 
        //注意不要漏掉p为NULL的情况，
        //此时表明*T为空树，将新结点直接作为根结点。
        if (!p)
            *T = n;
        //key比查找路径上的最后一个结点小，则将n作为p的左子树。
        else if (key < p->data)
        {
            p->lchild = n;
        }
        //key比查找路径上的最后一个结点大，则将n作为p的右子树。
        else
        {
            p->rchild = n;
        }
        return true;
    }
}
bool DeleteBST(BiTree *T, TElemType key)
{
    if (!*T)        //空树。查无此结点。
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
 * 遍历函数
 */
bool PrintElement(TElemType e)
{
    printf("%-3d ",e);
    return true;
}
int main()
{
    BiTree T = NULL;//注意一定要先将T初始化为空树
    int i, num;
 
    //使用插入操作构建二叉排序树。(插入过程中已检验查找函数SearchBST2())
    printf("输入T全部节点构建二叉排序树：\n");
    for (i = 0; i < TOTAL; i++)
    {
        scanf("%d", &num);
        InsertBST(&T, num);
    }
 
    //检验插入效果。中序遍历该树，若结果为由小到大，表明插入成功。
    printf("中序遍历该树:\n");
    InOrderTraverse_Recursive(T, PrintElement);
    putchar('\n');
 
    //删除操作
    printf("输入待删除的数:");
    scanf("%d", &num);
    DeleteBST(&T, num);
 
    //检验删除操作
    printf("重新中序遍历该树:\n");
    InOrderTraverse_Recursive(T, PrintElement);
    putchar('\n');
     
    //检验查找操作SearchBST1()
    printf("输入待查找的数:");
    scanf("%d", &num);
    if (SearchBST1(T, num))
        printf("Yes\n");
    else
        printf("No\n");
 
    return 0;
}
