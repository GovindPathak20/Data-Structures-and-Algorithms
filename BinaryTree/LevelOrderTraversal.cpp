#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }

    return 0;
}