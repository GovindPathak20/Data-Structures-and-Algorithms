// Introduction to binary trees
// Full Binary Tree: A binary tree in which every node has either 0 or 2 children.
// Complete Binary Tree: A binary tree in which all levels are completely filled except possibly the last level, the last level has all nodes as left as possible.
// Perfect Binary Tree: A binary tree in which all leaf nodes are at the same level and every parent has two children.
// Balanced Binary Tree: A binary tree which can have a maximum height of log(n) where n is the number of nodes in the tree.
// Degenerate Tree: A binary tree which is a skewed tree having only one child for each parent node. It resembles a linked list. 

// DFS Traversal Techniques in Binary Trees:
// 1. Inorder Traversal: Left, Root, Right
// 2. Preorder Traversal: Root, Left, Right
// 3. Postorder Traversal: Left, Right, Root

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}