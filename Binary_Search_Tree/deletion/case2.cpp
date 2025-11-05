/**
* @file case2.cpp program untuk memhapus node pada binary search tree yang dimana kondisi nya
* memiliki 1 anak
* @brief karena node yang akan dihapus memiliki 1 anak(child),maka kemunkinan anak node yang akan
* di hapus akan berada di kanan atau dikiri saja,strategi utama adalah track parent dari node yang
* akan dihapus dan relinking dengan anak dari node yang akan dihapus
* @details time complexity O(h),dimana h = tinggi tree
* average O(n log n) ->super linear
* worst O(n) ->jika tree skewed
*/
#include <iostream>
#include <stack>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data),left(nullptr),right(nullptr){}
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
            return root;//hindari duplikasi
        }
    }
    if(key < parent->data){
        parent->left = new_node;
    }else{
        parent->right = new_node;
    }
    return root;
}
void inorder(Node* root){
    if(!root){
        return;
    }
    std::stack<Node*>s;
    Node* curr;
    while(curr || !s.empty()){
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();   
    }
}
Node* deleteNode(Node* root,int key){
    if(!root){
        return nullptr;
    }
    Node* parent = nullptr;
    Node* curr = root;
    //cari parent dari node yang ingin dihapus
    while(curr && curr->data != key){
        parent = curr;
        if(key < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    //note:
    //curr = menunjuk node yang akan dihapus
    //parent = menunjuk parent node dari curr(node yang akan dihapus)
    if(!curr){
        return root;
    }
    //karena case 2 node yang dihapus punya 1 anak,maka ada 2 kemunkinan yaitu 
    //anak nya berada di kiri dan dikanan.
    if((curr->left && !curr->right) || (!curr->left && curr->right)){
        Node* child = curr->left ? curr->left : curr->right;
        //jika node adalah root
        if(!parent){
            delete curr;
            return child; // anak jadi root yang baru
        }
        if(parent->left == curr){
            parent->left = child;
        }else{
            parent->right = child;
        }
        delete curr;
        return root;
    }
    return root;
}
int main(){
    std::cin.get();
    return 0;
}