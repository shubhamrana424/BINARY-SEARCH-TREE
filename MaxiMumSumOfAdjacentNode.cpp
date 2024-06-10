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
    pair<int, int> Solve(Node* root) {
        // base case
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = Solve(root->left);
        pair<int, int> right = Solve(root->right);

        pair<int, int> res;
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;
    }

    int getMaxSum(Node* root) {
        pair<int, int> ans = Solve(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution solution;
    cout << "Maximum Sum of Non-Adjacent Nodes: " << solution.getMaxSum(root) << endl;

    return 0;
}
