#include <iostream>
using namespace std;

int countSequences(int n) {
    int dp[n + 1];

    dp[1] = 2; // Последовательности: 0, 1
    if (n > 1) {
        dp[2] = 3; // Последовательности: 00, 01, 10
    }

    // Далее все зависит от выбора 0 или 1, таким образом получаем формулу
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Введите длину последовательности n: ";
    cin >> n;

    cout << "Количество последовательностей длины " << n 
         << ", в которых нет двух подряд идущих единиц: " 
         << countSequences(n) << endl;

    return 0;
}
