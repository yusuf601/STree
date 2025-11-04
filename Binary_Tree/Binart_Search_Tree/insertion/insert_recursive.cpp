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
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node* recursiveInsert(Node* root,int key){
    //jika tree kosong
    if(!root){
        root = new Node(std::move(key));
        return root;
    }
    if(key < root->val){
        root->left = recursiveInsert(root->left,key);
    }else if(key < root->val){
        root->right = recursiveInsert(root->right,key);
    }
    return root;
}
int main(){
    std::cin.get();
}