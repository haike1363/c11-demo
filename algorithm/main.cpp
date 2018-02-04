#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values = {1, 3, 5};
    for(int i = 0;i <= 6; ++i) {
        auto it = std::lower_bound(values.begin(), values.end(), i);
        if (it != values.end()) {
            std::cout<<"lower_bound:" << i <<" "<< *it <<std::endl;
        }else {
            std::cout<<"lower_bound:" << i <<" "<< " end"<<std::endl;
        }

        auto it2 = std::upper_bound(values.begin(), values.end(), i);
        if (it2 != values.end()) {
            std::cout<<"upper_bound:" << i <<" "<< *it2 <<std::endl;
        }else {
            std::cout<<"upper_bound:" << i <<" "<< " end"<<std::endl;
        }
    }

    return 0;
}