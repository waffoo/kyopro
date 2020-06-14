#pragma once

#include <map>
using namespace std;

template <typename K>
class PriorityMap {
    map<K, int> data;

public:
    void insert(K k) { data[k]++; }
    void erase(K k) {
        if (data[k] == 0) exit(0);
        if (data[k] > 1)
            data[k]--;
        else
            data.erase(k);
    }
    int count(K k) { return data[k]; }

    K max() {
        if (data.size() == 0) exit(0);
        return rbegin(data)->first;
    }
    K min() {
        if (data.size() == 0) exit(0);
        return begin(data)->first;
    }
    bool empty() { return data.size() == 0; }

    void display() {
        for (auto e : data)
            cout << "key = " << e.first << " : value = " << e.second << endl;
    }
};