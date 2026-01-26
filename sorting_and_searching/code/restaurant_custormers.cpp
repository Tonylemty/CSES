#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, int>> events(2 * n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    sort(events.begin(), events.end());

    int cur = 0; // 當下餐聽內人數
    int ans = 0; // 歷史最大人數
    for (auto &e : events) {
        cur += e.second;
        ans = max(ans, cur);
    }
    cout << ans;
        
    return 0;
}
