#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll bestEnd = arr[0];
    ll sum = arr[0];
    for (int i = 1; i < n; i++) {
        bestEnd = max(bestEnd + arr[i], arr[i]);
        sum = max(sum, bestEnd);
    }
    
    cout << sum << '\n';

    return 0;
}
