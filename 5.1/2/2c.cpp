#include <iostream>

using namespace std;

int main(){
    int inArr[12] = {9, 8, 7, 6, 5, 4, 3, 2, 10, 43, 14, 17};
    unsigned char bitmap[8] = {0};

    for (auto i : inArr){
        bitmap[i / 8] = bitmap[i / 8] | (1 << i % 8);
    }

    for (int i = 0; i < 64; i++){
        if (bitmap[i / 8] & (1 << (i % 8))){
            std::cout << i << " ";
        }
    }
}