#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include "future_fun.h"

std::string doA() {
    std::random_device rd;
    std::cout<<"doing A ...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(rd()%1000));
    std::cout<<"A done\n";
    return "A";
}

std::string doB() {
    std::random_device rd;
    std::cout<<"doing B ...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(rd()%1000));
    std::cout<<"B done\n";
    return "B";
}

std::string doC() {
    std::random_device rd;
    std::cout<<"doing C ...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(rd()%1000));
    std::cout<<"C done\n";
    return "C";
}

std::string doX(std::string a, std::string b, std::string c) {
    std::random_device rd;
    std::cout<<"doing X with A " << a
        << " with B " << b 
        << " with C " << c
        << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rd()%1000));
    std::cout<<"X done\n";
    return "X";
}

std::string doZ(std::string a, std::string x) {
    std::random_device rd;
    std::cout<<"doing Z with A " << a
        << " with X " << x
        << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rd()%1000));
    std::cout<<"Z done\n";
    return "Z";
}

std::string doY(std::string x, std::string c) {
    std::random_device rd;
    std::cout<<"doing Y with X " << x
        << " with C " << c
        << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rd()%1000));
    std::cout<<"Y done\n";
    return "Y";
}