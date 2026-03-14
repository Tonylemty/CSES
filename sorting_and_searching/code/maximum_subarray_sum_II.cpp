#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    // 1. 先建好 1-indexed 的前綴和陣列 p
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }

    ll ans = LLONG_MIN;
    deque<int> dq; // 裡面只要存 index 就好，要比大小時直接查 p[index]

    // 2. 從長度剛好滿 a 的地方開始找答案
    for (int i = a; i <= n; i++) {
        // 準備要加入視窗的新鮮候選人 (剛好滿足最小距離 a)
        int new_idx = i - a; 
        
        // 維護單調隊列：把後面那些「數字比我大，又比我早過期」的廢物踢掉
        while (!dq.empty() && p[dq.back()] >= p[new_idx]) {
            dq.pop_back();
        }
        dq.push_back(new_idx);

        // 踢掉已經超出最大距離 b，太舊的過期品
        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }

        // 用目前的 p[i] 減去視窗內的最小值，就是以 i 結尾的最大子陣列和
        ans = max(ans, p[i] - p[dq.front()]);
    }
    
    cout << ans << '\n';

    return 0;
}
