/**
* @file rekursif_postorder.cpp program untuk mensimulasikan tree traversal metode postorder dengan
* menggunakan pendekatan rekursif
* @brief postorder traversal adalah tree traversal yang bekerja dengan mengunjungi subtree kanan
* terlebih dahulu lalu lanjut ke subtree kiri terakhir kembali ke root
* urutannya:
* kiri -> kanan -> root
* @details menggunakan pendekatan rekursif
* visualization: https://www.youtube.com/watch?v=4Xo-GtBiQN0
*/
#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x){
        this->left = nullptr;
        this->right = nullptr;
    }
};
void postorder(Node* root){
    // base case
    if(!root){
        return; //panggil fungsi pemanggil pada call stack jika ada,jika tidak berhenti
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
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
    postorder(root);
    std::cin.get();
    return 0;
}