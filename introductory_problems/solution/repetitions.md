### 核心觀念
找最長連續相同字元 = 找最長連續區段
* 只需要從左掃到右
* 比較 `s[i]` 和 `s[i - 1]` 是否相同
  * 若一樣就累積「目前連續長度」
  * 若不一樣就更新「最大值」和重置「目前連續長度」

### 官方解法
```C++
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cur = 1; // 目前字串的連續長度
    int res = 1; // 目前最大長度
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) cur = 0; // 重置
        cur++;
        res = max(res, cur); // 更新最大值
    }
    cout << res << "\n";
}
```