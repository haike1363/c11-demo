#include <iostream>
#include <functional>
#include "cds_string_set.h"
void test() {
    CDSStringSet tickets_set_;
    bool ret = tickets_set_.insert("1");
    std::cout<<"insert ret " << ret<< std::endl;

    ret = tickets_set_.insert("2");
    std::cout<<"insert ret " << ret<< std::endl;

    ret = tickets_set_.insert("2");
    std::cout<<"insert ret must be false :" << ret<< std::endl;
}

int main() {
    test();
    return 0;
}