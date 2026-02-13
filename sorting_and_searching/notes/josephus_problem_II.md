### 題目意思
* 有 `n` 個人圍成一圈（編號 1 到 n）
* 每次固定跳過 `k` 個人，然後將下一個人淘汰出局
* 紀錄並輸出所有人的淘汰順序

### 核心概念
* 使用 C++ 內建的 PBDS 中的順序統計樹（Order Static Tree）來模擬（CPE 不會出）
  * 引入方式：
  ```c++
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>

  using namespace __gnu_pbds;
  typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
  ```
  * 會使用到當中的 `find_by_order(p)` 和 `erase()` 函式
    * `find_by_order(p)`：給我剩下的人裡面的第 $p$ 個
    * `erase(it)`：把那個人刪掉
  * 要刪掉哪個位置的人的公式：`p = (p + k) % circle.size();`（0-based）
    * `p`：現在位置
    * `k`：跳過的步數
    * `circle.size()`：剩下人數
* 程式主要流程：
  1. 算位置
  2. 找人
  3. 輸出：印出編號
  4. 淘汰
* 原版喬瑟夫問題的位置更新公式（重點）：
  ```c++
  // 所有人的編號必須從 0 開始
  int get_survivor(int n, int k) {
    int ans = 0; // 當只有 1 個人時 (i=1)，倖存者的索引是 0
    
    // 從 2 個人開始，一路推導到 n 個人
    // i 表示的是當下圈圈中共有幾個人，一路推到題目要求的第 n 人
    for (int i = 2; i <= n; i++) {
        ans = (ans + k) % i;
    }
    
    // 如果題目要的是 1 到 n 的編號，記得 +1
    return ans + 1; 
  }
  ```