#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
class Solution{
    public:
    Node* lca(Node* root,int n1,int n2){
        // base case
        if(root==NULL){
          return NULL;  
        }
        if(root->data== n1 || root->data == n2){
            return root;
        }
        Node* leftAns=lca(root->left,n1,n2);
        Node* rightAns=lca(root->right,n1,n2);

        if(leftAns !=NULL && rightAns != NULL){
            return root;
        }
        else if( leftAns !=NULL && rightAns== NULL)
        return leftAns;

      else if(rightAns !=NULL && leftAns == NULL)
       return rightAns;

    else{
        return NULL;
    }
    }
};
int main(){
     Node* root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(7);
    root->left->right=new Node(1);
    root->left->right->left=new Node(6);
    root->right=new Node(5);
    root->right->left=new Node(2);
    root->right->right=new Node(3);

    int n1=1, n2=3;
    Solution solution;
   
     Node* result = solution.lca(root, n1, n2);

    if (result != NULL) {
        cout << "LCA of A Binary Tree: " << result->data << endl;
    } else {
        cout << "One or both nodes not present in the tree." << endl;
    }
    return 0;
}