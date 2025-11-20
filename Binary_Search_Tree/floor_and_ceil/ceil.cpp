#include <iostream>
#include <stack>
#include <algorithm>
struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int data): data(data),left(nullptr),right(nullptr){}
};
Node* insert(Node* root,int val){
  if(!root){
    root = new Node(val);
  }
  Node* parent = nullptr;
  Node* node = root;
  while(node){
    parent = node;
    if(val < node->data){
      node = node->left;
    }else if(val > node->data){
      node = node->right;
    }else{
      return root;//duplicates
    }
  }
  if(val < parent->data){
    parent->left = new Node(val);
  }else{
    parent->right = new Node(val);
  }
  return root;
}
int ceil(Node* root,int key){
  if(!root){
    return -1;
  }
  //case 
  //1.jika key ditemukan di binary search tree maka return key
  //2.jika tidak maka kembalikan nilai terbesar setelah key
  //int _max = INT32_MAX;
  int _min = INT32_MAX;
  //inorder traversal
  std::stack<Node*>s;
  Node* node = root;
  bool checked = false;
  while(!s.empty() || node){
    while(node){
    s.push(node);
    node = node->left;
    }
    node = s.top();
    s.pop();
    if(node->data == key){
      return key;
    }
    if(node->data > key){
      checked = true;
      _min = std::min(_min,node->data);
    }
    node = node->right;
  }
  if(!checked){
    return -1;
  }
  return _min;
}
int optimization(Node* root,int x){
  if(!root){
    return -1;
  }
  int successor = -1;
  while (root) {
      if (x == root->data) {
          return x;  // case 1: key ditemukan
      }
      else if (x < root->data) {
          successor = root->data; // calon successor
          root = root->left;
      }
      else {
          root = root->right;
      }
  }

    return successor; // jika tidak dapat successor → tetap -1
}
int main(){
   /**
          8
        /   \
     4      12
   /  \    /  \
2    6  10   14

Key: 11  Ceil: 12
Key: 1   Ceil: 2
Key: 6  Ceil: 6
Key: 15 Ceil: -1
*/
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
  std::cout << ceil(root,6) << std::endl;; //expected 8
 // std::cin.get();
  return 0;
}
