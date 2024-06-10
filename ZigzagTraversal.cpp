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
    vector<int> zigzagTraversal(Node* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) { // Fixed the typo in empty()
            int size = q.size();
            vector<int> ans(size);

            // Level Process 
            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                // Normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);  // Fixed the typo in push()

                if (frontNode->right)
                    q.push(frontNode->right);  // Fixed the typo in push()
            }

            // Direction Change
            leftToRight = !leftToRight;

            for (auto i : ans) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
   
    Solution solution;
    vector<int> result = solution.zigzagTraversal(root);

    cout << "Zig-Zag Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
