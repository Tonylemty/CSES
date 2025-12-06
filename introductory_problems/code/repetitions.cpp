#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string seq;
    while (cin >> seq) {
        
        int current = 1;
        int max_len = 1;
        for (size_t i = 1; i < seq.size(); i++) {
            if (seq[i - 1] != seq[i]) {
                max_len = max(current, max_len);
                current = 1;
            } else {
                current++;
            }
        }
        max_len = max(current, max_len);
        cout << max_len << '\n';
    }


    return 0;
}