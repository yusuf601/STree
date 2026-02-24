#include <bits/stdc++.h>
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val),left(nullptr),right(nullptr){}
};

void automatic_insertion(Node* root,std::vector<int>value){
    //langsung insertion pakai bfs(level order traversal)
    //anggapan bahwa front itu root(mahal)
    if(!root){
        root = new Node(value.front());
        if(value.size() == 1){
            return;
        }
        std::queue<Node*>q;
        q.push(root);
        for(auto it = value.begin() + 1;it != value.end();++it){
            //insert disini
            while(!q.empty()){
                auto nodes = q.front();
                q.pop();
                if(nodes->left){
                    q.push(nodes->left);
                }else{
                    nodes->left = new Node(*it);
                    q.push(nodes->left);
                    continue;
                }
                if(nodes->right){
                    q.push(nodes->right);
                }else{
                    nodes->right = new Node(*it);
                    q.push(nodes->right);
                    continue;
                }
            }
        }
        return;
    }
    std::queue<Node*>q;
    q.push(root);
    for(auto x: value){
        while(!q.empty()){
            auto nodes = q.front();
            q.pop();
            if(nodes->left){
                q.push(nodes->left);
            }else{
                nodes->left = new Node(x);
                q.push(nodes->left);
                continue;
            }
            if(nodes->right){
                q.push(nodes->right);
            }else{
                nodes->right = new Node(x);
                q.push(nodes->right);
                continue;
            }
        }
    }
}
void preorder_traversal(Node* root){
    if(!root)return;
    std::stack<Node*>s;s.push(root);
    while(!s.empty()){
        auto nodes = s.top();
        s.pop();
        std::cout << nodes->val << " ";
        if(nodes->right)s.push(nodes->right);
        if(nodes->left)s.push(nodes->left);
    }
}
int main(){
    Node* root = nullptr;
    std::vector<int>v = {1,2,3,4,5,6}
    automatic_insertion(root,v);

    return 0;
}
