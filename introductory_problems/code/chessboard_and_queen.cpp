#include <bits/stdc++.h>
using namespace std;

vector<string> board(8);
bool colUsed[8] = {false};
bool diag1Used[15] = {false}; // 共有 15 條對角線
bool diag2Used[15] = {false};
long long ans = 0;

void dfs(int r) {

    if (r == 8) { // 已經放完 8 個皇后
        ans++;
        return;
    }

    for (int c = 0; c < 8; c++) {

        if (board[r][c] == '*') continue;

        int d1 = r + c; // 主對角線
        int d2 = r - c + 7; // 副對角線
        if (colUsed[c] || diag1Used[d1] || diag2Used[d2]) continue;

        // 放入
        colUsed[c] = diag1Used[d1] = diag2Used[d2] = true;
        dfs(r + 1);
        // 不放入
        colUsed[c] = diag1Used[d1] = diag2Used[d2] = false;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 8; i++) cin >> board[i];

    dfs(0);
    cout << ans << '\n';

    return 0;
}