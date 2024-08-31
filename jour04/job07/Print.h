#include <iostream>
using namespace std;

void print() {
    std::cout << std::endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    cout << first;
    
    if (sizeof...(args) > 0) {
        cout << ", ";
    }
    
    print(args...);
}