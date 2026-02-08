#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> gray;
    // 先建立最基本的 1-bit 格雷碼
    gray.push_back("0");
    gray.push_back("1");


    for (int i = 2; i <= n; i++) { // 每一圈把 i - 1 位元的 gray code 變為 i 位元
        vector<string> temp = gray;
        reverse(temp.begin(), temp.end()); // 反轉

        for (string &s : gray) { // 在原格雷碼前面加 0
            s = "0" + s;
        }

        for (string s : temp) {
            gray.push_back("1" + s); // 對反轉後的格雷碼前面加一，可以確保相鄰只差一位元
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