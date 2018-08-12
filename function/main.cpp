#include<iostream>
#include<functional>

void func(void) {
    std::cout << __FUNCTION__ << std::endl;
}

class StringKey {
 public:
    static int foo_func(int a) {
        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
        return a;
    }
};

class Bar {
 public:
    int operator()(int a) {
        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
        return a;
    }
    void show(int i) {
        printf("Bar --- %d\n", i);
    }
};

int main() {
    // ����ͨ����
    std::function<void(void)> fr1 = func;
    fr1();

    // ����ľ�̬��Ա����
    std::function<int(int)> fr2 = StringKey::foo_func;
    std::cout << fr2(100) << std::endl;

    // �󶨷º���
    Bar bar;
    fr2 = bar;
    std::cout << fr2(200) << std::endl;

    // ��lamada����
    std::function<bool(int)> is_prime([&](int i)->bool {
        std::cout << "not prime" << std::endl;
        return false;
    });
    is_prime(1);

    // �����Ա��������һ������
    typedef std::function<void(int)> ShowFuncT1;
    ShowFuncT1 show1 = std::bind(&Bar::show, &bar, std::placeholders::_1);
    show1(123);

    ShowFuncT1 show11 = std::bind(&Bar::show, &bar, 23);
    // show11(); // ���Ͳ�ƥ��
    show11(1);  // ��1û�ã���Ϊ23�Ѿ���bind�����Ҳ���std::placeholders

    typedef std::function<void(void)> ShowFuncT2;
    ShowFuncT2 show2 = std::bind(&Bar::show, &bar, 2);
    show2();

    // ���Ϸ������벻ͨ��
    // ShowFuncT2 show3 = std::bind(&Bar::show, &bar, std::placeholders::_1);

    return 0;
}
