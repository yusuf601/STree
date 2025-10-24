#include <iostream>
#include <stack>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x){
        this->data = x;
        this->left= nullptr;
        this->right = nullptr;
    }
};
void IteratifPostorderI(Node* root){
    if(!root){
        return;
    }
    std::stack<Node*>st1,st2;
    st1.push(root);
}
int main(){
    std::cin.get();
    return 0;
}