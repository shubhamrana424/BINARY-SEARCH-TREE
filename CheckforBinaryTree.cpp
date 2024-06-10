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
    pair<bool, int> isBalancedFast(Node* root) {
        // base case
        if (root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        // Calculate the height difference
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (leftAns && rightAns && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        return ans;
    }

    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
    }
};

int main() {
    // Create a sample tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->right = new Node(6);

    Solution solution;
    
    if (solution.isBalanced(root)) {
        cout << "Tree is balanced." << endl;
    }
    else {
        cout << "Tree is not balanced." << endl;
    }

    return 0;
}

