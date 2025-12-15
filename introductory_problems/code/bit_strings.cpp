#include <bits/stdc++.h>
using namespace std;
using ll = long long
const int M = 1000000007;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll ans = 1;
    ll base = 2;

    // 快速冪 (binary exponentiation)
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * base % M;
        }
        base = base * base % M;
        n /= 2;
    }
    cout << ans << "\n";
    
    return 0;
}