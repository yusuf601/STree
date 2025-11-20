#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x),left(nullptr),right(nullptr){}
};
int floor(Node* root,int x){
    if(!root){
        return -1;
    }
    Node* node = root;
    int floor = -1;
    while(node){
        if(node->data < x){
            node = node->right;
        }else if(node->data > x){
            floor = node->data;
            node = node->left;
        }else{
            return node->data;
        }
    }
    return floor;
}
int main(){
    // Representation of the given tree
    //       10
    //       / \
    //      5  15
    //         / \
    //        12 30 
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);
    std::cin.get();
    return 0;
}