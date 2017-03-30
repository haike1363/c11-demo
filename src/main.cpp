#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <array>
#include <time.h>
#include <stdlib.h>
#include "sub.h"
#include "add.h"
#include "gflags/gflags.h"

/*
*/
void testmove() {
    std::string s1 = {"123"};
    std::string s2 = std::move(s1);
    printf("s1:%s  s2:%s\n", s1.c_str(), s2.c_str());
}

void testnullptr() {
    const char* ps = "hello\n";
    if(ps != nullptr) {
        printf(ps);
    }
}

void testinit() {
    class Point {
        int x = -1;
        int y = -1;
    public:
        int getX() { return x; }
        int getY() { return y; }
        Point() = default;
        virtual ~Point() = default;
        Point(int a, int b){ x = a, y = b;}
    };

    int (*pf)(int, int) = nullptr; //指向函数的指针
    pf = add;

    Point p{1, 1};
    Point s;
    printf("%d  %d %d\n", pf(p.getX(), p.getY()), s.getX(), s.getY());
    
    
    class Line{
        Point ps[2];
    public:
        Line(int x1, int y1, int x2, int y2)
            :ps{ {x1, y1}, {x2, y2} }
        {}
        Line(int x2, int y2):Line(0, 0, x2, y2) {}
        Line(): ps{ {0,0}, {0,0} } {}
    };
    Line line;
    printf("line %p\n", &line);
    int* array = new int[3]{ 0, 1, 2 };
    std::for_each(array, array + 3, [](int i) { printf("%d\n", i);});
}


void testauto() {
    std::array<int, 7> foo = {0,1,-1,3,-3,5,-5};
    for(auto i : foo) {
        printf("%d\n", i);
    }
    //初始化Vercor
    std::vector<int> ids = { 1, 2, 3, 4 };
    for(auto it = ids.begin(); it != ids.end(); ++it) {
        std::cout<<"id:" << *it <<std::endl;
    }
    std::map<int, std::string> names = { {1, "A" }, {2, "B"}, {3, "C"} };
    typedef decltype (names.begin()) VIT;
    for(VIT it = names.begin(); it != names.end(); ++it) {
        printf("id:%d name:%s\n", it->first, it->second.c_str());
    }
}

void testlambda() {
    char s[] = { "123456789" };
    std::cout<< std::all_of(s, s +sizeof(s), [](char c){ return c>='1'; }) << std::endl;
    std::cout<< std::any_of(s, s +sizeof(s), [](char c){ return c=='4'; }) << std::endl;
    std::cout<< std::none_of(s, s +sizeof(s), [](char c){ return c=='a'; }) << std::endl;
    int count = 0;
    std::for_each(s, s+sizeof(s), [&count](char c) {
        if(c > '5') {
            ++count;
        }
    });
    printf("large than 5 :%d\n", count);
}

void testlib() {
	std::cout << "hello 1+1=" << add(1, 1) << std::endl;
	std::cout << "hello 1-1=" << sub(1, 1) << std::endl;
}
void testrandom() {
	srand(123);
	for(int i =0 ; i< 10; ++i) {
		std::cout<< "rand " << rand() << std::endl;
	}
}
int main(int argc, char **argv) {
    gflags::AllowCommandLineReparsing();
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	//
	testlib();
	testrandom();
	testlambda();
    testinit();
    testauto();
    testnullptr();
    testmove();
    return 0;
}