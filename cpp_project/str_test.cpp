#include <iostream>
#include <string>

void str_construct();

int main() {
    str_construct();
    return 0;
}

void str_construct() {
    std::string str ("Sairamkrishna Mammahe");
    // for (int i=0; i<str.length(); ++i) {
    for (char i : str) {
        std::cout << i;
    }
    std::cout << std::endl;
    std::cout << std::hex << 0x31; // print as hex
}
