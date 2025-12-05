#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    while (cin >> n) {

        ll num;
        set<ll> set;
        for (int i = 0; i < n - 1; i++) {
            cin >> num;
            set.insert(num);
        }
        
        for (ll i = 1; i <= n; i++) {
            if (!set.count(i)) cout << i << '\n';
        }

    }


    return 0;
}