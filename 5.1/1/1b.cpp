#include <iostream>

int main(){
    unsigned char x = 10; //11111111
    unsigned char maska = 1; //00000001
    x = x | (maska << 6); // сдвиг до 7 бита
    std::cout << (int) x;
}