/**
 * @file level_order.cpp code untukk mengimplementasikan level_order traversal pada generic tree
 * @brief level order traversal adalah tipe traversal yang mengunjungi node tiap level,menggunakan queue untuk menyimpan node
 * yang dikunjungi
 *
*/
#include <print>
#include <queue>
#include <vector>
struct Node{
  int data;
  std::vector<Node*>children;
  Node(int val): data(val){};
};

Node* FindNode(Node* root,int val){
  //pakai queue untuk search
  if(!root){
    return nullptr;
  }
  std::queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* node = q.front();q.pop();
    if(node->data == val){
      return node;
    }
    for(auto child: node->children){
      q.push(child);
    }
  }
  return nullptr;
}

bool insert(Node* root,int parent,int val){
  Node* parentNode = FindNode(root,parent);
  if(!parentNode){
    return false;
  }
  Node* new_node = new Node(val);
  //chaining karena tidak ada parent node
  parentNode->children.push_back(new_node);
  return true;
}

void level_order(Node* root){
  if(!root){return;}
  std::queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* node = q.front();
    q.pop();
    std::print("{} ",node->data);
    for(auto child: node->children){
      q.push(child);
    }
  }
}

int main(){
  Node* root;
  return 0;
}
