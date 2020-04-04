#pragma once

#include <map>
#include <vector>
using namespace std;

vector<int> divisor(int n) {
    vector<int> v;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.pb(i);
            if (i * i < n) v.pb(n / i);
        }
    }
    return v;
}

map<int, int> prime_factor(int n) {
    map<int, int> mp;
    while (true) {
        bool found = false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                mp[i]++;
                found = true;
                n /= i;
                break;
            }
        }
        if (not found) {
            mp[n]++;
            break;
        }
    }
    return mp;
}