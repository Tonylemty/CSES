#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> coins(n);
    for (ll &c : coins) {
        cin >> c;
    }
    sort(coins.begin(), coins.end());

    ll reach = 0;
    for (ll &c : coins) {
        if (c > reach + 1) {
            break;
        } else {
            reach += c;
        }
    }
    cout << reach + 1 << '\n';
    
    return 0;
}
