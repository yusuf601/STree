#include <iostream>
#include <stack>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(nullptr),right(nullptr){}
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
void preorder_traversal(Node* root){
    if(!root)return;
    std::stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        auto nodes = s.top();
        s.pop();
        std::cout << nodes->data << std::endl;
        if(nodes->right)s.push(nodes->right);
        if(nodes->left)s.push(nodes->left);
    }
}
void inorder(Node* root){
    if(!root)return;
    //kiri root kanan
    std::stack<Node*>s;
    auto nodes = root;
    while(nodes || !s.empty()){
        //kekiri dulu sampai mentok
        while(nodes){
            s.push(nodes);
            nodes = nodes->left;
        }
        nodes = s.top();
        s.pop();
        std::cout << nodes->data << " ";
        if(nodes->right){
            nodes = nodes->right;
        }
    }
}
void optimal_postorder(Node* root){
    if(!root)return;
    std::stack<std::pair<Node*,bool>>s;
    s.push({root,false});
    while(!s.empty()){
        auto [nodes,is_visited] = s.top();
        s.pop();
        if(!nodes)continue;
        if(is_visited){
            std::cout << nodes->data << std::endl;
        }else{
            s.push({nodes,true});
            s.push({nodes->right,false});
            s.push({nodes->left,false});
        }
    }
}
void min_postorder(Node* root){
    if(!root){
        return;
    }
    std::stack<Node*>s;
    Node* nodes = root;
    Node* last_visited = nullptr;
    while(nodes || !s.empty()){
        //kekiri sampai mentok
        if(nodes){
            s.push(nodes);
            nodes = nodes->left;
        }else{
            Node* PeekNode = s.top();
            //cek apakah masih ada kanan yang belum ditelusuri
            if(PeekNode->right && last_visited != PeekNode->right){
                nodes = PeekNode->right;
            }else{
                std::cout << nodes->data << " ";
                last_visited = s.top();
                s.pop();
            }
        }
    }
}
int main(){
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root,1);
    root = insert(root,6);
    //Node* root = new Node(5);
    //root->left = new Node(1);
    //root->right = new Node(7);
    preorder_traversal(root);
}
