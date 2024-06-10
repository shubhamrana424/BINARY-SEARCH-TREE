#include<iostream>
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

class Solution{
public:
    void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex){
        // base case
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }

        // create a root node for the element
        int element = pre[index++];
        Node* root = new Node(element);

        // find the element's index in the inorder traversal
        int position = nodeToIndex[element];

        // recursive call
        root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n){
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;

        // create nodes to index map
        createMapping(in, nodeToIndex, n);

        // pass the correct parameters to solve function
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);

        return ans;
    }
};

// Helper function to perform postorder traversal and output elements
void postorderTraversal(Node* root){
    if(root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    int in[] = {1, 6, 8, 7};
    int pre[] = {1, 6, 7, 8};
    int n = sizeof(in) / sizeof(in[0]);
  

    Solution obj;
    Node* root = obj.buildTree(in, pre, n);

    cout << "Postorder Traversal of the constructed tree is: ";
    postorderTraversal(root);

    return 0;
}
