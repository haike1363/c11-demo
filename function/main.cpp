#include <vector>
#include <iostream>

struct NodeA {
    int id = 0;
    std::string name = "A";
    void Show() {
        printf("NodeA: %d %s\n", id, name.c_str());
    }
};

struct NodeB {
    int id = 1;
    std::string name = "B";
    NodeA nodea;
    NodeB() {

    }
    NodeB(NodeB&& o)
        : name(o.name)
    {
        int t = o.id;
        o.id = id;
        id = t;
    }
    NodeB(const NodeB& o)
        : id(o.id),
          name(o.name),
          nodea(o.nodea)
    {
    }
    NodeB(int i, const std::string& n)
        : id(i),
          name(n)
    {
    }
    void Show() {
        printf("NodeB: %d %s nodea:%d %s\n", id, name.c_str(), nodea.id, nodea.name.c_str());
    }
};

int main(int argc, char **argv) {
    // 标准库类型
    std::vector<std::string> ss;
    std::string s1 = {"s1"};
    ss.push_back(std::move(s1));
    printf("s1:%s\nvector s1:%s\n", s1.c_str(), ss[0].c_str());

    std::string s2 = {"s2"};
    std::string s22(std::move(s2));
    printf("s2:%s\ns22:%s\n", s2.c_str(), s22.c_str());

    std::string s3 = {"s3"};
    s3 = std::move(s22);// 调用swap函数
    printf("s3:%s\ns22:%s\n", s3.c_str(), s22.c_str());

    // 自定义类型
    NodeB nodeb1 = { 1, "B" };
    nodeb1.id = 11;
    nodeb1.name = "B1";

    nodeb1.Show();
    NodeB nodeb2(std::move(nodeb1));
    nodeb1.Show();
    nodeb2.Show();
    return 0;
}