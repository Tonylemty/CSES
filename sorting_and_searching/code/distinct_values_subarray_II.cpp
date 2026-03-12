#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];


    int l = 0;
    ll ans = 0;
    map<ll, int> mp;
    for (int r = 0; r < n; r++) {
        mp[v[r]]++;
        while (mp.size() > k) {
            mp[v[l]]--;
            if (mp[v[l]] == 0) mp.erase(v[l]);
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';

    return 0;
}
