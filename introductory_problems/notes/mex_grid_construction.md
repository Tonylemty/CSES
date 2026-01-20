### 題目意思
* 給定一個整數 `n`，要構造一個 `n × n` 的表格。
* 對於每一個位置 `(i, j)`（索引從 0 開始）：
  - 收集**同一列左邊**已出現的數字  
  → `(i, 0)` 到 `(i, j-1)`
  - 收集**同一行上方**已出現的數字  
  → `(0, j)` 到 `(i-1, j)`
* 將這兩部分的數字合併成一個集合，找出**沒有出現在此集合中的最小非負整數（mex）**

### 核心概念
* 從表格中可以觀察到：$a_{i, j} = i \oplus j$
* 每格要放「在同一列左邊出現過的數」∪「同一行上方出現過的數」裡沒有的最小非負整數

### 問題點
* 不知道 XOR 條件滿足 mex 的條件

### 官方解答
```cpp
// 直接構造矩陣
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<bool> seen(2 * n, false);
            for (int r = 0; r < i; r++) seen[grid[r][j]] = true;
            for (int c = 0; c < j; c++) seen[grid[i][c]] = true;

            int m = 0;
            while (m < (int)seen.size() && seen[m]) m++;
            grid[i][j] = m;
            cout << grid[i][j] << (j + 1 == n ? '\n' : ' ');
        }
    }    
    return 0;
}
```