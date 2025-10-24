/**
* @file program untuk implementasi tree traversal menggunakan postorder traversal menggunakan
* pendekatan iteratif.
* @brief urutan postorder traversal:
* subtree kiri -> subtree kanan -> root
* ada 2 pendekatan yang dipakai dalam iteratif postorder,yaitu:
* 1.menggunakan 2 stack
* stack pertama dipakai untuk traversal seperti preorder(root->subtree kiri->subtree kanan)
* stack kedua untuk menampung hasil terbalik(subtree kanan->subtree kiri->root)
* 2.Menggunakan 1 stack 
* jika menggunakan 1 stack harus menambahkan pointer lastVisited,untuk menandai apakah node
* ini sudah dikunjungi atau belum
*/
#include <iostream>
#include <stack>
#include <vector>
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
    while(!st1.empty()){
        Node* node = st1.top();
        st1.pop();
        st2.push(node); //root masuk ke st2
        if(node->left){
            st1.push(node->left);
        }
        if(node->right){
            st1.push(node->right);
        }
    }
    // balik
    std::vector<int>res;
    while(!st2.empty()){
        res.push_back(st2.top()->data);
        st2.pop();
    }
    for(auto x: res){
        std::cout << x << " ";
    }
    // left -> right->root
}
void IteratifPostorderII(Node* root){
    if(!root){return;}
    std::vector<int>res;
    std::stack<Node*>st;
    Node* curr = root;
    Node* lastVisited = nullptr;
    while(curr || !st.empty()){
        if(curr){
            //push semua node di kiri
            st.push(curr->left);
            curr = curr->left;
            // selesai jika mentok kiri
        }else{
            Node* peek = st.top();
            if(peek->right && lastVisited != peek->right){
                curr = peek->right; //kekanan
            }else{
                res.push_back(peek->data);
                lastVisited = peek;
                st.pop();
            }
        }
    }
    for(auto x: res){
        std::cout << x << " ";
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
    std::cin.get();
    return 0;
}