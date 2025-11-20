#include <iostream>
#include <vector>

struct Node{
    int data;
    std::vector<Node> children;
    Node(int data): data(data){}
};

int main(){
    std::cin.get();
    return 0;
}