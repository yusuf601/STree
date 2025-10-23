/**
* @file level_order_traversal.cpp program untuk mensimulasikan breadth first search
* @brief breadth first search adalah tree traversal yang melakukan penjelejahan secara 
* melebar dari kiri ke kanan menggunakan queueu sebagai struktur data tambahan
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
void bfs(Node* root){
    if(!root){
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
       Node* curr = q.front();
       q.pop();
       std::cout << curr->data << " ";
        // prioritas kiri
        if(curr->left != nullptr){
            q.push(curr->left);
        } 
        if(curr->right != nullptr){
            q.push(curr->right);
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

    Node *root = new Node(5);
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
    bfs(root);
    std::cin.get();
    return 0;
}