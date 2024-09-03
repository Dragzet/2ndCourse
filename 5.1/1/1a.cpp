#include <iostream>

int main(){
    unsigned char x = 255;
    unsigned char maska = 1;
    x = x & (~ (maska << 4));
    std::cout << (int) x;
}