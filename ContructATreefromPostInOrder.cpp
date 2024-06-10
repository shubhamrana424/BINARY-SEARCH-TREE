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

    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex){
        // base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        // create a root node for the element
        int element = post[index--];
        Node* root = new Node(element);

        // find the element's index in the inorder traversal
        int position = nodeToIndex[element];

        // recursive call[in Case of postorder ans inorder we build first right subtree]
        root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);
        

        return root;
    }

    Node* buildTree(int in[], int post[], int n){
        int postOrderIndex = n-1;
        map<int,int> nodeToIndex;

        // create nodes to index map
        createMapping(in, nodeToIndex, n);

        // pass the correct parameters to solve function
        Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);

        return ans;
    }
};

// Helper function to perform postorder traversal and output elements
void preorderTraversal(Node* root){
    if(root == NULL)
        return;
     cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
   
}

int main(){
    int in[] = {4 ,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};
    int n = sizeof(in) / sizeof(in[0]);
  

    Solution obj;
    Node* root = obj.buildTree(in, post, n);

    cout << "Preorder Traversal of the constructed tree is: ";
    preorderTraversal(root);

    return 0;
}
