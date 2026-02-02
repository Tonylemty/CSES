#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    ll med;
    if (n % 2) {
        med = sticks[n / 2];
    } else {
        med = sticks[(n - 1) / 2];
    }
    
    ll sum = 0;
    for (ll &s : sticks) {
        sum += llabs(s - med);
    }

    cout << sum << '\n';

    return 0;
}
