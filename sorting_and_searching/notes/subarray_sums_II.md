### 題目意思
* 找出有多少個連續子陣列的和等於 $x$
* 因為陣列中的值可能會出現**負數**或是**零**，所以不可以使用滑動窗口

### 核心概念
* 補數搜尋：
  不是在「找區間」，而是在「找過去的紀錄」
  * 定義前綴和：$prefix \_ sum[i] = a_1 + a_2 + ... + a_n$
  * 轉換公式：
    我們要找 $prefix \_ sum[current] - prefix \_ sum[past] = x$
    等同於找 $prefix \_ sum[past] = prefix \_ sum[current] - x$
  * Map 可以幫我們記住所有過去的 $prefix \_ sum$
* 注意：
  * 在開始迴圈前，必須先執行 `mp[0] = 1`。因為如果某個 `prefix_sum[j]` 剛好等於 $x$，你需要找的是 `prefix_sum[past] = 0`。這代表從頭開始到現在就是一個答案
  * `map` 通常比 `unordered_map` 好，因為可以避免被刻意設計的 hash collision 攻擊