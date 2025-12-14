#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {

        ll sum = ((1 + n) * n) / 2;

        if (sum % 2) {
            cout << "NO\n";
            continue;
        }
        
        vector<int> A, B;

        if (n % 4 == 0) { // 表示能用 4 個為一組
            for (int i = 1; i <= n; i += 4) {
                A.push_back(i);
                A.push_back(i + 3);
                B.push_back(i + 1);
                B.push_back(i + 2);
            }
        } else { // 先處理 3 個，剩下才能用 4 個一組
            A.push_back(1);
            A.push_back(2);
            B.push_back(3);
            for (int i = 4; i <= n; i += 4) {
                A.push_back(i);
                A.push_back(i + 3);
                B.push_back(i + 1);
                B.push_back(i + 2);
            }
        }

        cout << "YES\n";
        cout << A.size() << "\n";
        for (int &a : A) cout << a << " ";
        cout << "\n";
        cout << B.size() << "\n";
        for (int &b : B) cout << b << " ";
        cout << "\n";
    }
    
    return 0;
}