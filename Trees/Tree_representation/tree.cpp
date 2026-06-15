#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = this->right = NULL;
    }
};

int main(){
    //usage 

    Node* root =  new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);

    root->left->right = new Node(5);

    return 0;
}