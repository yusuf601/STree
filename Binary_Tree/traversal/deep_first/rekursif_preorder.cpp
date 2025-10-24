/**
* @file preorder.cpp program untuk mensimulasikan tree traversal dengan metode preorder
* dengan pendekatan rekursif
* @brief preorder traversal adalah metode traversal yang mengunjungi root terlebih dahulu lalu
* ke subtree kiri dan terakhir ke subtree kanan.
* urutannya:
* root ->kiri ->kanan
* @details menggunakan pendekatan rekursif
* visualization: https://www.youtube.com/watch?v=8xue-ZBlTKQ
*/
#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    // constructor
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void preorder(Node* root){
    if(!root){
        return;//panggil fungsi pemanggil pada call stack jika ada,jika tidak berhentu
    }
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    // / \  /  \  / \
    //17 23 27 3  8  11

    Node* root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);
    preorder(root);
    std::cin.get();
    return 0;
}