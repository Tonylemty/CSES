#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
    int l, r, id;
};

bool cmp(Range &a, Range &b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r > b.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
    }
    sort(ranges.begin(), ranges.end(), cmp);

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);
    ordered_set<pair<int, int>> pbds;

    for (int i = 0; i < n; i++) {
        contained[ranges[i].id] = pbds.size() - pbds.order_of_key({ranges[i].r, -1});
        pbds.insert({ranges[i].r, ranges[i].id});
    }
    pbds.clear();
    
    for (int i = n - 1; i >= 0; i--) {
        contains[ranges[i].id] = pbds.order_of_key({ranges[i].r, 1e9});
        pbds.insert({ranges[i].r, ranges[i].id});
    }

    for (int &c : contains) {
        cout << c << " ";
    }
    cout << '\n';
    for (int &c : contained) {
        cout << c << " ";
    }
    cout << '\n';

    return 0;
}
