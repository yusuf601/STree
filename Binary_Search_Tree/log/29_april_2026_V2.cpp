#include <bits/stdc++.h>
#include <iterator>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(nullptr),right(nullptr){};
};
Node* insert(Node* root,int data){
    if(!root){
        root = new Node(data);
        return root;
    }
    auto nodes = root;
    Node* parent = nullptr;
    bool insertion = true;
    while(nodes){
        parent = nodes;
        if(data < nodes->data){
            nodes = nodes->left;
        }else if(data > nodes->data){
            nodes = nodes->right;
        }else{
            //duplikat
            return root;
        }
    }
    //if(!insertion){return root;}
    if(parent->data > data){
        parent->left = new Node(data);
    }else{
        parent->right = new Node(data);
    }

    return root;
}
/* 
 * @brief Successor = nilai berikutnya (lebih besar) dalam urutan
 *
 * Ada 2 kasus:
 * 1.Node punya right subtree
 * → ambil paling kiri di subtree kanan
 * 2.Tidak punya right
 * → naik ke atas sampai ketemu parent yang lebih besar
 *
*/
Node* find_Succesor(Node* root,Node* target){
    //case ada right subtree
    if(target->right){
        Node* curr = target->right;
        while(curr->left){
            curr = curr->left;
        }
        return curr;
    }
    //case tidak ada right subtree
    Node* Successor = nullptr;
    auto nodes = root;
    while(nodes){
        if(target->data < nodes->data){
           Successor = nodes;
           nodes = nodes->left;
        }else if(target->data > nodes->data){
            nodes = nodes->right;
        }else{
            break;//dupls
        }
    }
    return Successor;
}
/*
 * @ Predecessor = nilai sebelumnya (lebih kecil) dalam urutan
 * Kebalikan:
 * Node punya left subtree
 * → ambil paling kanan di subtree kiri
 * Tidak punya left
 * → naik ke atas sampai ketemu parent yang lebih kecil
 *
 */
Node* find_Predecessor(Node* root,Node* target){
    if(target->left){
        Node* nodes = target->left;
        while(nodes->right){
            nodes = nodes->right;
        }
        return nodes;
    }
    Node* Predecessor = nullptr;
    auto nodes = root;
    while(nodes){
        if(target->data < nodes->data){
            nodes = nodes->left;
        }else if(target->data > nodes->data){
            Predecessor = nodes;
            nodes = nodes->right;    
        }else{
            break;
        }
    }
    return Predecessor;
    
}
std::pair<Node*,Node*> find_min(Node* root,Node* target){
    Node* parent = nullptr;
    if(target->left){
        Node* nodes = target->left;
        while(nodes->right){
            parent = nodes;
            nodes = nodes->right;
        }
        return {nodes,parent};
    }
    Node* Predecessor = nullptr;
    auto nodes = root;
    while(nodes){
        parent = nodes;
        if(target->data < nodes->data){
            nodes = nodes->left;
        }else if(target->data > nodes->data){
            Predecessor = nodes;
            nodes = nodes->right;    
        }else{
            break;
        }
    }
    return {Predecessor,parent};
    
}

Node* deletedNode(Node* root,Node* target){
    if(!root)return nullptr;
    auto nodes = root;
    Node* parent = nullptr;
    while(nodes){
        parent = nodes;
        if(target->data < nodes->data){
            nodes = nodes->left;
        }else if(target->data > nodes->data){
            nodes = nodes->right;
        }else{
            //node ditemukan atau nullptr;
            break;
        }
    }
    if(!nodes){
        return root;//tidak ditemukan
    }
    bool is_left = false;//agar tidak berulang mencari posisi nodes di 
    if(parent->left == nodes){
        is_left = true;
    }

    // case 1: tidak ada child node
    if(!nodes->left && !nodes->right){
        if(parent->left == nodes){
            parent->left = nullptr;
            delete nodes;
            return root;
        }
        parent->right = nullptr;
        delete nodes;
        return root;
    }
    //case 2: delete node dan relingking dengan parent
    if(!nodes->right || !nodes->left && (!nodes->left && !nodes->right)){
        if(is_left && nodes->right){
            parent->left = nodes->right;    
            delete nodes;
            return root;
        }
        if(is_left && nodes->left){
            parent->left = nodes->left;
            delete nodes;
            return root;
        }
        if(!is_left && nodes->right){
            parent->right = nodes->right;
            delete nodes;
            return root;
        }
        if(!is_left && nodes->left){
            parent->right = nodes->left;
            delete nodes;
            return root;
        }
    }
    //case 3:
    //1.cari inorder Successor
    //2.tukar nilai nodes dengan Successor
    //3.handling delete dengan case 1 atau case 2
    auto [succ,succ_parent] = find_min(root, nodes); //keknya harus cari disini karena
    nodes->data = succ->data;
    //sekarang succ(target) bisa punya 1 anak aja atau tidak ada(best case tp gimana cara relingking parentnya)
    bool is_left_succ = false;
    if(parent->left == succ){
        is_left_succ = true;
    }

    if(!succ->left && !succ->right){
        if(is_left_succ){
            succ_parent->left = nullptr;
            delete succ;
            return root;
        }
        succ->right = nullptr;
        delete succ;
        return root;
    }
    if(!succ->left || !succ->right){
        if(is_left && succ->right){
            parent->left = succ->right;    
            delete succ;
            return root;
        }
        if(is_left && succ->left){
            parent->left = succ->left;
            delete succ;
            return root;
        }
        if(!is_left && succ->right){
            parent->right = succ->right;
            delete succ;
            return root;
        }
        if(!is_left && succ->left){
            parent->right = succ->left;
            delete succ;
            return root;
        }

    }
    return root; //tidak akan pernah sampai sini seharusnya

}
int main(){
    Node* root = nullptr;
    // Mari kita buat BST yang valid
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    return 0;
}
