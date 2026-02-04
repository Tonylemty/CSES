#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int num;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num] = i;
    }

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            rounds++;
        }
    }
    cout << rounds << '\n';
    return 0;
}
