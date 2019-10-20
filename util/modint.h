#pragma once

// need to define MOD
class mint {
    using ll = long long;
    ll num;

public:
    mint(ll x = 0) : num(x % MOD) {}
    mint operator+=(const mint& x) noexcept {
        this->num += x.num;
        if (this->num >= MOD) this->num %= MOD;
        return *this;
    }
    mint operator-=(const mint& x) noexcept {
        if (this->num < x.num) this->num += MOD;
        this->num -= x.num;
        return *this;
    }
    mint operator*=(const mint& x) noexcept {
        this->num = (this->num * x.num) % MOD;
        return *this;
    }
    mint operator/=(mint x) noexcept {
        ll exp = MOD - 2;
        while (exp) {
            if (exp % 2) *this *= x;
            x *= x;
            exp /= 2;
        }
        return *this;
    }
    mint operator%=(const mint& x) noexcept {
        this->num %= x.num;
        return *this;
    }
    mint operator+(const mint& x) const noexcept { return mint(*this) += x; }
    mint operator-(const mint& x) const noexcept { return mint(*this) -= x; }
    mint operator*(const mint& x) const noexcept { return mint(*this) *= x; }
    mint operator/(const mint& x) const noexcept { return mint(*this) /= x; }
    mint operator%(const mint& x) const noexcept { return mint(*this) %= x; }
    mint operator&(const mint& x) const noexcept { return this->num & x.num; }
    bool operator==(const mint& x) const noexcept { return this->num == x.num; }
    bool operator!=(const mint& x) const noexcept { return not((*this) == x); }
    explicit operator bool() const noexcept { return this->num != 0; }
    explicit operator int() const noexcept { return this->num; }

    friend ostream& operator<<(ostream&, const mint&);
};

ostream& operator<<(ostream& stream, const mint& x) { return stream << x.num; }

mint mpow(mint r, mint _n) {
    mint re = 1;
    int n = (int)_n;
    for (; n; n /= 2) {
        if (n & 1) re *= r;
        r *= r;
    }
    return re;
}