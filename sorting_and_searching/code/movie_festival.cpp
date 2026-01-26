#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> intervals;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }

    sort(intervals.begin(), intervals.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second < b.second;
    });

    int count = 1;
    ll end = intervals[0].second;
    for (int i = 1; i < n; i++) {
        if (intervals[i].first >= end) {
            count++;
            end = intervals[i].second;
        }
    }

    cout << count << '\n';
        
    return 0;
}
