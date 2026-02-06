### 題目意思
* 給定一串長度 `n` 的歌曲 id：`k1, k2, ..., kn`
* 要找一段連續的區間（不能跳著選）
* 這段區間內的每個 id 都不能重複
* 輸出這段區間的最大長度

### 核心概念
* 滑動窗口（Two pointer / Sliding Window）
  * 維持一個目前「不重複」的連續區間 `[left, ..., right]`
  * 用 `last[id]` 紀錄每個 id 最後一次出現的位置
  * 當右端 `right` 讀取到 `x`：
    * 如果 `x` 之前出現過的位置 `last[x]` 在目前的視窗內
      &rarr; 把 `left` 直接跳到 `last[x] + 1`
    * 更新 `last[x] = right`
    * 更新答案：`ans = max(ans, right - left + 1)`
