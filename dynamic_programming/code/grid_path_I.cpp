#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            ll top = (i > 0) ? dp[i - 1][j] : 0;
            ll left = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = (top + left) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << '\n';

    return 0;
}
