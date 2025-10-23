/**
* @file use_rekursif.cpp program untuk mendapatkan max height and deepth menggunakan pendekatan
* rekursif
* @brief menjelajahi node menggunakan depth tree traversal terkhususnya adalah postorder
* traversal,untuk menentukan max height dan max deepth memakai rumus
* max = 1 + max(child(left),child(right))
* @details time complexity O(n),karena tiap node dikunjungi 1 kali
*/
#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int height(Node* root){
    if(!root){
        return - 1;
    }
    int lleft = height(root->left);
    int lright = height(root->right);

    return 1 + std::max(lleft,lright);
}
int main(){
    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);
    height(root);
    std::cin.get();
    return 0;
}