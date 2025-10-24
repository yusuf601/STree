/**
* @file iterator_preorder.cpp program implementasi dasar traversal tree menggunakan inorder
* traversal dengan pendekatan iteratif.
* @brief urutan traversal
* root ->subtree kiri -> subtree kanan
* @details time complexity O(n),tiap node hanya di kunjungi sekali
*/
#include <iostream>
#include <stack>
#include <vector>
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
void IteratifPreorder(Node* root){
    std::vector<int>res;
    std::stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        res.push_back(node->data);
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
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
    IteratifPreorder(root);
    std::cin.get();
    return 0;
}