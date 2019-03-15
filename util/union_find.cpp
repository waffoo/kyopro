#include "union_find.h"

void UnionFind::unite(int x, int y) {
    x = root(x), y = root(y);
    if (x != y) {
        if (parent.at(x) > parent.at(y)) std::swap(x, y);
        if (parent.at(x) == parent.at(y)) parent.at(x)--;
        sz[x] += sz[y];
        parent.at(y) = x;
    }
}