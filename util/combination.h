#pragma once
#include <vector>

class ModuloCombination {
    using ll = long long;
    ll mod, len;
    std::vector<ll> f, rf;

    ll inv(ll x);

public:
    ModuloCombination(long long mod_ = 1000000007);
    ll c(int n, int k);
    ll getMod() { return mod; }
};