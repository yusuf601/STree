/**
* @file predecessor.cpp program untuk mencari predecessor dari sebuah nodes
* @brief predecessor dari sebuah node adalah nilai terbesar yg lebih kecil dari nodes.
*/
#include <iostream>
#include <print>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data),left(nullptr),right(nullptr){}
};
Node* max(Node* nodes){
    Node* node = nodes;
    while(node && node->left){
        node = node->right;
    }
    return node;
}
Node* find_predecessor(Node* root,Node* target){
    if(!root || !target){
        return nullptr;
    }
    //case 1: punya left child
    if(target->left){
        return max(target->left);
    }   

    Node* predecessor;
    Node* nodes;
    while(nodes){
        if(target->data > nodes->data){
            predecessor = nodes;
            nodes = nodes->right;
        }else if(target->data < nodes->data){
            nodes = nodes->left;
        }else{
            break;
        }
    }
    return predecessor;
}
int main(){
    std::println("disini");
    // membuat BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(40);

    Node* target = root->right->left; // node 25

    Node* pred = find_predecessor(root, target);
    if (pred){
        std::println("predecessor dari {} adalah {} " ,target->data,pred->data);
    }else
        std::println("tidak punya predecessor");
    std::cin.get();
    return 0;
}