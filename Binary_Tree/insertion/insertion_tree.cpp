/**
* @file insertion_tree.cpp program untuk mengimplementasikan insertion pada binary tree
* @brief insertion pada binary tree memakai level order traversal(bfs) dari kiri kenanan.
* cara kerja:
* mulai dari node paling kiri lalu pindah ke node kanan pada level yang
* jika ada node yang kosong(nullptr),maka insert di posisi ini
* jika tidak cari terus sampai ada pos kosong.
* @details memakai level order traversal,Time complexity O(n),Space complexity O(n)
* @see Binary_Tree/traversal
*/
#include <iostream>
#include <queue>
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
/**
* @brief fungsi untuk mengimplementasikan insert node menggunakan level order traversal
* @param root struktur data tree
* @param val node baru yang akan di insert
*/
Node* insertion(Node* root,int val){
    Node* new_node = new Node(val);
    if(!root){
        //return root
        return new_node;
    }
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(!node->left){
            node->left = new_node;
            return root;
        }else q.push(node->left);
        if(!node->right){
            node->right = new_node;
            return root;
        }else q.push(node->right);
    }
    //pakai level order traversal
    return root;
}
/**
* @brief fungsi untuk print node menggunakan inorder traversal
* @param root struktur data tree
*/
void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left); //subtree kiri
    std::cout << root->data << " ";
    inorder(root->right); //subtree kanan
}
int main(){
  	// Constructing the binary tree
  	//          10
    //        /    \
    //       11     9
    //      /      / \
    //     7      15   8
  
    Node* root = new Node(10);
    root->left = new Node(11);
  	root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    inorder(root);
    std::cout << "\nproses insert\n";
    root = insertion(root, 12);
  	// After insertion 12 in binary tree
  	//          10
    //        /    \
    //       11     9
    //      /  \   / \
    //     7   12 15  8
    inorder(root);
    // std::cin.get();
    return 0;
}