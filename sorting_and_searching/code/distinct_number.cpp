#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    vector<ll> val(size);
    for (ll& v : val) {
        cin >> v;
    }
    sort(val.begin(), val.end());

    ll last = 0;
    int count = 0;
    for (ll& v : val) {
        if (v != last) count++;
        last = v;
    }

    cout << count << '\n';

    return 0;
}