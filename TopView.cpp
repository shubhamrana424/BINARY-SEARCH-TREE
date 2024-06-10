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
     vector<int> topView(Node* root){
        vector<int>ans;
         if(root==NULL){
            return ans;
         }
         map<int,int> topNode;
         queue<pair<Node* ,int> > q;

         q.push(make_pair(root,0));
         while(!q.empty()){
            pair<Node* ,int> temp=q.front();
            q.pop();

            Node* frontNode=temp.first;
            int hd= temp.second;

            // if one value is present for a HD, then Do nothing
            if(topNode.find(hd)==topNode.end())
            topNode[hd]=frontNode->data;

            if(frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));

        if(frontNode->right)
        q.push(make_pair(frontNode->right,hd+1));
         }
         for(auto i:topNode){
            ans.push_back(i.second);
         }
       return ans;
     }
};
int main(){
       Node* root = new Node(1);
       root->left=new Node(2);
       root->left->left=new Node(4);
       root->left->right=new Node(5);
       root->right=new Node(3);
       root->right->left=new Node(6);
       root->right->right=new Node(7);

       Solution solution;

       vector<int> result=solution.topView(root);

       cout<<" Top View Of Binary Tree Are: "<<endl;
       for(auto i:result){
        cout<<i<<" ";
         }

        cout<<endl;

        return 0;
      
}