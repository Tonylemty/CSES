#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int l = 0;
    int ans = 0;
    map<ll, int> last;
    for (int r = 0; r < n; r++) {
        ll k;
        cin >> k;
        if (last.count(k)) {
            l = max(l, last[k] + 1);
        }
        last[k] = r;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
