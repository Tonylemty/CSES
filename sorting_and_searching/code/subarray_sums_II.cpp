#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    

    ll current_sum = 0;
    ll ans = 0;
    map<ll, int> mp;
    
    mp[0] = 1;
    for (ll &n : v) {
        current_sum += n;
        if (mp.count(current_sum - x)) ans += mp[current_sum - x];
        mp[current_sum]++; 
    }
    cout << ans << '\n';

    return 0;
}
