### 題目意思
* 給定一個二元數字串長度 `n`
* 求在長度 `n` 的情況下，可組成幾種二元數字串

### 核心概念
* 大次方的情況下，不可使用 `pow()`，且需要邊算邊**取模**
  * 因為 `pow()` 是浮點數 &rarr; 會有精度問題
* 進階觀念：**快速冪**
  * 時間複雜度：$O(\log n)$
  * 若 `n` 是偶數 &rarr; $2^n = (2^{n/2})^2$
  * 若 `n` 是奇數 &rarr; $2^n = 2 \times 2^{n - 1}$

### 問題點
* 不知道在大次方情況下不使用 `pow`，且需要邊算邊取模
* 不知道快速冪的觀念

### 官方解
```c++
#include <iostream>
#include <vector>
using namespace std;
const int M = 1000000007;

int main() {
    int n;
    cin >> n;

    int ans = 1;
    // 因為 n <= 1e6，所以才可用線性方式
    for (int i = 1; i <= n; i++) {
        ans = ans * 2 % M;
    }
    cout << ans << "\n";
}
```