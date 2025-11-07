#include <iostream>

bool isLittleEndian() {
    unsigned int x = 1;
    char* c = reinterpret_cast<char*>(&x);
    return (*c == 1); // if lowest byte is 1 → little endian
}

int main() {
    if (isLittleEndian())
        std::cout << "System is Little Endian\n";
    else
        std::cout << "System is Big Endian\n";
}