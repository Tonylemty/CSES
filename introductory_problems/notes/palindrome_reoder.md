### 題目意思
* 給定一個只包含字母 A-Z 且長度為 `n` 的字串
* 求此字串是否可組成**回文**

### 核心概念
* 回文特性：
  * 左右必須成對 &rarr; 出現次數必須是**偶數**
  * 整個字串中，出現奇數次的字元最多只有**一個**

### 問題點
* 有想到回文特性，但是不知道該怎麼由原字串組成回文字串

### 官方解答
```c++
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> count;
    for (auto c : s) {
        count[c]++;
    }

    int odds = 0;
    char center;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (count[c] % 2 == 1) {
            odds++;
            center = c;
        }
    }

    if (odds > 1) {
        cout << "NO SOLUTION\n";
    } else {
        for (char c = 'A'; c <= 'Z'; c++) { // 印左邊
            cout << string(count[c] / 2, c);
        }
        if (odds) {
            cout << center;
        }
        for (char c = 'Z'; c >= 'A'; c--) { // 印右邊
            cout << string(count[c] / 2, c);
        }
        cout << "\n";
    }
}
``` 