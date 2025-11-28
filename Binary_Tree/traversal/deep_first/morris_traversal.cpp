/**
 * @file morris_traversal.cpp berisi implementasi code dari morris traversal
 * @brief morris traversal adalah teknik traversal yang dapat menelusuri node secara inorder,preorder,dan postorder tanpa menggunkan stack ataupun rekursif
 * dengan menggunakan morris traversal yang tadinya space complexity adalah O(n),dapat di opmitimisasi menjadi O(1).
 * implementasi morris traversal membutuhkan pemahamanan konsep predecessor
*/

#include <bits/stdc++.h>
struct Node{
  int data;
  Node* left;
  Node* right;
};
Node* insert(Node* root,int val){
  if(!root){
    root = new Node(val);
    return root;
  }
  std::queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* node = q.front();
    q.pop();
    if(!node->left){
      node->left = new Node(val);
      break;
    }else{
      q.push(node->left);
    }
    if(!node->right){
      node->right = new Node(val);
      break;
    }else{
      q.push(node->right);
    }
  }
  return root;
}
Node* max(Node* nodes){
  Node* node = nodes;
  while(node->right){
    node = node->right;
  }
  return node;
}
void morrisTraversal(Node* root){
  Node* node = root;
  while(node){
    if(!node->left){
      //jika tidak punya right child,langsung visit
      std::print("{} ",node->data); //visit
      node = node->right; //kunjungi right child
    }else{
      //cari inorder Predecessor
      Node* tree = node->left;
      if(tree->left && pre->right != node){
        pre = pre->right;
      }
    }
  }
}
int main(){

  std::cin.get();
  return 0;
}
