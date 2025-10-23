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
int height(Node* root){
    if(!root){
        return 0;
    }
    std::queue<Node*>q;
    q.push(root);
    int depth = 0;
    while(!q.empty()){
        int levelSize = q.size();
        for(int i = 0;i < q.size();i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
        depth++;
    }
    return depth;
}
int main(){
    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    std::cout << "max depth: " << height(root) << "\n";
    std::cin.get();
    return 0;
}