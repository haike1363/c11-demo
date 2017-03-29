#include <iostream>
#include "sub.h"
#include "add.h"
#include "gflags/gflags.h"

int main(int argc, char **argv) {
    gflags::AllowCommandLineReparsing();
	gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << "hello 1+1=" << add(1, 1) << std::endl;
	std::cout << "hello 1-1=" << sub(1, 1) << std::endl;
    return 0;
}