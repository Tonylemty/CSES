#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<ll> dp(x + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
        }
    }
    cout << dp[x] << '\n';

    return 0;
}
