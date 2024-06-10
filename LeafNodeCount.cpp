#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node* root, int &count) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, count);

    if (root->left == NULL && root->right == NULL) {
        count++;
    }

    inorder(root->right, count);
}

int noOfLeafNodes(node* root) {
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Number of leaf nodes: " << noOfLeafNodes(root) << endl;

    return 0;
}
