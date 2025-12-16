#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    int count = 0;
    for (ll i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    cout << count << "\n";

    return 0;
}