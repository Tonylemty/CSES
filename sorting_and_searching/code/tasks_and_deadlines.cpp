#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll deadline = 0;
    vector<ll> durations;
    for (int i = 0; i < n; i++) {
        ll a, d;
        cin >> a >> d;
        deadline += d;
        durations.push_back(a);
    }
    sort(durations.begin(), durations.end());

    ll s = 0;
    ll finish = 0;
    for (int i = 0; i < n; i++) {
        s += durations[i];
        finish += s;
    }

    cout << (deadline - finish) << '\n';

    return 0;
}   
