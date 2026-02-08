#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cubes(n);
    for (ll &c : cubes) {
        cin >> c;
    }

    vector<ll> towers;
    for (ll &c : cubes) {
        auto it = upper_bound(towers.begin(), towers.end(), c);
        if (it == towers.end()) towers.push_back(c);
        else *it = c;
    }

    cout << towers.size() << '\n';

    return 0;
}
