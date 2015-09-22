// This program illustrates the use of decltype().
#include <vector>               // vector
#include <iostream>             // cout

int main() {
    std::vector<int> v(10);
    decltype(v.size()) num = 10;
    if (v.size() == num) std::cout << "yeah" << std::endl;
    return 0;
}
