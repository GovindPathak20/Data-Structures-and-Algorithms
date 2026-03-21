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

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *curr = st.top();
        st.pop();
        cout << curr->data << " ";
        // Right node will be pushed first as stack follows LIFO principle
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
    }

    return 0;
}