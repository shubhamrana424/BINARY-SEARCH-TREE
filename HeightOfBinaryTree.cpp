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

class Solution {
public:
    int height(Node* node) {
        // base case 
        if(node == NULL){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
};

int main() {
    Solution solution;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);


    cout << "Maximum Height of Tree: " << solution.height(root) << endl;
    return 0;
}
