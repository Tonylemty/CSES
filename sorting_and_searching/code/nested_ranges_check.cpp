#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Range {
    int l, r, id;
};

bool cmp(const Range &a, const Range &b) {
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

    vector<Range> range(n);
    for (int i = 0; i < n; i++) {
        cin >> range[i].l >> range[i].r;
        range[i].id = i;
    }

    sort(range.begin(), range.end(), cmp);

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    int max_r = 0;
    for (int i = 0; i < n; i++) {
        if (range[i].r <= max_r) {
            contained[range[i].id] = 1;
        }
        max_r = max(max_r, range[i].r);
    }

    int min_r = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (range[i].r >= min_r) {
            contains[range[i].id] = 1;
        }
        min_r = min(min_r, range[i].r);
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
