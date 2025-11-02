/**
* @file iterator_inorder.cpp program implementasi dasar traversal tree menggunakan inorder
* traversal dengan pendekatan iteratif.
* @brief urutan traversal
* subtree kiri ->root -> subtree kanan
* @details time complexity O(n),tiap node hanya di kunjungi sekali
*/
#include <iostream>
#include <stack>
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
* @brief program untuk Inorder traversal secara Iteratif
* @param root struktur data tree 
*/
void IteratifInorder(Node* root){
    std::stack<Node*>st;
    Node* curr = root;
    while(curr || !st.empty()){
        // masuk ke subtree kiri
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        // masuk ke subtree paling kanan
        curr = st.top();
        st.pop();
        std::cout << curr->data << " ";
        curr = curr->right;
    }
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
    std::cout << "traversal use inorder \n";
    IteratifInorder(root);
    std::cin.get();
    return 0;
}