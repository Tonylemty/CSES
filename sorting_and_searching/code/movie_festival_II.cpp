#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        return a.second < b.second;
    });

    ll ans = 0;
    multiset<ll> mt;
    
    for (int i = 0; i < k; i++) mt.insert(0);

    for (auto [a, b] : v) {
        
        auto it = mt.upper_bound(a);
        if (it != mt.begin()) {
            --it;
            mt.erase(it);
            mt.insert(b);
            ans++;
        }
        
    }
    
    cout << ans << '\n';
    return 0;
}
