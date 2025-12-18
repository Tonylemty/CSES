#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<int> count(26, 0);
    cin >> line;

    int odd = 0;
    for (char &x : line) count[x - 'A']++;
    for (int n : count) {
        if (n % 2 == 0) continue;
        odd++;
    }

    string left = "";
    string middle = "";
    string right = "";
    if (odd <= 1) {
        for (int i = 0; i < 26; i++) {
            int n = count[i];
            char ch = i + 'A';
            if (n % 2 == 0 && n != 0) {
                int c = n / 2;
                while (c--) {
                    left.push_back(ch);
                }
            } else if (n % 2 == 1) {
                int c = (n - 1) / 2;
                middle = ch;
                while (c--) {
                    left.push_back(ch);
                }
            }
        }
        right = left;
        reverse(right.begin(), right.end());
        cout << left + middle + right << "\n";
    } else {
        cout << "NO SOLUTION\n";
    }
    

    return 0;
}