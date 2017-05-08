#include<iostream>
#include<functional>

void func(void)
{
    std::cout << __FUNCTION__ << std::endl;
}

class Foo
{
public:
    static int foo_func(int a)
    {
        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
        return a;
    }
};

class Bar
{
public:
    int operator() (int a)
    {
        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
        return a;
    }
    void show(int i) {
        printf("Bar --- %d\n", i);
    }
};

int main()
{
    // 绑定普通函数
    std::function<void(void)> fr1 = func;
    fr1();

    // 绑定类的静态成员函数
    std::function<int(int)> fr2 = Foo::foo_func;
    std::cout << fr2(100) << std::endl;

    // 绑定仿函数
    Bar bar;
    fr2 = bar;
    std::cout << fr2(200) << std::endl;

    // 绑定类成员函数，带一个参数
    typedef std::function<void(int)> ShowFuncT1;
    ShowFuncT1 show1 = std::bind(&Bar::show, &bar, std::placeholders::_1);
    show1(123);

    ShowFuncT1 show11 = std::bind(&Bar::show, &bar, 23);
   // show11(); // 类型不匹配
    show11(1); // 传1没用，因为23已经被bind过，且不是std::placeholders

    typedef std::function<void(void)> ShowFuncT2;
    ShowFuncT2 show2 = std::bind(&Bar::show, &bar, 2);
    show2();

    // 不合法，编译不通过
    // ShowFuncT2 show3 = std::bind(&Bar::show, &bar, std::placeholders::_1);

    return 0;
}