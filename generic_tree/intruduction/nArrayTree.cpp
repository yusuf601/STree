#include <iostream>
#include <vector>
#include <queue>
#include <print>
struct Node{
    int data;
    //Node* parent;
    std::vector<Node*> children;
    Node(int data): data(data){}
};
//find
Node* findNode(Node* root,int target){
  if(!root){
    return nullptr;
  }
  //cari menggunakan breadth first search
  std::queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* node = q.front();
    q.pop();
    if(node->data == target){
      return node;
    }
    //proses node
    for(auto child: node->children){
      q.push(child);
    }
  }
  return nullptr;
}
//insertion n array tree
/**
 * @brief fungsi untuk insertion pada n array tree berbasis parent node yang bias digunakan pada filesytem dan decision tree
 *
*/
bool insertion(Node* root,int parent,int val){
  Node* parentNode = findNode(root,parent);
  //kondisi parent tidak ditemukan atau root nullptr
  if(!parentNode){
    return false;
  }
  Node* new_node = new Node(val);
  parentNode->children.push_back(new_node);
  return true;
}
void print(Node* root){
  std::println("root: {}",root->data);
  for(auto c1: root->children){
    std::println("child of {} :{}", root->data,c1->data);
    for(auto c2: c1->children){
      std::println("child of {} : {}",c1->data,c2->data);
    }
  }
}
int main(){
    Node* root = new Node(1);
    insertion(root,1,2); //insert node 2 base on parent node 1
    insertion(root,1,3); //insert node 3 base on parent node 1
    insertion(root,2,4);// insert node 4 base on parent node 2
    print(root);
    std::cin.get();
    return 0;
}
