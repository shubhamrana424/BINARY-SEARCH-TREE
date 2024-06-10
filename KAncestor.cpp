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
Node* Solve(Node* root, int &k,int node ){
    // base case
    if(root == NULL)
    return NULL;
if(root->data== node){
    return root;
}
Node* leftAns=Solve(root->left,k,node);
Node* rightAns=Solve(root->right,k,node);
// wapas
if(leftAns!=NULL && rightAns==NULL){
    k--;
    if(k<=0){
        k=INT_MAX;
        return root;
    }
    return leftAns;
}
if(leftAns==NULL && rightAns!=NULL){
    k--; 
    if(k<=0){
        k=INT_MAX;
        return root;
    }
    return rightAns;
}
return NULL;
}
int KthAncestor(Node* root,int k, int node){
    Node* ans=Solve(root,k,node);
    if(ans== NULL || ans->data== node)
    return -1;
else{
    return ans->data;
}
}
int main(){
    Node* root= new Node(1);
    root->left= new Node(2);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right= new Node(3);


    int k=2;
    int node=4;3
    cout<<" Kth Ancestor In A Tree: "<<KthAncestor(root,k,node);
    cout<<endl;
    return 0;
}