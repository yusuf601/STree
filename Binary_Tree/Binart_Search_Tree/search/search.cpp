/***
* @file search.cpp program untuk mengimplementasikan search pada binary search tree(BST)
* @brief karena pada binary search tree ada beberapa aturan maka proses searching juga harus
* mengikuti aturan tersebut,langkah-langkah search node pada binary tree
* jika tree kosong maka return false
* mulai traversal dari root,jika node sekarang lebih kecil daripada key maka jelajahi child node kiri
* jika lebih besar jelajahi child node kanan
*/
#include <iostream>
#include <stack>
struct Node{
    int data;
    Node* left;
    Node* right;   
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node* insert(Node* root,int key){
    if(!root){
        root = new Node(key);
    }
    Node* curr = root;
    Node* parent = nullptr;
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
        parent->left = new Node(key);
    }else{
        parent->right = new Node(key);
    }
    return root;
}
bool search(Node* root,int key){
    if(!root){
        return false;
    }
    Node* curr = root;
    while(curr){
        if(key == curr->data){
            return true;
        }else if(key < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    return false;
}
void preorder(Node* root){
    if(!root){
        return;
    }
    std::stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        std::cout << node->data << " ";
        if(node->right)s.push(node->right);
        if(node->left)s.push(node->left);
    }
}
void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
int main(){
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);
    std::cout << "tampilkan tree: " ;
    inorder(root);
    std::cout << " \n";
    std::cout << "cari node: \n";
    if(search(root,14)){
        std::cout << "ada pada tree \n";
    }else{
        std::cout << "tidak ada pada tree \n";
    }
    std::cin.get();
    return 0;
}