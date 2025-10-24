/**
* @file inorder.cpp program untuk mensimulasikan traversal tree dengan metode
* inorder dengan pendekatan rekursi
* @brief main idea dari inorder adalah mulai dari root node lalu traversal ke subtree kiri
* kemudian kembali ke root lalu selesaikan subtree kanan
* urutan:
* left ->root -> right
* @details menggunakan pendekatan rekursif
* visualization: https://www.youtube.com/watch?v=4_UDUj1j1KQ
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
void inorder(Node* root){
    //base case
    //jika masih ada fungsi pemanggil di call stack maka kembalikan,jika tidak berhenti
    if(!root){
        return;//
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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
    std::cout << "traversal use inorder \n";
    inorder(root);
    std::cin.get();
    return 0;
}