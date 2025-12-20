#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves;
void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        moves.emplace_back(a, c);
    } else {
        hanoi(n - 1, a, c, b);
        hanoi(1, a, b, c);
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << moves.size() << "\n";
    for (auto &m : moves) {
        cout << m.first << " " << m.second << "\n";
    }

    return 0;
}