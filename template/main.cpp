#include <iostream>
#include <functional>
#include <type_traits>

struct Node {
};
std::ostream& operator<<(std::ostream& stm, const Node& node) {
    stm<<"to string";
    return stm;
}

struct Node2 {
};

template<typename T, bool is_to_string>
inline typename std::enable_if<is_to_string>::type
show(const T& v) {
    std::cout<<"has cout "<<v<<std::endl;
}

template<typename T, bool is_to_string>
inline typename std::enable_if<!is_to_string>::type
show(const T& v) {
    std::cout<<" no cout type "<<std::endl;
}

int main() {
    show<Node, true>(Node());
    show<Node2, false>(Node2());
    return 0;
}