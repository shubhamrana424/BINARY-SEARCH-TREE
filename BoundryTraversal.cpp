#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class Solution {
public:
    void traverseLeft(Node* root, vector<int>& ans) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else {
            traverseLeft(root->right, ans);
        }
    }

    void traverseLeaf(Node* root, vector<int>& ans) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node* root, vector<int>& ans) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
        ans.push_back(root->data);
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->data);
        traverseLeft(root->left, ans);
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        traverseRight(root->right, ans);

        return ans;
    }
};

int main() {
    // Create a sample binary tree
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
    vector<int> result = solution.boundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
