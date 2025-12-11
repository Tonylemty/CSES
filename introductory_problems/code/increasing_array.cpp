#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {


    int size;
    while (cin >> size) {

        vector<ll> arr(size);
        for (auto &a : arr) {
            cin >> a;
        }

        
        ll moves = 0;
        ll current_max = arr[0]; // 到目前為止的最大值 -> 從左至右建立的最低要求
        for (int i = 1; i < size; i++) {
            if (arr[i] < current_max) {
                moves += current_max - arr[i];
            } else {
                current_max = arr[i];
            }
        }
        cout << moves << "\n";
    }

    return 0;
}