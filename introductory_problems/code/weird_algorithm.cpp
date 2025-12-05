#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    long long n; 
    while (cin >> n) {

        vector<long long> seq;
        while (n != 1) {
            seq.push_back(n);
            if (n % 2) {
                n = (3 * n) + 1;
            } else {
                n /= 2;
            }
        }
        seq.push_back(1);

        for (size_t i = 0; i < seq.size(); i++) { // seq.size() 回傳的是 size_t(無符號)
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << '\n';
    }
    

    return 0;
}
