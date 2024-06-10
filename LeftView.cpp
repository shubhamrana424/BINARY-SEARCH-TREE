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
void solve(Node* root ,vector<int> &ans,int level){
 // base case
 if(root== NULL)
 return ;
// we enter in a New level 
if(level== ans.size())
ans.push_back(root->data);

solve(root->left,ans,level+1);
solve(root->right,ans,level+1);
}
vector<int> leftView(Node* root){
    vector<int> ans;
     solve(root,ans,0);
     return ans;
}
int main(){
     Node* root = new Node(1);
       root->left=new Node(2);
       root->left->left=new Node(4);
       root->left->right=new Node(5);
       root->right=new Node(3);
       root->right->left=new Node(6);
       root->right->right=new Node(7);
       root->right->right->left=new Node(9);
       root->right->right->right=new Node(8);
 vector<int> result = leftView(root);

    cout << "Left View of Binary Tree: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}