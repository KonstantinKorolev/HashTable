// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cstring>
#include <list>
#include <iostream>
#include <random>
using namespace std;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; 

    public:
        bool isEmpty() const;
        int hashfunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashfunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashfunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "{WARNING} Key exist" << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashfunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "{INFO} item removed" << endl;
            break;
        }
    }

    if (!keyExists) {
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

int main()
{
    HashTable HT;

    if (HT.isEmpty()) {
        cout << "Correct answer. Good job." << endl;
    }
    else {
        cout << "Oh oh. We need to check our code!" << endl;
    }
    
    HT.insertItem(905, "Morrison");
    HT.insertItem(902, "Ford");
    HT.insertItem(903, "Smith");
    HT.insertItem(954, "Moore");
    HT.insertItem(955, "Taylor");
    HT.insertItem(956, "Anderson");
    HT.insertItem(957, "Cooper");

    HT.printTable();

    if (HT.isEmpty()) {
        cout << "Oh oh. We need to check our code!" << endl;
    }
    else {
        cout << "Correct answer. Good job." << endl;
    }

    return 0;
}
