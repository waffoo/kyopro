#pragma once
#include <vector>

class ModuloCombination {
    using ll = long long;
    ll mod, len;
    std::vector<ll> f, rf;

    ll inv(ll x) {
        ll res = 1;
        ll k = mod - 2;
        ll y = x;
        while (k) {
            if (k & 1) res = (res * y) % mod;
            y = y * y % mod;
            k /= 2;
        }
        return res;
    }

public:
    ModuloCombination(ll mod_, ll max_len = 101010)
        : mod(mod_),
          len(max_len + 1),
          f(std::vector<ll>(len)),
          rf(std::vector<ll>(len)) {
        f[0] = 1;
        for (int i = 0; i < len - 1; i++) f[i + 1] = f[i] * (i + 1) % mod;
        for (int i = 0; i < len; i++) rf[i] = inv(f[i]);
    }
    ll c(int n, int k) {
        ll a = f[n];
        ll b = rf[n - k];
        ll c = rf[k];
        ll bc = (b * c) % mod;
        return (a * bc) % mod;
    }
    ll getMod() { return mod; }
};