#pragma once
#include <vector>
#include "modint.h"

class ModuloCombination {
    using ll = long long;
    ll len;
    std::vector<mint> f, rf;

public:
    ModuloCombination(ll max_len = 10000010)
        : len(max_len + 1),
          f(std::vector<mint>(len)),
          rf(std::vector<mint>(len)) {
        f[0] = 1;
        for (int i = 0; i < len - 1; i++) f[i + 1] = f[i] * (i + 1);
        rf[len - 1] = f[len - 1].inv();
        for (int i = len - 2; i >= 0; i--) rf[i] = rf[i + 1] * (i + 1);
    }
    mint c(ll n, ll k) {
        if (n < 0 or k < 0 or n - k < 0) {
            std::cerr << "(n,k) = " << n << " " << k << std::endl;
            exit(0);
        }
        return f[n] * rf[n - k] * rf[k];
    }
};