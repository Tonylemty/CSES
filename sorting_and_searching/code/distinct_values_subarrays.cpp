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

    int l = 0;
    ll ans = 0;
    map<ll, ll> cnt;
    for (int r = 0; r < n; r++) {
        cnt[arr[r]]++;
        while (cnt[arr[r]] > 1) {
            cnt[arr[l]]--;
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';

    return 0;
}
