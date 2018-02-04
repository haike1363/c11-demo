#include <iostream>
#include <memory>

struct Node {
};
typedef std::shared_ptr<Node> NodePtr;

int main() {
    NodePtr ptr;
    std::cout<<"shared_ptr default is nullptr?"<< (ptr == nullptr) << std::endl;
    return 0;
}