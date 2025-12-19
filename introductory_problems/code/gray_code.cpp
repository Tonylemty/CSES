#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");


    for (int i = 2; i <= n; i++) {
        vector<string> temp = gray;
        reverse(temp.begin(), temp.end());

        for (string &s : gray) {
            s = "0" + s;
        }

        for (string s : temp) {
            gray.push_back("1" + s);
        }
    }

    if (n == 1) {
        cout << "0\n1\n";
        return 0;
    }
    
    for (string s : gray) {
        cout << s << "\n";
    }
    
    return 0;
}