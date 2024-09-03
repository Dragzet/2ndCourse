#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>

using namespace std;

int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    unsigned int x = 255;
    const int n = sizeof(int) * 8;
    unsigned maska = (1 << n - 1);
    cout << "Начальный вид маски " <<bitset<n>(maska) << endl;
    cout << "Результат: ";
    for (int i = 1; i <= n; i++){
        cout << ((x & maska) >> (n - i)); // до тех пор, пока наша 1000...0000 не дойдет до `1111111`, строка будет выдавать 0, ведь 1 & 0 = 0
        maska = maska >> 1; // сдвигаем единицу
    }
    cout << endl;
    system("pause");
    return 0;
}