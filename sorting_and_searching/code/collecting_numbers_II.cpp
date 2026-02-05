#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    vector<int> pos(n + 2, 0);
    pos[n + 1] = n + 1; // 邊界處理

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) ans++;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int u = arr[a], v = arr[b];

        // 使用 set 收集受影響的數值對，避免重複計算（如 u, v 是連續數字時）
        set<pair<int, int>> affected;
        if (u > 1) affected.insert({u - 1, u});
        if (u < n) affected.insert({u, u + 1});
        if (v > 1) affected.insert({v - 1, v});
        if (v < n) affected.insert({v, v + 1});

        // 移除舊貢獻
        for (auto p : affected) {
            if (pos[p.first] > pos[p.second]) ans--;
        }

        // 交換
        swap(arr[a], arr[b]);
        pos[u] = b;
        pos[v] = a;

        // 加入新貢獻
        for (auto p : affected) {
            if (pos[p.first] > pos[p.second]) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}