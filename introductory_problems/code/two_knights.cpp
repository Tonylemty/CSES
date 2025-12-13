#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    while (cin >> n) {

        ll ans;
        for (ll i = 1; i <= n; i++) {
            ans = ((i*i) * ((i*i) - 1)) / 2 - (4 * (i - 1) * (i - 2));
            cout << ans << "\n";
        }

    }
    
    return 0;
}