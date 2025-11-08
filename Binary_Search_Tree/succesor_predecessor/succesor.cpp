/**
* @file successor program untuk mencari nilai succesor dari sebuah nodes
* @brief inorder successor
* inorder successor dari sebuah node adalah node dengan nilai terkecil yang lebih besar dari nilai
* node tersebut.ada 2 kondisi dalam mencari succesor,yaitu:
* 1.nodes memiliki right child,di kondisi ini kita akan mencari leaf node right child,artinya
* kita akan melakukan traversal sampai leaf right child.
* 2. nodes tidak memiliki right child,jika node tidak memiliki right child,maka kita akan mencari dari successor 
* diatas node,jika node saat ini lebih kecil daripada nodes maka update succesor,lakukan sampai current menunjuk
* nodes.
*/
#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data): data(data),left(nullptr),right(nullptr){}
};
Node* min(Node* node){
    if(!node){
        return nullptr;
    }
    Node* curr = node;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}
Node* find_successor(Node* root,Node* target){
    if(!root || !target){
        return nullptr;
    }
    //case 1 jika target punya right child
    if(target->right){
        return min(target);
    }
    //case 2 jika target tidak punya right child
    Node* successor = nullptr;
    Node* curr = root;
    while(curr){
        if(target->data < curr->data){
            successor = curr;
            curr = curr->left;
        }else if(target->data > curr->data){
            curr = curr->right;
        }else{ //target-data = curr->data
            break;
        }
    }
    return successor;
}
int main() {
    // membuat BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(40);

    Node* target = root->right->left; // node 25

    Node* succ = find_successor(root, target);
    if (succ){
        std::cout << "Successor dari " << target->data << " adalah " << succ->data << std::endl;;
    }else
        std::cout << "Tidak punya successor\n";

    return 0;
}