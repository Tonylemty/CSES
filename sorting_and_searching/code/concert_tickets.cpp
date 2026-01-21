#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int t;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        cin >> t;
        tickets.insert(t);
    }
    
    int c;
    for (int i = 0; i < m; i++) {
        cin >> c;
        auto it = tickets.upper_bound(c);
        if (it == tickets.begin()) cout << -1 << '\n';
        else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }

    return 0;
}
