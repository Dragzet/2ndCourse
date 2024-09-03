#include <iostream>

int main(){
    int inArr[4] = {3, 7, 2, 0};
    unsigned char bitmap = 0;

    for (auto i : inArr){
        bitmap = bitmap | (1 << i); //ставим соответствующий бит в 1
    }

    for (int i = 0; i < 8; i++){
        if (bitmap & (1 << i)){
            std::cout << i << " ";
        }
    }
}