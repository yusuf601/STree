#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data): data(data),left(nullptr),right(nullptr){}
};
Node* insert(Node* root,int key){
    Node* new_node = new Node(key);
    if(!root){
        root = new_node;
        return root;
    }
    Node* curr = root;
    Node* parent = nullptr;
    while(curr){
        parent = curr;
        if(key < curr->data){
            curr = curr->right;
        }else if(key > curr->data){
            curr = curr->right;
        }else{
            return root;
        }
    }
    if(parent->data > key){
        parent->left = new_node;
    }else{
        parent->right = new_node;
    }
    return root;
}
int maximum(Node* root){
    if(!root){
        return 0;
    }
    Node* curr = root;
    while(curr){
        curr = curr->right;
    }
    return curr->data;
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
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 6);
    std::cout << "maximum: " << maximum(root) << "\n";
    std::cin.get();
    return 0;
}