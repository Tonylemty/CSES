#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> children(n);
    for (int &child : children) {
        cin >> child;
    }
    sort(children.begin(), children.end());

    int i = 0;
    int j = n - 1;
    int gondola = 0;
    while (i <= j) {
        if (children[i] + children[j] <= x) {
            i++;
            j--;
        } else if (children[i] + children[j] > x) {
            j--;
        }
        gondola++;
    }
    
    cout << gondola << '\n';
    return 0;
}
