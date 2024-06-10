#include <iostream>
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
    void flatten(Node *root) {
        Node *curr = root;
        while (curr != NULL) {
            if (curr->left) {
                Node *pred = curr->left;
                while (pred->right)
                    pred = pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// Function to print the linked list
void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);

    Solution solution;
    solution.flatten(root);

    cout << "Flattened Binary Tree to Linked List: ";
    printList(root);

    cout << endl;
    return 0;
}
