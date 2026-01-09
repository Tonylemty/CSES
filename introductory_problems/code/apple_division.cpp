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

    // 1 << n 指的是把「1」放在第 n 個位置，且一定從十進位 1（如：00000001） 開始
    for (int i = 0; i < (1 << n); i++) {
        ll s = 0;
        // 檢查在「第 i 種選法」裡，是否挑選第 j 顆蘋果
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