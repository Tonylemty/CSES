#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long y, x;
    cin >> t;
    while (cin >> y >> x) {
        
        long long ans;
        long long n = max(y, x);
        if (n % 2) {
            if (x == n) ans = n * n - (y - 1);
            else ans = (n - 1) * (n - 1) + x;
        }

        if (!(n % 2)) {
            if (y == n) ans = n * n - (x - 1);
            else ans = (n - 1) * (n - 1) + y;
        }

        cout << ans << "\n";
    }
    

    return 0;
}