### 核心觀念
* 找出 1 到 n 中沒有出現的數

### 官方解法

1. 使用布林陣列來判斷是否有出現過
```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> seen(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int x;
        cin >> x;
        seen[x] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            cout << i << "\n";
        }
    }
}
```

2. 利用「總和公式」（$\frac{n(n + 1)}{2}$）求出所缺少的數
```c++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    for (int i = 1; i <= n - 1; i++) {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << "\n";
}
```