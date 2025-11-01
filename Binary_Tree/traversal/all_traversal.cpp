#include <iostream>
#include <stack>
#include <queue>
#include <memory>
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
class TraversalStrategy{ //->interface
    public:
        virtual void traverse(Node* root) = 0;
        virtual ~TraversalStrategy() = default;
};

class inorderTraversal : public TraversalStrategy{
    public:
        void traverse(Node* root) override{
            if(!root){
                return;
            }
            std::stack<Node*>s;
            Node* curr = root;
            while(!s.empty() || curr){
                while(curr){
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                std::cout << curr->data << " ";
                curr = curr->right;
            }
        }
};
//root-subtree kiri - subtree kanan
class preorderTraversal : public TraversalStrategy{
    public:
        void traverse(Node* root) override{
            std::stack<Node*>s;
            s.push(root);
            while(!s.empty()){
                Node* node = s.top();
                s.pop();
                std::cout << node->data << " ";
                if(node->right)s.push(node->right);
                if(node->left)s.push(node->left);
            }
        }
};
class postorder : public TraversalStrategy{
    public:
        void traverse(Node* root) override{
            std::stack<Node*>s1;
            std::stack<int>s2;
            s1.push(root);
            while(!s1.empty()){
                Node* node = s1.top();
                s1.pop();
                s2.push(node->data);
                if(node->right)s1.push(node->right);
                if(node->left)s1.push(node->left);
            }
            while(!s2.empty()){
                std::cout << s2.top() << " ";
                s2.pop();
            }
        }
};

class levelOrder : public TraversalStrategy{
    public:
        void traverse(Node* root) override{
            std::queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* node = q.front();
                q.pop();
                std::cout << node->data << " ";
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
};
class BinaryTree{
    private:
        Node* root;
        std::unique_ptr<TraversalStrategy> strategy;
    public:
        BinaryTree() : root(nullptr){}

    public:
        void insert(int val){
            //pakai lvvel order traversal
            Node* new_node = new Node(val);
            if(!root){
                root = new_node;
                return;
            }
            std::queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* node = q.front();
                q.pop();
                if(!node->left){
                    node->left = new_node;
                    break;;
                }else{
                    q.push(node->left);
                }
                if(!node->right){
                    node->right = new_node;
                    break;
                }else{
                    q.push(node->right);
                }
            }
        }
        //setter
        void setStrategy(std::unique_ptr<TraversalStrategy>newstrategy){
            strategy = std::move(newstrategy);
        }
        void traversal(){
            if(!strategy){
                std::cout << "strategi loop belum diatur\n";
                return;
            }
            strategy->traverse(root);
            std::cout << "\n";
        }
};
int main(int argc,char* argv[]){
    BinaryTree tree;
    for(int val: {1,2,3,4,5,6,7}){
        tree.insert(val);
    }
    std::cout << "preorder: \n";
    tree.setStrategy(std::make_unique<preorderTraversal>());
    tree.traversal();
    std::cout << "\n";

    std::cout << "inorder: \n";
    tree.setStrategy(std::make_unique<inorderTraversal>());
    tree.traversal();
    std::cout << "\n";

    std::cout << "postorder: \n";
    tree.setStrategy(std::make_unique<postorder>());
    tree.traversal();
    std::cout << "\n";

    std::cout << "level order: \n";
    tree.setStrategy(std::make_unique<postorder>());
    tree.traversal();
    std::cout << "\n";
    std::cin.get();
    return 0;
}