#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

void diagonalTraversalHelper(Node* root, int diagonalLevel, map<int, vector<int>>& diagonalMap) {
    if (!root)
        return;

    diagonalMap[diagonalLevel].push_back(root->data);

    diagonalTraversalHelper(root->left, diagonalLevel + 1, diagonalMap);
    diagonalTraversalHelper(root->right, diagonalLevel, diagonalMap);
}

vector<int> diagonalTraversal(Node* root) {
    vector<int> result;
    if (!root)
        return result;

    map<int, vector<int>> diagonalMap;
    diagonalTraversalHelper(root, 0, diagonalMap);

    // Flatten the map to get the result
    for (auto it : diagonalMap) {
        for (int val : it.second) {
            result.push_back(val);
        }
    }

    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = diagonalTraversal(root);

    cout << "Diagonal Traversal of Binary Tree: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
