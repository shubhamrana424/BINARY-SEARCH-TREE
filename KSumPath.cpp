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
    void Solve(Node* root,int k,int &count,vector<int> path){
        // ase case
        if(root== NULL)
        return ;
    path.push_back(root->data);
    // left
    Solve(root->left,k,count,path);
    // right
    Solve(root->right,k,count, path);

    //check for K sum
    int  size=path.size();
    int sum=0;
    for(int i=size-1; i>=0; i--){
        sum+= path[i];
        if(sum== k)
        count++;
    }
    path.pop_back();
    }
    int sumK(Node* root, int k){
        vector<int> path;
        int count =0;
        Solve(root,k,count,path);
        return count;
    }
};
int main(){
 Node* root=new Node(1);
    root->left=new Node(3);
    root->left->left=new Node(2);
    root->left->right=new Node(1);
    root->left->right->left=new Node(1);
    root->right=new Node(-1);
    root->right->left=new Node(4);
    root->right->left->left=new Node(1);
    root->right->left->right=new Node(2);
    root->right->right=new Node(5);

int k=5;
Solution solution ;
cout<<" K Sum of  Path: "<<solution.sumK(root,k);
cout<<endl;
return 0;
}