#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    // 這題只與字母「數量」有關
    // 所以要計算每個字母出現次數
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'A']++;

    // 檢查是否有解
    int maxCnt = 0;
    for (int i = 0; i < 26; i++) {
        maxCnt = max(maxCnt, cnt[i]);
    }
    // 若任一個字母出現的次數超過字串長度的一半就不可行
    if (maxCnt > (n + 1) / 2) {
        cout << -1;
        return 0;
    }

    string ans;
    ans.reserve(n);

    // 貪心構造答案
    for (int pos = 0; pos < n; pos++) { // 遍歷字串的每個位置
        for (int c = 0; c < 26; c++) { // 嘗試將每個字母填入到 pos
            if (cnt[c] == 0) continue; // 未出現在字串或已用完
            if (!ans.empty() && ans.back() == char('A' + c)) continue; // 與前面字母一樣

            // 「假設」放這個字母
            cnt[c]--;

            int rest = n - pos - 1; // 剩下的字串長度
            int curMax = 0;
            for (int i = 0; i < 26; i++) {
                curMax = max(curMax, cnt[i]);
            }

            // 檢查剩下是否仍然可行
            if (curMax <= (rest + 1) / 2) {
                ans.push_back(char('A' + c));
                break;
            }

            // 不可行，還原
            cnt[c]++;
        }
    }

    cout << ans;
    return 0;
}
