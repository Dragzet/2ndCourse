#include <iostream>
#include <string>
#include <unordered_map>

int linearSearch(const std::string& text, const std::string& pattern, int& counter) {
    int n = text.size();
    int m = pattern.size();

    if (m > n) return -1;

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            counter++;  
            j++;
        }
        counter++;  
        if (j == m) {
            return i;  
        }
    }
    return -1;  
}

std::unordered_map<char, int> buildShiftTable(const std::string& pattern) {
    std::unordered_map<char, int> table;
    int m = pattern.size();

    for (int i = 0; i < m - 1; ++i) {
        table[pattern[i]] = m - i - 1;
    }
    return table;
}

int boyerMooreHorspoolSearch(const std::string& text, const std::string& pattern, int& counter) {
    int n = text.size();
    int m = pattern.size();

    if (m > n) return -1;

    std::unordered_map<char, int> shiftTable = buildShiftTable(pattern);
    int i = 0; 
    int lastOccurrence = -1;

    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0) {
            counter++;  
            if (text[i + j] != pattern[j]) {
                break;  
            }
            j--;
        }

        if (j < 0) {
            lastOccurrence = i;  
            i++;  
        } else {
            i += shiftTable.count(text[i + m - 1]) ? shiftTable[text[i + m - 1]] : m;
        }
    }
    return lastOccurrence;
}

int main() {
    std::string text = "Тестовая строка";
    std::string pattern = "Артем";
    int counter = 0;

    int result = linearSearch(text, pattern, counter);
    std::cout << "Compares counter: " << counter << std::endl;
    if (result != -1) {
        std::cout << "First index: " << result << std::endl;
    } else {
        std::cout << "No subrow." << std::endl;
    }

    counter = 0;

    result = boyerMooreHorspoolSearch(text, pattern, counter);
    std::cout << "Compares counter: "<< counter << std::endl; 
    if (result != -1) {
        std::cout << "Last index: " << result << std::endl;
    } else {
        std::cout << "No subrow." << std::endl;
    }
    return 0;
}
