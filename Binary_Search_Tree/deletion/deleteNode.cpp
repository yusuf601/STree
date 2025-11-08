#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data): data(data),left(nullptr),right(nullptr){}
};
Node* insertNode(Node* root,int key){
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
            curr = curr->left;
        }else if(key > curr->data){
            curr = curr->right;
        }else{
            return root;
        }
    }   
    if(key < parent->data){
        parent->left = new_node;
    }else {
        parent->right = new_node;
    }
    return root;
}
void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
//
std::pair<Node*,Node*>min(Node* nodes){
    Node* node = nodes;
    Node* parent = nullptr;
    while(node && node->left){
        parent = node;
        node = node->left;
    }
    return {node,parent};
}
Node* deleteNode(Node* root,int nodes){
    if(!root){
        return nullptr;
    }
    //cari node yg akan dihapus
    Node* node = root;
    Node* parent = nullptr;
    while(node && node->data != nodes){
        parent = node;
        if(nodes < node->data){
            node = node->left;
        }else{
            node = node->right;
        }
    }
    if(!root){
        return root;
    }
    //kasus 0 dan 1 anak
    if(!node->left || !node->right){
        Node* child = node->left ? node->left : node->right;
        if(!parent){
            root = child;
        }else if(parent->left == node){
            parent->left = child;
        }else{
            parent->right = child;
        }
        delete node;
        //kasus 2 anak
    }else{
        auto [succ,succParent] = min(node->right);
        //salin nilai key dari succesor
        node->data = succ->data;
        //hapus succesor
        Node* succChild = succ->right;
        if(succParent){
            if(succParent->left == succ){
                succParent->left = succChild;
            }else{
                succParent->right = succChild;
            }
        }
        delete succ;
    }
    return root;
}
int main(){
    std::cin.get();
    return 0;
}