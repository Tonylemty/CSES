### 題目意思

給定一個字串，輸出：
* 所有由這些字元組成的**不重複排列**
* 並且按照字典排序排列
* 先輸出總數，再輸出排列內容

### 核心概念
* Backtracking（回溯 + DFS）：為樹狀搜尋的一種
  * 每一個節點 = 已經選好的部分排列
  * 每一條邊 = 新加入的一個字元
  * 深度 = 已選字元數
  * 走到長度 n = 形成一個解
* Backtracking 的程式架構：
  * 終止條件
  * 做選擇
  * 往下遞迴（DFS）
  * 回溯
* C++ 中內建的函式：`next_permutation(first, last)`
  * 行為：將範圍 `[first, last)` 的字元排成下一個排列
  * 回傳值：
    * 如果「還有下一個字典排列」&rarr; 改成下一個排列，並回傳 `true`
    * 如果「已經是最後一個排列」&rarr; 把排列變回最小的排列，並回傳`false`

### 問題點
* 不清楚要使用什麼演算法
* 不知道 C++ 有 `next_permutation()` 這個內建函式

### 官方解答
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<string> v;
    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << v.size() << "\n";
    for (auto s : v) {
        cout << s << "\n";
    }
}
```