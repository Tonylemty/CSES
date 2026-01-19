#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicant(n);
    vector<int> apartment(m);
    for (int& x : applicant) {
        cin >> x;
    }

    for (int& x : apartment) {
        cin >> x;
    }
    sort(applicant.begin(), applicant.end());
    sort(apartment.begin(), apartment.end());

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (apartment[j] < applicant[i] - k) {
            j++;
        }

        if (apartment[j] > applicant[i] + k) {
            i++;
        }

        if (apartment[j] >= applicant[i] - k && apartment[j] <= applicant[i] + k) {
            i++;
            j++;
            ans++;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
