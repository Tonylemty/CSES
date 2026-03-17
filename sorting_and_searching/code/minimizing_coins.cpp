#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int &y : c) cin >> y;
    sort(c.begin(), c.end());


    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n && i - c[j] >= 0; j++) {
            dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    if (dp[x] == 1e9) cout << -1 << '\n';
    else cout << dp[x] << '\n';
    return 0;
}
