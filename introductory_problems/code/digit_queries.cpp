#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digit(ll k) {
    k--;
    ll a = 1; // 區間起始值
    ll b = 9; // 區間結束值
    int c = 1;
    while (k >= (b - a + 1) * c) { // k 距離目標字元，還剩下要走的步數 (0-index)
        k -= (b - a + 1) * c; // 走完整個區間
        // 換到下一個區間
        a *= 10;
        b = b * 10 + 9;
        // 位數 + 1
        c++; 
    }
    // 因為 a 為該區間的起始值，k 表示剩餘步數
    // 每個數字佔 c 個字元，因此 k / c 代表跨過幾個數字
    // 目前所在的數字 = a + (k / c)
    ll x = a + (k / c);
    // // 每個數字長度為 c，字元索引 0~c-1 重複出現，用 k % c 取得
    return to_string(x)[k % c] - '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    ll k;

    cin >> q;
    while (q--) {
        cin >> k;
        cout << digit(k) << "\n";
    }
    return 0;
}
