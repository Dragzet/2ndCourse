#include <fstream>
#include <string>
//include <windows.h>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <format>
#include <string.h>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

struct card {
    int StudNumber;
    char group[20];
    char name[50];

    card(int StudNumber, const char* group_in, const char* name_in)
        : StudNumber(StudNumber) {
        strncpy(group, group_in, sizeof(group));
        strncpy(name, name_in, sizeof(name));
    }

    card() = default;

    string toString() {
        return format("StudNumber = {:8}\tGroup: {:10}\tFIO:  {:50}", StudNumber, group, name);
    }
};

struct cardSearch {
    int key;
    int pos;
};

vector<int> generateRandomNumbers(int size, int from, int to) {
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<> distrib(from, to);
    set<int> unset;
    vector<int> result;
    while (unset.size() < size)
        unset.insert(distrib(g)); // Создаем множество случайных чисел

    while (result.size() < size)
        result.push_back(unset.extract(unset.begin()).value()); // Копируем из множества в вектор

    shuffle(result.begin(), result.end(), g); // Перемешиваем

    return result;
}

card generateData(card* cardArray, int cardsCounter)
{
    string groups[5] = { "IKBO-10-23", "IKBO-11-23", "IKBO-12-23", "IKBO-13-23", "IKBO-14-23" };
    string names[5] = { "Kharitonov Arseniy", "Antonov Nikolai", "Moiseev Artur", "Gribov Ivan", "Radoms Anton" };
    card tempCard;
    vector<int> randoms = generateRandomNumbers(cardsCounter, 100'000'000, 900'000'000);
    for (int i = 0; i < cardsCounter; i++) {
        tempCard = card(randoms[i], groups[generateRandomNumbers(1, 100'000'000, 900'000'000)[0] % 5].c_str(), names[generateRandomNumbers(1, 100'000'000, 900'000'000)[0] % 5].c_str());
        cardArray[i] = tempCard;
    }
    return tempCard;
}

card linearSearch(fstream& fs, int cardCounter, int StudNumber)
{
    fs.seekg(0);
    card tempCard;
    for (int i = 0; i < cardCounter; i++) {
        fs.read((char*)&tempCard, sizeof(card));
        if (tempCard.StudNumber == StudNumber) return tempCard;
    }
    return card(-1, "NONE", "NONE");
}

void tableSort(cardSearch* table, int cardCounter)
{
    for (int i = 0; i < cardCounter - 1; i++)
    {
        int ind = i;
        for (int j = i + 1; j < cardCounter; j++)
        {
            if (table[j].key < table[ind].key) ind = j;
        }
        cardSearch tempCard = table[i];
        table[i] = table[ind];
        table[ind] = tempCard;
    }
}

card* getCard(fstream& fs, int counter)
{
    fs.seekg(0);
    card* cardArray = new card[counter];
    card tempCard;
    for (int i = 0; i < counter; i++)
    {
        fs.read((char*)&tempCard, sizeof(card));
        cardArray[i] = tempCard;
    }
    return cardArray;
}

cardSearch* createTable(fstream& fs, int cardCounter, card* cardArray)
{
    fs.seekg(0);
    cardSearch* table = new cardSearch[cardCounter];
    card tempCard;
    for (int i = 0; i < cardCounter; i++) {
        fs.read((char*)&tempCard, sizeof(card));
        cardArray[i] = tempCard;
        table[i].key = tempCard.StudNumber;
        table[i].pos = i;
    }
    tableSort(table, cardCounter);
    return table;
}

cardSearch modifiedBinarySearch(cardSearch* table, int needKey, int position, int delta, int cardCounter)
{
    if (delta == 0) return cardSearch(-1, -1);
    if (table[position].key == needKey) return table[position];
    if (position != 0) if (table[position - 1].key == needKey) return table[position - 1];
    if (position != cardCounter - 1) if (table[position + 1].key == needKey) return table[position + 1];
    delta /= 2;
    if (table[position].key > needKey)
        return modifiedBinarySearch(table, needKey, position - delta, delta, cardCounter);
    else
        return modifiedBinarySearch(table, needKey, position + delta, delta, cardCounter);
}

int main() {
    //SetConsoleOutputCP(1251);
    const char* fname = "file.txt";

    fstream fs(fname, ios::out | ios::binary);
    fs.close();


    int cardsCounter = 100000;
    card* cardArray = new card[cardsCounter];


    //First ex
    card lastCard = generateData(cardArray, cardsCounter);
    fs.open(fname, ios::in | ios::out | ios::binary);
    for (int i = 0; i < cardsCounter; i++)
    {
        fs.write((char*)&cardArray[i], sizeof(card));
    }
    cout << "Last card: " << lastCard.toString() << endl;
    cout << string(120, '=') << endl;

    //Second ex
    int key = 0;
    cin >> key;
    auto start = chrono::steady_clock::now();
    card foundCard = linearSearch(fs, cardsCounter, key);
    chrono::duration<double> time = (chrono::steady_clock::now() - start);

    cout << "Found card: " + foundCard.toString() << endl;
    cout << format("In {:} seconds.\n", time.count());
    cout << string(120, '=') << endl;
    
    //Third ex
    cardSearch* table = NULL;
    start = chrono::steady_clock::now();
    card* newCardArray = new card[cardsCounter];
    table = createTable(fs, cardsCounter, newCardArray);
    time = (chrono::steady_clock::now() - start);
    cout << format("Table created in {:} seconds.\nCurrent size is {:} lines.\n", time.count(), cardsCounter);
    cout << string(120, '=') << endl;
    start = chrono::steady_clock::now();
    cardSearch result = modifiedBinarySearch(table, key, cardsCounter / 2, cardsCounter / 2, cardsCounter);
    card resultCard = newCardArray[result.pos];
    time = (chrono::steady_clock::now() - start);
    cout << "Found card: " + resultCard.toString() << endl;
    cout << format("In {:} seconds.\n", time.count());
    fs.close();
}
