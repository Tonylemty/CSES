#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll sum = 0;
    vector<ll> p(n);
    for (ll& x : p) {
        cin >> x;
        sum += x;
    }

    ll ans = LLONG_MAX;

    for (int i = 0; i < (1 << n); i++) {
        ll s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s += p[j];
            }
        }

        ll diff = llabs(sum - 2 * s);
        ans = min(diff, ans);
    }

    cout << ans << '\n';

    return 0;
}