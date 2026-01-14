#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            for (char ch = 'A'; ch <= 'D'; ch++) {
                bool fail = false;
                if (grid[r][c] == ch) fail = true;
                if (c > 0 && grid[r][c - 1] == ch) fail = true;
                if (r > 0 && grid[r - 1][c] == ch) fail = true;
                if (!fail) {
                    grid[r][c] = ch;
                    break;
                }
            }
            cout << grid[r][c];
        }
        cout << '\n';
    }
    return 0;
}