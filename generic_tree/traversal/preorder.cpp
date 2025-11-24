#include <print>
#include <vector>
#include <stack>
#include <queue>
struct Node{
  int data;
  std::vector<Node*>children;
  Node(int data): data(data){}
};
//iterative insertion use case filesystem,insertion base on parent
void insertion(Node* root,int parent,Node* val){
  //insert memakai level order traversal
  std::queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* node = q.front();
    q.pop();
    if(node->data == parent){
      node->children.push_back(val);
      return;
    }
  }
}
//iterative preorder traversal
void preorder(Node* root){
  //root->kiri->kanan
  if(!root){
    return;
  }
  std::stack<Node*>s;
  s.push(root);
  while(!s.empty()){
    Node* node = s.top();
    s.pop();
    std::print("{} ",node->data);
    //proses node dari kiri ke kanan
    for(int i = node->children.size();i >= 0;i--){
      s.push(node->children[i]);
    }
  }

}

int main(){
  Node* root = new Node(5);
  Node* new_node = new Node(14);
  insertion(root,5,new_node);

  std::println("generics tree");
  return 0;

}
