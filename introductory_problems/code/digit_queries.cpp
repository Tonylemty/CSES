#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digit(ll k) {
    k--;
    ll a = 1;
    ll b = 9;
    int c = 1;
    while (k >= (b - a + 1) * c) {
        k -= (b - a + 1) * c;
        a *= 10;
        b = b * 10 + 9;
        c++;
    }
    ll x = a + (k / c);
    return to_string(x)[k % c] - '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    ll k;

    cin >> q;
    while (q--) {
        cin >> k;
        cout << digit(k) << "\n";
    }
    return 0;
}
