#include <iostream>
#include <queue>
class Binary_tree{
    private:
        struct Node{
            int data;
            Node* left;
            Node* right;
            Node(int data): data(data){
                this->left = nullptr;
                this->right = nullptr;
            }
        };
        Node* root;
    public:
        //default constructor
        Binary_tree(){};
    public:
        void new_node(const int x){
            Node* node = new Node({});
            node->data = x;
            node->left = nullptr;
            node->right = nullptr;
        }
        void insert(const int x){
            std::queue<Node*>q;
            q.push(root);
        }

};
int main(){

    std::cin.get();
    return 0;
}