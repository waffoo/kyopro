#pragma once
#include <vector>

// rank of tree is stored in the parent of the root node
class UnionFind {
    int root(int x) {
        return parent.at(x) < 0 ? x : parent.at(x) = root(parent.at(x));
    }
    std::vector<int> parent;
    std::vector<int> sz;

public:
    UnionFind(int max) : parent(max + 1, -1), sz(max + 1, 1) {}
    void unite(int x, int y);
    int size(int x) { return sz.at(root(x)); }
    bool isFamily(int x, int y) { return root(x) == root(y); }
};