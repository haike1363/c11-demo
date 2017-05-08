#include <vector>
#include <iostream>

void Print(const std::string& s) {
    printf("%s\n", s.c_str());
}
void testSTLStruct () {
    std::string s1 = "s1";
    // s11偷了s1的 impl
    std::string s11(std::move(s1));
    Print(s1);
    Print(s11);

    std::string s2 = "s2";
    std::string s22 = "s22";
    // 实际调用swap函数
    s22 = std::move(s2);
    Print(s2);
    Print(s22);
};


void testUserBaseStruct() {
    struct DefaultNote {
        DefaultNote() = default;
        ~DefaultNote() = default;
        DefaultNote(const DefaultNote& o) {
            printf("default copy construct\n");
        }
        DefaultNote& operator = (const DefaultNote& o) {
            printf("default assign\n");
            return *this;
        }
        DefaultNote(DefaultNote&& o) {
            printf("default right value copy construct\n");
        }
        DefaultNote& operator = (DefaultNote&& o) {
            printf("default right value assign\n");
            return *this;
        }
    };

    struct Node {
        Node() = default;
#if 1
        Node(const Node& o) {
            printf("user copy construct\n");
        }
#endif

#if 0
        Node& operator = (const Node& o) {
            printf("user assign\n");
            return *this;
        }
#endif

#if 0
        Node(Node&& o) {
            printf("user right value copy construct\n");
        }
#endif 

#if 0
        Node& operator = (Node&& o) {
            printf("user right value assign\n");
            return *this;
        }
#endif
        DefaultNote base;
    };


    Node node;
    Node node1(node);
    node = node;
    Node node2(std::move(node));
    node = std::move(node);
}

int main(int argc, char **argv) {
    testUserBaseStruct();
    testSTLStruct();
    return 0;
}