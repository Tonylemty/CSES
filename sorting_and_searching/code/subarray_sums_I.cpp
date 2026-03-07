#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int ans = 0;
    int current_sum = 0;
    
    for (int r = 0; r < n; r++) {
        current_sum += arr[r];
        while (current_sum > x) {
            current_sum -= arr[l];
            l++;
        }
        if (current_sum == x) ans++;
    }
    cout << ans << '\n';

    return 0;
}
