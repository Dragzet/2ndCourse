#include <iostream>

int main(){
    int inArr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    
    const int n = sizeof(long long);
    unsigned bitmap = (1 << n - 1);

    for (auto i : inArr){
        bitmap =  bitmap & (~(1 << (i - 1)));
    }


    std::cout << (long long)bitmap << std::endl;

    for (int i = 0; i < 64; i++){
        if ((long long)bitmap & (1 << i)){
            std::cout << i + 1<< " ";
        }
    }


}