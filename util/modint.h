#pragma once

// need to define MOD
class mint {
    using ll = long long;
    ll num = 0;

public:
    mint(ll x) : num(x) {}
    const mint& operator+=(const mint& x) noexcept {
        this->num += x.num;
        if (this->num >= MOD) this->num %= MOD;
        return *this;
    }
    const mint& operator-=(const mint& x) noexcept {
        if (this->num < x.num) this->num += MOD;
        this->num -= x.num;
        return *this;
    }
    const mint& operator*=(const mint& x) noexcept {
        this->num = (this->num * x.num) % MOD;
        return *this;
    }
    const mint& operator/=(mint x) noexcept {
        ll exp = MOD - 2;
        while (exp) {
            if (exp % 2) *this *= x;
            x *= x;
            exp /= 2;
        }
        return *this;
    }
    const mint& operator+(const mint& x) const noexcept {
        return mint(*this) += x;
    }
    const mint& operator-(const mint& x) const noexcept {
        return mint(*this) -= x;
    }
    const mint& operator*(const mint& x) const noexcept {
        return mint(*this) *= x;
    }
    const mint& operator/(const mint& x) const noexcept {
        return mint(*this) /= x;
    }

    friend ostream& operator<<(ostream&, const mint&);
};

ostream& operator<<(ostream& stream, const mint& x) { return stream << x.num; }