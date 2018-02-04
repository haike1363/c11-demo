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
        // 无参构造
        DefaultNote() {

        }
        // 析构
        ~DefaultNote() {

        }
        // 拷贝构造
        DefaultNote(const DefaultNote& o) {
            printf("default copy construct\n");
        }
        // 赋值
        DefaultNote& operator = (const DefaultNote& o) {
            printf("default assign\n");
            return *this;
        }
        // 右值构造
        DefaultNote(DefaultNote&& o) {
            printf("default right value copy construct\n");
        }
        // 右值赋值
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

void transRValue(std::vector<int> && rvec) {
    std::cout<< rvec.size();
}
void testRValue() {
    std::vector<int> tmp = {1, 2, 3};
    transRValue(std::move(tmp));
}

int main(int argc, char **argv) {
    testRValue();
    testUserBaseStruct();
    testSTLStruct();
    return 0;
}