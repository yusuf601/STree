#include <iostream>
#include <queue>
#include <stack>
struct Node{
    int x;
    Node* left;
    Node* right;
    Node(int x){
        this->x = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int UsePreOrder(Node* root){
    int cnt = 0;
    std::stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        cnt++;
        if(node->right != nullptr){
            st.push(node->right);
        }
        if(node->left != nullptr){
            st.push(node->left);
        }
    }
    return cnt;
}
int UseInorder(Node* root){
    std::stack<Node*>st;
    Node* node = root;
    int cnt = 0;
    while(!st.empty() || node) {
        while(node){
            st.push(node);
            node = node->left;
        }
        //masuk subtree kanan
        node = st.top();
        st.pop();
        cnt++;
        node = node->right;
    }
    return cnt;
}
int UseLevelOrder(Node* root){
    int cnt = 0;
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cnt++;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return cnt;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    std::cout << "pakai preorder: " << UsePreOrder(root) << "\n";
    std::cout << "pakai Inorder: " << UseInorder(root) << "\n";
    std::cout << "pakai bfs: " << UseLevelOrder(root) << "\n";
    std::cin.get();
    return 0;
}