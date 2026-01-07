#include <bits/stdc++.h>
using namespace std;

// 進行 backtracking
void dfs(string& s, string& cur, vector<bool>& used, vector<string>& ans) {
    if (cur.size() == s.size()) {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (used[i] == true) {
            continue;
        }

        // 避免同一層重複使用相同字元，防止重複排列
        // 每一層都表示一次遞迴
        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) {
            continue;
        }

        // 做選擇
        used[i] = true;
        cur.push_back(s[i]);

        // 往下遞迴
        dfs(s, cur, used, ans);

        // 做回溯的動作，恢復到原先的狀態
        cur.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    sort(str.begin(), str.end()); // 先排序
    vector<bool> used(str.length(), false);
    vector<string> ans;
    string cur;
    dfs(str, cur, used, ans);
    
    cout << ans.size() << '\n';
    for (auto &str : ans) {
        cout << str << '\n';
    }

    return 0;
}