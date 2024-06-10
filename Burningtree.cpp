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
    // create mapping, return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            if (front->data == target) {
                res = front;
            }
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int BurnTree(Node* targetNode, map<Node*, Node*>& nodeToParent) {
        int ans = 0;
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        while (!q.empty()) {
            bool flag = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // process neighboring node
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }

    int minTime(Node* root, int target) {
        // algo
        // step-1: create nodeToParent Mapping
        // step-2: find target Node
        // step-3: burn tree in min time

        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);

        int ans = BurnTree(targetNode, nodeToParent);
        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);

    int target = 8;
    Solution solution;
    cout << "Burning Tree Minimum Time is: " << solution.minTime(root, target);
    cout << endl;
    return 0;
}
