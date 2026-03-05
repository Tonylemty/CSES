#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        ll tar = x - arr[i].first;
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            ll sum = arr[l].first + arr[r].first;
            if (sum < tar) {
                l++;
            } else if (sum > tar) {
                r--;
            } else {
                vector<int> ans = {arr[i].second, arr[l].second, arr[r].second};
                sort(ans.begin(), ans.end());
                cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";

    return 0;
}   
