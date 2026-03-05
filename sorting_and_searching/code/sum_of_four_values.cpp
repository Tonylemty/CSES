#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());

    for (int k = 0; k < n; k++) {
        for (int m = k + 1; m < n; m++) {
            int tar = x - (v[k].first + v[m].first);
            int i = m + 1; int j = n - 1;
            while (i < j) {
                int v1 = v[i].first; int v2 = v[j].first;
                if (v1 + v2 < tar) {
                    i++;
                } else if (v1 + v2 > tar) {
                    j--;
                } else {
                    vector<int> ans = {v[k].second, v[m].second, v[i].second, v[j].second};
                    sort(ans.begin(), ans.end());
                    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
                    return 0;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";


    return 0;
}   
