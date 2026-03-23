#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;

    vector<ll> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<ll> pages(n);
    for(int i = 0; i < n; i++) cin >> pages[i];

    vector<ll> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    cout << dp[x] << '\n';

    return 0;
}
