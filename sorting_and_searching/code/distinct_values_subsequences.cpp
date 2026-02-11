#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    long long ans = 1;
    long long MOD = 1e9 + 7;
    for (auto const& [val, count] : freq) {
        ans = (ans * (count + 1)) % MOD;
    }

    // 減 1 是因為要扣除空子序列
    cout << (ans - 1 + MOD) % MOD << endl;
    return 0;

    return 0;
}
