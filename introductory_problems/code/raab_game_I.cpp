#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n || (a == 0 && b > 0) || (a > 0 && b == 0)) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        int k = n - a - b;
        
        if (a == 0 && b == 0) {
            for (int i = 1; i <= k; i++) cout << i << " ";
            cout << "\n";
            for (int i = 1; i <= k; i++) cout << i << " ";
            cout << "\n";
            continue;
        }

        vector<int> A, B;

        // 平手段
        for (int i = 1; i <= k; i++) {
            A.push_back(i);
            B.push_back(i);
        }

        // B 贏段
        for (int i = k + 1; i <= k + b; i++) {
            A.push_back(i);
        }
        
        for (int i = k + a + 1; i <= n; i++) {
            B.push_back(i);
        }

        // A 贏段
        for (int i = k + b + 1; i <= n; i++) {
            A.push_back(i);
        }

        for (int i = k + 1; i <= k + a; i++) {
            B.push_back(i);
        }

        for (int a : A) cout << a << " ";
        cout << "\n";
        for (int b : B) cout << b << " ";
        cout << "\n";
    }
    
    return 0;
}