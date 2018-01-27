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
  
//��ӡ��level�еĽڵ㣬�д�ӡ����򷵻�true�����򷵻�false   
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
  
//�����������ĳһ��û�д�ӡʱbreak��ѭ��   
void levelOrder(Tree tree) {  
    for(int i = 0; ; i++) {  
        if(!printLevel(tree, i)) {  
            break;  
        }  
    }  
}  
  
int main()  
{  
	cout<<"��������Ҫ���в�������Ķ�����������������У�"<<endl; 
    Tree tree = createTree();  
    cout << "level order: " << endl;  
    levelOrder(tree);  
    return 0;  
}  
