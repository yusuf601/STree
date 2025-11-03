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
struct InsertCommand{
    Node* parent;
    Node* node;
    bool is_left;
};
class Command{
    public:
        //pure virtual funciton
        virtual void execute() = 0;
        virtual void undo() = 0;
        //virtual destuctor
        virtual ~Command() = default;
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

//receiver
class BinaryTree{
    private:
        Node* root;
        std::unique_ptr<TraversalStrategy>strategy;
    public: 
        BinaryTree() : root(nullptr){}
    public:
        //false left,true right
        InsertCommand insert(int val){
            Node* new_node = new Node(val);
            if(!root){
                root = new_node;
                return {nullptr,root,false};
            }
            //history
            Node* parent = nullptr;
            Node* child = nullptr;
            bool is_left = false;
            //pakai level order
            std::queue<Node*>q;
            q.push(root);
            Node* p = nullptr;
            int pos = 0;
            while(!q.empty()){
                Node* node = q.front();
                q.pop();
                if(!node->left){
                    node->left = new_node;
                    parent = node;
                    child = node->left;
                    is_left = true;
                    break;
                }else{
                    q.push(node->left);
                }
                if(!node->right){
                    node->right = new_node;
                    parent = node;child = node->right;is_left = false;
                    break;
                }else{
                    q.push(node->right);
                }
            }
            return {parent,child,is_left};
            
        }
        void cancel(InsertCommand& cmd){
            if(cmd.parent == nullptr){
                delete root;
                root = nullptr;
                return;
            }
            if(cmd.is_left){
                cmd.parent->left = nullptr;
            }else{
                cmd.parent->right = nullptr;
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
                    std::cout << node->data << " ";
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
//conrete command insert(implementasi insert node pada tree)
class InsertNode : public Command{
    private:
        BinaryTree& tree;
        int val;
        InsertCommand& cmd;
    public:
        InsertNode(BinaryTree& t,int val,InsertCommand& c) : tree(t),val(val),cmd(c){}
    public:
        void execute()override{
            tree.insert(val);
        }
        void undo()override{
            tree.cancel(cmd);
        }
};
//invoker
class ManageCommand{
    private:
        std::stack<std::unique_ptr<Command>>UndoStack;
        std::stack<std::unique_ptr<Command>>RedoStack;
    public:
        void executeCommand(std::unique_ptr<Command>cmd){
            cmd->execute();
            UndoStack.push(std::move(cmd));
            if(!RedoStack.empty()){
                RedoStack.pop();
            }
        }   
        void Undo(){
            if(UndoStack.empty()){
                return;
            }
            auto cmd = std::move(UndoStack.top());
            UndoStack.pop();
            cmd->undo();
            RedoStack.push(std::move(cmd));
        }
        void redo(){
            if(RedoStack.empty()){
                return;
            }
            auto cmd = std::move(RedoStack.top());
            RedoStack.pop();
            cmd->execute();
            UndoStack.push(std::move(cmd));
        }
};
int main(int argc,char* argv[]){
    //insert history struct
    InsertCommand cmd;
    //buat object receiver
    BinaryTree tree;
    //buat object invoker
    ManageCommand manager;
    //insert
    for(auto val : {1,2,3,4,5,6,7}){
        manager.executeCommand(std::make_unique<InsertNode>(tree,val));
    }
    if(argc < 2){
        std::cerr << "usage: ./program -[traversal strategi]";
    }
    std::string arg = argv[1];
    if(arg == "-in"){
        tree.setStrategy(std::make_unique<inorder>());
    }else if(arg == "-pre"){
        tree.setStrategy(std::make_unique<preorderTraversal>());
    }else if(arg == "-post"){
        tree.setStrategy(std::make_unique<postorder>());
    }else if(arg == "bfs"){
        tree.setStrategy(std::make_unique<levelOrder>());
    }else{
        std::cout << "usage: ./program [traversal strategi]";
    }
    tree.printNode();
    //std::cin.get();
    return 0;
}