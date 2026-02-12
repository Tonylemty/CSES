#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    list<int> circle;
    for (int i = 1; i <= n; i++) {
        circle.emplace_back(i);
    }

    auto it = circle.begin();
    while (!circle.empty()) {
        it++;
        if (it == circle.end()) it = circle.begin();

        cout << *it << " ";
        it = circle.erase(it);

        if (it == circle.end()) it = circle.begin();
    }
    cout << '\n';

    return 0;
}
