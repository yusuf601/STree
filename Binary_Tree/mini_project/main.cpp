#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <functional>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class TraversalStrategy{
    public:
        virtual void traverse(Node* root,std::function<void(Node*)> visit) = 0;
        virtual ~TraversalStrategy() = default;
};

class preorderTraversal : public TraversalStrategy{
    public: 
        void traverse(Node* root,std::function<void(Node*)>visit)override{
            if(!root){
                return;
            }
            std::stack<Node*>s;
            s.push(root);
            while(!s.empty()){
                Node* node = s.top();
                s.pop();
                if(node){
                    visit(node);
                }
                if(node->right)s.push(node->right);
                if(node->left)s.push(node->left);
            }
        }
};
class postorder : public TraversalStrategy{
    public:
        void traverse(Node* root,std::function<void(Node* root)>visit)override{
            if(!root){
                return;
            }
            std::stack<Node*>s1;
            std::stack<Node*>s2;
            s1.push(root);
            while(!s1.empty()){
                Node* node = s1.top();
                s1.pop();
                s2.push(node);
                if(node->right)s1.push(node->right);
                if(node->left)s1.push(node->left);
            }
            while(!s2.empty()){
                visit(s2.top());
                s2.pop();
            }
        }
};
class inorder : public TraversalStrategy{
    public:
        void traverse(Node* root,std::function<void(Node* root)>visit) override{
            if(!root){
                return;
            }
            std::stack<Node*>s;
            Node* node = root;
            while(node || !s.empty()){
                while(node){
                    s.push(node);
                    node = node->left;
                }
                node = s.top();
                s.pop();
                visit(node);
                node = node->right;
            }
        }
};
class levelOrder : public TraversalStrategy{
    public:
        void traverse(Node *root, std::function<void (Node *)> visit) override{
            if(!root){
                return;
            }
            std::queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* node = q.front();
                q.pop();
                visit(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
};
class BinaryTree{
    private:
        Node* root;
        std::unique_ptr<TraversalStrategy>strategy;
    public: 
        BinaryTree() : root(nullptr){}
    public:
        void insert(int val){
            Node* new_node = new Node(val);
            if(!root){
                root = new_node;
                return;
            }
            //pakai level order
            std::queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* node = q.front();
                q.pop();
                if(!node->left){
                    node->left = new_node;
                    break;
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
        void setStrategy(std::unique_ptr<TraversalStrategy>strategi){
            this->strategy = std::move(strategi);
        }
        void printNode(){
            if(!strategy){
                std::cerr << "strategi belum dipilih!";
                return;
            }
            strategy->traverse(root, [](Node* node) {
                if(node){
                    std::cout << node->data << "\n";
                }
            });
            std::cout << "\n";
        }

        int size_node(){
            if(!root){
                return 0;
            }
            if(!strategy){
                std::cerr << "strategi belum dipilih!";
                return -1;
            }
            int count = 0;
            strategy->traverse(root,[&](Node* node){
                if(node){
                    count++;
                }
            });
            return count;
        }
        bool search(int x){
            if(!root){
                return false;
            }
            if(!strategy){
                std::cerr << "strategi belum dipilih!";
                return -1;
            }
            bool checked = false;
            strategy->traverse(root,[&](Node* node){
                if(node->data == x){
                    checked = true;
                }
            });
            return checked;
        }
        int sum_nodes(){
            if(!root){
                return false;
            }
            if(!strategy){
                std::cerr << "strategi belum dipilih!";
                return -1;
            }
            int sum = 0;
            strategy->traverse(root,[&](Node* node){
                sum += node->data;
            });
            return sum;
        }
};
int main(){
    BinaryTree tree;
    for(auto val: {1,2,3,4,5,6,7}){
        tree.insert(val);
    }
    // std::cout << "ini semua memakai inorder traversal" << std::endl;
    tree.setStrategy(std::make_unique<preorderTraversal>());
    std::cout << "jumlah node: " << tree.sum_nodes() <<  "\n";
    std::cout << "cari node 4,apakah ada ";
    if(tree.search(4)){
        std::cout << "ya\n";
    }else{
        std::cout << "ngak\n";
    }
    std::cout << "size node: " << tree.size_node() << "\n";
    std::cout << "print node \n";
    tree.printNode();
    //std::cin.get();
    return 0;
}