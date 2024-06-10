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
     vector<int> verticalOrder(Node* root){
        map<int,map<int, vector<int> >> nodes;
        queue<pair<Node*, pair<int,int> >> q;
        vector<int> ans;

        if(root == NULL)
        return ans;

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node*,pair<int,int> > temp=q.front();
        q.pop();

        Node*frontNode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;  

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left)
        q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
     
     if(frontNode->right)
     q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));

    }
    for(auto i: nodes){

        for(auto j: i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
     }
};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    // Create an instance of the Solution class
    Solution solution;

    // Call the boundary function and get the result
    vector<int> result = solution.verticalOrder(root);

    // Print the result
    cout << "VerticalOrder Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}