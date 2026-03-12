#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canSplit(vector<ll> &v, ll mid, ll k) {
    int seg = 1;
    ll current_sum = 0;
    
    for (ll x : v) {
        if (current_sum + x > mid) {
            seg++;
            current_sum = x;
        } else {
            current_sum += x;
        }
    }
    return seg <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll lo = *max_element(v.begin(), v.end());
    ll hi = accumulate(v.begin(), v.end(), 0LL);

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canSplit(v, mid, k)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << '\n';

    return 0;
}
