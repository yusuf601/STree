/**
* @file insertion.cpp program untuk mengimplementasikan insertion pada binary search tree(BST)
* @brief pada binary search tree(BST),ada beberapa aturan:
* - semua node pada subtree kiri nilai nya lebih kecil dari root
* - semua node pada subtree kanan nilainya lebih besar dari root 
* pada saat insertion juga memiliki aturan:
* jika tree kosong maka,buat node baru jadi root
* jika nilai yang ingin di insert lebih kecil dari node sekarang maka pindah ke kekiri
* jika lebih besar maka pindah kekanan
* ulangi sampai ada posisi kosong
*/
#include <iostream>
#include <stack>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data  = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node* insertIterative(Node* root,int key){
    Node* new_node = new Node(key);
    if(!root){
        root = new_node;
        return root;
    }
    Node* parent = nullptr;
    Node* curr = root;
    while(curr){
        parent = curr;
        if(key < curr->data){
            curr = curr->left;
        }else if(key > curr->data){
            curr = curr->right;
        }else{
            return root;
        }
    }
    if(key < parent->data){
        parent->left = new_node;
    }else{
        parent->right = new_node;
    }
    return root;
}
void inorder(Node* root){
    if(!root){
        return;
    }
    std::stack<Node*>s;
    Node* curr = root;
    while(curr || !s.empty()){
        //jelajahi subtree kiri
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        std::cout << curr->data << "\n";
        //pada subtree kiri,jika ada child dikanan maka jelajahi,selesai di subtree kiri lanjut jelajahi subtree kanan
        curr = curr->right;
    }
}
int main(){
    Node* root = nullptr;
    root = insertIterative(root, 8);
    root = insertIterative(root, 3);
    root = insertIterative(root, 10);
    root = insertIterative(root, 1);
    root = insertIterative(root, 6);
    root = insertIterative(root, 14);
    root = insertIterative(root, 4);
    root = insertIterative(root, 7);
    root = insertIterative(root, 13);
    inorder(root);
    std::cin.get();
    return 0;
}