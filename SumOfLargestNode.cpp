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
    void Solve(Node* root,int sum,int &maxSum,int len,int &maxLen ){
 // base  case
    if(root== NULL){

       if(len> maxLen){
        maxLen=len;
        maxSum=sum;
       }
       else if(len== maxLen){
        maxSum=max(sum,maxSum);
       }
       return;
    }
    sum=sum+root->data;
    Solve(root->left,sum,maxSum,len+1,maxLen);
    Solve(root->right,sum,maxSum,len+1,maxLen);

    }
    int sumOFRootToLeafPath(Node*root){
        int len=0;
        int maxLen=0;
        
        int sum=0;
        int maxSum=INT_MIN;

   Solve(root,sum,maxSum,len, maxLen);

   return maxSum;
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

    Solution Solution;
    cout<<"Sum Of LArgest BloodLine:  "<<Solution.sumOFRootToLeafPath(root);
    cout<<endl;
    return 0;
}