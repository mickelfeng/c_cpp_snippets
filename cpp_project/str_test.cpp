#include <iostream>
#include <string>

class sss;

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string str ("Sairamkrishna Mammahe");
    // for (int i=0; i<str.length(); ++i) {
    for (char i : str) {
        std::cout << i;
    }
    std::cout << std::endl;


    return 0;
}
