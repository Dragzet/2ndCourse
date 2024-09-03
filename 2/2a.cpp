#include <iostream>

int main(){
    int inArr[4] = {3, 7, 2, 1};

    
    unsigned char bitmap = 0;
    for (auto i : inArr){
        bitmap = bitmap | (1 << (i - 1));
    }


    for (int i = 0; i < 7; i++){
        if (bitmap & (1 << i)){
            std::cout << i + 1<< " ";
        }
    }


}