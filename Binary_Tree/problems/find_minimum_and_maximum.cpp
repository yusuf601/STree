#include <cstdint>
#include <iostream>
#include <stack>
struct Node{
    int x;
    Node* left;
    Node* right;
    Node(int x): x(x),left(nullptr),right(nullptr){}
};
class Solution {
  public:
    //preorder
    int findMax(Node *root) {
        int _max = INT32_MIN;
        std::stack<Node*>s;
        s.push(root);
        while(!s.empty()){
            Node* node = s.top();
            s.pop();
            if(_max < node->x){
                _max = node->x;
            }
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return _max;
    }   

    int findMin(Node *root) {
        int _max = INT32_MAX;
        std::stack<Node*>s;
        s.push(root);
        while(!s.empty()){
            Node* node = s.top();
            s.pop();
            if(_max > node->x){
                _max = node->x;
            }
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return _max;
    }
};
int main(){
    std::cin.get();
    return 0;
}