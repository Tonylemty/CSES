#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {

        vector<int> odd;
        vector<int> even;

        if (n == 1) cout << 1 << "\n";
        else if (n == 2 || n == 3) cout << "NO SOLUTION" << "\n";
        else {
            for (int i = 2; i <= n; i += 2) cout << i << " ";
            for (int i = 1; i <= n; i += 2) cout << i << " ";
        }
    }

    return 0;
}