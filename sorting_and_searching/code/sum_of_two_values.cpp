#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
        vec[i].second = i + 1;
    }
    sort(vec.begin(), vec.end());

    int i = 0, j = vec.size() - 1;
    while (i < j) {
        int target = vec[i].first + vec[j].first;
        if (target == x) {
            cout << min(vec[i].second, vec[j].second) << " "
                 << max(vec[i].second, vec[j].second);
            return 0;
        } else if (target < x) {
            i++;
        } else {
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
