#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <bitset>
#include <iostream>
#include <sys/resource.h>
// #include <windows.h>
// #include <psapi.h>

using namespace std;

// void printMemoryUsage() {
//     PROCESS_MEMORY_COUNTERS_EX pmc;
//     HANDLE hProcess = GetCurrentProcess();
//     if (GetProcessMemoryInfo(hProcess, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
//         cout << "Memory usage: " << pmc.PrivateUsage / (1024 * 1024) << " MB" << endl;
//     } else {
//         cerr << "Failed to get memory usage." << endl;
//     }
// }



void printMemoryUsage() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        std::cout << "Использование памяти: " << usage.ru_maxrss / 1024 / (usage.ru_maxrss / 1024) << " МB" << std::endl;
    } else {
        std::cerr << "Ошибка при получении использования памяти" << std::endl;
        return;
    }
}

void makeTask(){
    const int bytes = 8;
    int arraySize = pow(10, 7) / bytes + 1;
    vector<unsigned char> bitmap(arraySize, 0); // битовый массив
    ifstream inputFile("input.txt");
    int number;
    while (inputFile >> number){
        bitmap[number / bytes] = bitmap[number / bytes] | (1ULL << number % bytes); // установка заданного бита в 1
    }
    inputFile.close();
    ofstream outputFile("output.txt");
    for (int i = 0; i < arraySize * bytes; i++){
        if (bitmap[i / bytes] & (1ULL << i % bytes)){
            outputFile << i << endl;
        }
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now(); //время начала
    makeTask();
    printMemoryUsage(); //вывод занятой оперативной памяти
    auto end = chrono::high_resolution_clock::now(); // время конца
    chrono::duration<double> timeGone = end - start;

    cout << "TIME - " << timeGone.count() << endl;
}