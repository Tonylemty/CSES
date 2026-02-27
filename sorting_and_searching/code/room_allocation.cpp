#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Customers {
    ll l, r;
    int id;
} typedef cust;

bool cmp(const cust &a, const cust &b) {
    return a.l < b.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<cust> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].l >> customers[i].r;
        customers[i].id = i + 1;
    }
    sort(customers.begin(), customers.end(), cmp);

    int rooms = 0;
    vector<int> ans(n + 1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top().first < customers[i].l) {
            int current_room = pq.top().second;
            pq.pop();

            pq.push({customers[i].r, current_room});
            ans[customers[i].id] = current_room;
        } else {
            rooms++;
            pq.push({customers[i].r, rooms});
            ans[customers[i].id] = rooms;
        }
    }

    cout << rooms << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
    cout << '\n';
    return 0;
}
