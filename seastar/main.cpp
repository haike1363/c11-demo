#include <iostream>
#include <seastar/core/future.hh>
using namespace seastar;

int main() {
    auto p = promise<uint32_t>();
    p.set_value(10);
    std::cout<< p.get_future().get0();
    return 0;
}
