#include <iostream>
/**
 * @brief Traversal berhenti ketika call stack kosong
    setiap fungsi dipanggil ditambahkan ke call stack
    ketika base case terpenuhi exec return
    dengan return fungsi akan memanggil fungsi yang memanggilnya
* @details ada 3 traversal tree,yaitu preorder,postorder,dan inorder

*/
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x): data(x){
        this->left = nullptr;
        this->right = nullptr;
    }
};
/**
 * @brief inorder tree
 * inorder tree,adalahh traversal yang menjelajahi node paling kiri dahulu
 * sampai node leaf paling bawah lalu pindah ke node kanan
 * @param root struktur data root
 */
void preorder(Node* root){
    if(!root){ //base case
        return;
    }
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
/**
 * @brief inorder tree
 * preorder tree,adalahh traversal yang menjelajahi node leaf paling kiri dahulu
 * lalu naik sampai root lalu lakukan hal yang dengan node kiri
 * @param root struktur data root
 */
void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
/**
 * @brief postorder tree
 * postorder,adalahh traversal yang menjelajahi node paling kiri(left),lalu pindah ke
 * node paling kanan,terakhir kembali ke node parent
 * @param root struktur data root
 */
void postorder(Node* root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}
int main(){
    // Membuat tree manual:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    std::cout << "preorder traversal" << std::endl;
    preorder(root);
    std::cout << "\ninorder traversal" << std::endl;
    inorder(root);
    std::cout << "\npostorder traversal\n";
    postorder(root); 
    std::cin.get();
    return 0;
}