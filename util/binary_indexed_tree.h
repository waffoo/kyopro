#pragma once
#include <vector>

class BIT {
    // ATTENTION: this tree is one-indexed
    std::vector<int> tree;
    int MAX_SIZE;

public:
    BIT(int max) : tree(max), MAX_SIZE(max) {}
    void add(int idx, int val) {
        for (int x = idx; x < MAX_SIZE; x += x & -x) tree[x] += val;
    }
    int sum(int idx) {
        int ret = 0;
        for (int x = idx; x > 0; x -= x & -x) ret += tree[x];
        return ret;
    }
};