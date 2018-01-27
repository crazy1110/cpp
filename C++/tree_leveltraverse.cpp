#include<iostream>  
#include<stdlib.h>  
using namespace std;  
  
typedef struct Node {  
    char val;  
    struct Node* left = NULL;  
    struct Node* right = NULL;  
}TreeNode, *Tree;  
  
Tree createTree() {  
    char c;  
    cin >> c;  
    if(c == '#') return NULL;  
    Tree tree = (Tree)malloc(sizeof(Tree));  
    tree->val = c;  
    tree->left = createTree();  
    tree->right = createTree();  
    return tree;  
}     
  
//打印第level行的节点，有打印输出则返回true，否则返回false   
bool printLevel(Tree tree, int level) {  
    if(!tree || level < 0) {  
        return false;  
    }  
    if(level == 0) {  
        cout << tree->val << " ";  
        return true;  
    }  
    return printLevel(tree->left, level - 1) + printLevel(tree->right, level - 1);  
}  
  
//层序遍历，当某一行没有打印时break掉循环   
void levelOrder(Tree tree) {  
    for(int i = 0; ; i++) {  
        if(!printLevel(tree, i)) {  
            break;  
        }  
    }  
}  
  
int main()  
{  
	cout<<"请输入你要进行层序遍历的二叉树的先序遍历序列："<<endl; 
    Tree tree = createTree();  
    cout << "level order: " << endl;  
    levelOrder(tree);  
    return 0;  
}  
