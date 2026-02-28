#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n >> t;

    vector<ll> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    ll L = 1;
    ll min_time = *min_element(times.begin(), times.end());
    ll R = min_time * t;

    ll ans = R;
    while (L <= R) {
        ll mid = L + (R - L) / 2;

        ll products = 0;
        for (int i = 0; i < n; i++) {
            products += (mid / times[i]);

            if (products >= t) break;
        }

        if (products >= t) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}   
