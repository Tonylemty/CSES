#include <bits/stdc++.h>
using namespace std;

string s;
int ans = 0;
bool visited[7][7] = {false};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

void dfs(int step, int x, int y) {

    if (x < 0 || x >= 7 || y < 0 || y >= 7) return;
    if (visited[x][y]) return;
    if (x == 6 && y == 0 && step < 48) return;
    if (step == 48) {
        if (x == 6 && y == 0) ans++;
        return;
    }

    bool up = (x-1 < 0 || visited[x-1][y]);
    bool down = (x+1 >= 7 || visited[x+1][y]);
    bool left = (y-1 < 0 || visited[x][y-1]);
    bool right = (y+1 >= 7 || visited[x][y+1]);

    if (up && down && !left && !right) return;
    if (!up && !down && left && right) return;

    visited[x][y] = true;
    
    if (s[step] == '?') {
        for (int i = 0; i < 4; i++) {
            dfs(step + 1, x + dx[i], y + dy[i]);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            if (dir[i] == s[step]) {
                dfs(step + 1, x + dx[i], y + dy[i]);
            }
        }
    }
    visited[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}
