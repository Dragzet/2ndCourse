#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct LZ78Pair {
    int index;
    wchar_t symbol;
};

vector<LZ78Pair> LZ78Encode(const wstring &input) {
    unordered_map<wstring, int> dictionary; 
    vector<LZ78Pair> encodedData;           
    wstring currentSequence = L"";          
    int dictSize = 0;                       

    for (wchar_t c : input) {
        currentSequence += c;

        if (dictionary.find(currentSequence) == dictionary.end()) {
            int index = (currentSequence.size() == 1) ? 0 : dictionary[currentSequence.substr(0, currentSequence.size() - 1)];
            encodedData.push_back({index, c});
            
            dictionary[currentSequence] = ++dictSize;
            
            currentSequence = L"";
        }
    }
    if (!currentSequence.empty()) {
        int index = dictionary[currentSequence.substr(0, currentSequence.size() - 1)];
        encodedData.push_back({index, currentSequence.back()});
    }

    return encodedData;
}

// Функция для вывода результата кодирования
void PrintEncodedData(const vector<LZ78Pair> &data) {
    for (const auto &pair : data) {
        wcout << L"(" << pair.index << L", " << pair.symbol << L")" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");

    wstring input = L"кукуркукурекурекун";
    wcout << L"Исходная строка: " << input << endl;

    vector<LZ78Pair> encodedData = LZ78Encode(input);

    wcout << L"Результат кодирования (LZ78):" << endl;
    PrintEncodedData(encodedData);

    return 0;
}
