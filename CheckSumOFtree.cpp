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
    pair<bool,int> isSumTreeFast(Node* root){
        // base case 
        if(root == NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;       
             }
             // Leaf Node
             if(root->left==NULL && root->right==NULL){
                pair<bool,int> p=make_pair(true,root->data);
                return p;
             }
             pair<bool,int> leftAns=isSumTreeFast(root->left);
             pair<bool,int> rightAns=isSumTreeFast(root->right);
    
    bool isleftSumTree=leftAns.first;
    bool isrightSumTree =rightAns.first;

    int leftSum=leftAns.second;
    int rightSum=rightAns.second;

    bool condn=root->data == leftSum+ rightSum;

    pair<bool,int> ans;
    if(isleftSumTree && isrightSumTree && condn){
        ans.first=true;
        ans.second=root->data + leftSum + rightSum;
    }
    else{
        ans.first=false;
    }
    return ans;
    }
    bool isSumTree(Node * root){
        return isSumTreeFast(root).first;
    }
};
int main()
{
    Solution solution;
    Node * root=new Node(70);
    root->right=new Node(20);
    root->right->right=new Node(10);
    root->right->left=new Node(10);
    root->left=new Node(30);

    if(solution.isSumTree(root)){
        cout<<" Is A Sum Tree : "<<endl;
    }
    else{
        cout<<" Is Not A Sum tree: "<<endl;
    }
    return 0;
}