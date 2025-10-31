#include <iostream>
#include <deque>
#include <stack>
#include <vector>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
/**
* klasifikasi mirror tree,tree dapat dikatakan mirror jika subtree kanan padaa tree b sama dengan
* subtree kiri pada subtree a
* preorder traversal,root->kiri->kanan try reverse ->kanan->kiri->root
*/
class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        //ide 1 pakai preorder trus reverse,if same return true otherwise return false
        //ide 2 pakai preorder tetapi buat terbalik aja.pakai ide 1
        std::stack<Node*>s1,s2;
        std::deque<int>q1;
        std::stack<int>q2;
        s1.push(a);
        while(!s1.empty()){
            Node* node = s1.top();
            s1.pop();
            q1.push_back(node->data);
            if(node->right)s1.push(node->right);
            if(node->left)s1.push(node->left);
        }
        int root1 = q1.front();
        q1.pop_front();
        s2.push(b);
        while(!s2.empty()){
            Node* node = s2.top();
            s2.pop();
            q2.push(node->data);
            if(node->right)s2.push(node->right);
            if(node->left)s2.push(node->left);
        }
        std::stack<int>res;
        if(!q2.empty()){
            res.push(q2.top());
            q2.pop();
        }
        int root2 = res.top();
        if(root2 == root1){
            while(!q1.empty() || !res.empty()){
                if(q1.back() != res.top()){
                    return false;
                }
                q1.pop_back();
                res.pop();
            }
            return true;
        }
        return false;
    }
};
void debug(Node* a,Node* b){
    std::stack<Node*>s1,s2;
    std::deque<int>q1,q2;
    s1.push(a);
    while(!s1.empty()){
        Node* node = s1.top();
        s1.pop();
        q1.push_back(node->data);
        if(node->right)s1.push(node->right);
        if(node->left)s1.push(node->left);
    }
    int root1 = q1.front();
    q1.pop_front();
    s2.push(b);
    // while(!q1.empty()){
    //     std::cout << q1.back() << " ";
    //     q1.pop_back();
    // }
    while(!s2.empty()){
        Node* node = s2.top();
        s2.pop();
        q2.push_back(node->data);
        if(node->right)s2.push(node->right);
        if(node->left)s2.push(node->left);
    }
    std::vector<int>res;
    //postordeerr
    // std::cout << q2.size() << " ";
    int root2 = q2.front();
    q2.pop_front();
    for(auto i = q2.rbegin();i != q2.rend();i++){
        res.push_back(*i);
        std::cout << *i << " ";
    }   
    // std::cout << "\n";
    // for(auto i = res.begin();i != res.end();i++){
    //     std::cout << *i << " ";
    // }
    std::cout << "\n";
    for(auto it = q1.rbegin();it != q1.rend();it++){
        std::cout << *it << " ";
    }

}
void cari_solusi(Node* a,Node* b){
    std::stack<Node*>s1,s2;
    s1.push(a);
    s2.push(b);
    std::vector<int>res1,res2;
    while(!s1.empty()){
        Node* node = s1.top();
        s1.pop();
        res1.push_back(node->data);
        if(node->right)s1.push(node->right);
        if(node->left)s1.push(node->left);
    }
    while(!s2.empty()){
        Node* node = s2.top();
        s2.pop();
        res2.push_back(node->data);
        if(node->right)s2.push(node->right);
        if(node->left)s2.push(node->left);
    }
    //try reverse res2;
    int root1 = res1.front();
    res1.erase(res1.begin() + 0);
    int root2 = res2.front();
    res2.erase(res2.begin() + 0);
    res2 = std::vector<int>(res2.rbegin(),res2.rend());
    std::cout << root1 << " " << root2 << "\n";
    for(int i = 0;i < res2.size();i++){
        std::cout << res1[i] << " " << res2[i] << "\n";
    }
}
bool checked(Node* a,Node* b){
    std::stack<Node*>s1,s2;
    s1.push(a);
    s2.push(b);
    while(!s1.empty() && !s2.empty()){
        //s1
        Node* node1 = s1.top();
        s1.pop();
        //s2
        Node* node2 = s2.top();
        s2.pop();
        if(node1->data != node2->data){
            return false;
        }
        //check mirror
        if(node1->left && node2->right){
            s1.push(node1->left);
            s2.push(node2->right);
        }else if(node1->left || node2->right){
            return false;
        }
        if(node1->right && node2->left){
            s1.push(node1->right);s2.push(node2->left);
        }else if(node1->right || node2->left){
            return false;
        }
    }
    return s1.empty() && s2.empty();
}
int main(){
        // Representation of input binary tree 1
    //        1
    //       / \
    //      3   2
    //          / \
    //         5   4
    Node* root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);
    Solution sol;
     // Representation of input binary tree 2 (mirror)
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    if(checked(root1,root2)){
        std::cout << "true\n";
    }else{
        std::cout << "false\n";
    }
    //debug(root1,root2);
   // cari_solusi(root1,root2);
    //std::cin.get();
    return 0;
}