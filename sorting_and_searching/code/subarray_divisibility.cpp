#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];


    ll current_sum = 0;
    ll ans = 0;

    vector<ll> cnt(n, 0);
    cnt[0] = 1;
    
    for (ll x : v) {
        current_sum += x;

        ll remainder = (current_sum % n + n) % n;

        ans += cnt[remainder];

        cnt[remainder]++;
    }

    cout << ans << '\n';

    return 0;
}   
