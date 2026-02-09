#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    int n;
    cin >> x >> n;

    set<ll> pos;
    multiset<ll> len;

    pos.emplace(0);
    pos.emplace(x);
    len.emplace(x);

    while (n--) {
        ll p;
        cin >> p;

        auto it = pos.lower_bound(p);
        ll right = *it;
        ll left = *prev(it);

        len.erase(len.find(right - left));

        len.emplace(p - left);
        len.emplace(right - p);

        pos.insert(p);
        cout << *len.rbegin() << " ";
    }

    return 0;
}
