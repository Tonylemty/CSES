#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n;

    ll mx = LLONG_MIN;
    ll sum = 0;
    vector<ll> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
        mx = max(mx, times[i]);
        sum += times[i];
    }

    if (mx > (sum - mx)) {
        cout << 2 * mx << '\n';
    } else {
        cout << sum << '\n';
    }

    return 0;
}   
