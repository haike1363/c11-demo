#include <iostream>
#include <map>
#include <sstream>
#include <list>
#include "boost_serialize_helper.hpp"
#include "to_string_helper.hpp"

struct Node {
    int a = 1;
    std::string b = "b";
    long c = 3;
    double d = 4.0f;
    std::map<std::string, long> sl_map;
    std::vector<long> ids;
    std::list<int> lids;
    long v8;
    long v9;
    char v10;
    float v11;
    short v12;

    ENABLE_BOOST_SERIALIZE(a, b, c, d, sl_map, ids, lids, v8, v9, v10, v11, v12)
};

void test() {
    Node node;
    node.d = 1.0f;
    std::string buf = BOOST_SERIALIZE(node);
    std::cout<<buf<<std::endl;

    Node node2;
    BOOST_UNSERIALIZE(buf, node2);
    std::cout << node2.d << "\n"; 
}

struct ToStringNode {
    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    int v4 = 4;
    int v5 = 5;
    int v6 = 6;
    int v7 = 7;
    int v8 = 8;
    int v9 = 9;
    int v10 = 10;
    int v11 = 11;
    int v12 = 12;

    ENABLE_TO_STRING_HELP(v1, v2, v3, v4, v10, v11, v12)
};

void testToString(){
    ToStringNode node;
    std::cout << TO_STRING_HELP(node.v1) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6, node.v7) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6, node.v7, node.v8) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6, node.v7, node.v8, node.v9) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6, node.v7, node.v8, node.v9, node.v10) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6, node.v7, node.v8, node.v9, node.v10, node.v11) << std::endl;
    std::cout << TO_STRING_HELP(node.v1, node.v2, node.v3, node.v4, node.v5, node.v6, node.v7, node.v8, node.v9, node.v10, node.v11, node.v12) << std::endl;

    std::cout << "==========" << std::endl;
    std::cout << node.to_string_help() << std::endl;
}

int main() {
    test();
    testToString();
    return 0;
}
