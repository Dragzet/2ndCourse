#include <iostream>

int main(){
    int inArr[12] = {9, 8, 7, 6, 5, 4, 0, 2, 10, 43, 14, 63};
    unsigned long long bitmap = 0;

    for (auto i : inArr){
        bitmap =  bitmap | (1ULL << i); // устанавливаем бит в 1
    }

    for (int i = 0; i < 64; i++){
        if ((long long)bitmap & (1ULL << i)){
            std::cout << i << " ";
        }
    }
}