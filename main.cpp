#include <iostream>

#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>

template<typename T>
struct ClassNameHelper {
    T name;
};

int main() {
    struct ClassNameHelper<std::string> test;
    test.name = "etst";
    std::cout << test.name;
    std::cout << std::endl;
    std::cout << typeid(std::string).name();
    return 0;
}
