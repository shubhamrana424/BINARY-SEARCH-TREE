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
    bool isidentical(Node* r1,Node* r2){
        // base case 
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if(r1==NULL && r2 !=NULL){
            return false;
        }
        if(r1 !=NULL && r2 == NULL ){
            return false;
        }
        bool left= isidentical(r1->left,r2->left);
        bool right=isidentical(r1->right,r2->right);

        bool value= r1->data == r2->data;

        if(left && right && value){
            return true;
        }
          else{
                return false;
            }
    }
};
int main(){
   Solution solution;
   Node * r1 =new Node(1);
   r1->right=new Node(2);
   r1->left=new Node(3);

   Node * r2=new Node(1);
   r2->right=new Node(2);
   r2->left=new Node(3);
   r2->left->right=new Node(34);

    if(solution.isidentical(r1,r2)){
        cout<<" Tree is Identical "<<endl;
    } 
    else{
        cout<<" Tree is Not Identical "<<endl;
    }
    return 0;

}