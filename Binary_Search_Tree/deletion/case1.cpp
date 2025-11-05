#include <iostream>
#include <stack>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        Node::data = data;
        Node::left = nullptr;
        Node::right = nullptr;;
    }
};
Node* insertNode(Node* root,int key){
    Node* new_node = new Node(key);
    if(!root){
        root = new_node;
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
            return root; //hindari duplicate
        }
    }
    if(key < parent->data){
        parent->left = new_node;
    }else{
        parent->right = new_node;
    }
    return root;
}
Node* DeleteNode(Node* root,int key){
    if(!root){
        return root;
    }
    Node* parent = nullptr;
    Node* curr = root;
    //cari parent dari node yang akan dihapus
    while(curr && curr->data != key){
        parent = curr;
        if(key < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    //jika tidak ditemukan
    if(!curr){
        return root;
    }
    //kasus 1:node yang ingin dihapus leaf
    if(curr->left == nullptr && curr->right == nullptr){
        //jika node yang dihapus adalah root
        if(!parent){
           delete curr;
           return nullptr; 
        }
        if(parent->left == curr){
            parent->left = nullptr;
        }else{
            parent->right = nullptr;
        }
        delete curr;
        return root;
    }
    return root;
}
void inorder(Node* root){
    std::stack<Node*>s;
    Node* curr = root;
    while(!s.empty() || curr){
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        std::cout << curr->data << " ";
        curr = curr->right; //pada subtree kiri jika ada child kanan maka jelajahi.
    }
    std::cout << "\n";
}   
int main(){
    Node* root = nullptr;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 6);
    inorder(root);
    DeleteNode(root,6);
    inorder(root);
    std::cin.get();
    return 0;
}