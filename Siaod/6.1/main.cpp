#include <iostream>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

struct Subscription {
    int id;
    string name;
    string address;
    
    Subscription(int id, string name, string address)
    : id(id), name(name), address(address) {}
};

class HashTable{
private:
    vector<list<Subscription>> table;
    int capacity;
    int len;
    const float A = (sqrt(5) - 1) / 2;


    int hashFunction(int key){
        float fractional_part = (key * A) - int(key * A);
        return int(capacity * fractional_part);
    }

    void rehash(){
        int oldCapacity = capacity;
        capacity *= 2;
        vector<list<Subscription>> newTable(capacity);

         for (int i = 0; i < oldCapacity; i++) {
            for (auto& sub : table[i]) {
                int newIndex = hashFunction(sub.id);
                newTable[newIndex].push_back(sub);
            }
        }
        table = move(newTable);
    }

public:
    HashTable(int size) : capacity(size), len(0) {
        table.resize(size);
    }

    void insert(const Subscription& sub){
        if (len > capacity * 0.75){
            rehash();
        }

        int index = hashFunction(sub.id);
        table[index].push_back(sub);
        len++;
    }

    Subscription* search(int key){
        int index = hashFunction(key);
        for (auto& sub : table[index]) {
            if (sub.id == key) {
                return &sub;
            }
        }
        return nullptr;
    }

     void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->id == key) {
                table[index].erase(it);
                len--;
                cout << "Subscription with ID " << key << " removed." << endl;
                return;
            }
        }
        cout << "Subscription with ID " << key << " not found." << endl;
    }

     void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            for (auto& sub : table[i]) {
                cout << "[ID: " << sub.id << ", Name: " << sub.name << ", Address: " << sub.address << "] -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashTable hashTable(7); 

    hashTable.insert(Subscription(10001, "John Doe", "123 Elm St"));
    hashTable.insert(Subscription(10002, "Jane Smith", "456 Oak St"));
    hashTable.insert(Subscription(10003, "Alice Johnson", "789 Pine St"));
    hashTable.insert(Subscription(10004, "Bob Brown", "101 Maple St"));
    hashTable.insert(Subscription(10005, "Eve White", "202 Birch St"));

    cout << "Initial hash table state:\n";
    hashTable.display();

    int searchId = 10003;
    Subscription* sub = hashTable.search(searchId);
    if (sub) {
        cout << "\nFound subscription with ID " << searchId << ": " << sub->name << ", " << sub->address << endl;
    } else {
        cout << "\nSubscription with ID " << searchId << " not found." << endl;
    }

    hashTable.remove(10002);

    cout << "\nHash table state after removal:\n";
    hashTable.display();

    return 0;
}