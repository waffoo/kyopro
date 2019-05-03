#pragma once
#include <functional>
#include <iostream>
#include <vector>

class SegTree {
    using ll = long long;
    // 0-indexed tree

    ll size;  // num of data
    std::vector<ll> tree;
    std::function<ll(ll, ll)> op;
    ll err_val;

    ll parent(ll x) { return (x - 1) / 2; }
    ll left(ll x) { return 2 * x + 1; }
    ll right(ll x) { return 2 * x + 2; }
    ll index(ll pos) { return this->size + pos - 1; }

    ll _query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a or b <= l) return this->err_val;
        if (a <= l and r <= b) return this->tree[k];

        int vl = this->_query(a, b, this->left(k), l, (l + r) / 2);
        int vr = this->_query(a, b, this->right(k), (l + r) / 2, r);
        return this->op(vl, vr);
    }

public:
    SegTree(ll x,
            std::function<ll(ll, ll)> op = [](ll a, ll b) -> ll {
                return a + b;
            },
            ll initial = 0)
        : op(op), err_val(initial) {
        ll sz = 1LL;
        while (sz < x) sz <<= 1;
        this->size = sz;
        this->tree = std::vector<ll>(sz * 2 - 1, initial);
    }

    void print() {
        ll next_row = 1;
        ll now_left_idx = 0;

        while (now_left_idx < 2 * this->size - 1) {
            for (ll i = 0; i < next_row; i++)
                std::cout << this->tree[now_left_idx + i] << " ";
            std::cout << std::endl;
            now_left_idx += next_row;
            next_row <<= 1;
        }
    }

    void update(ll pos, ll val) {
        ll index = this->index(pos);
        this->tree[index] = val;

        while (index > 0) {
            index = this->parent(index);
            this->tree[index] = this->op(this->tree[this->left(index)],
                                         this->tree[this->right(index)]);
        }
    }

    ll query(ll a, ll b) { return this->_query(a, b, 0, 0, this->size); }
};