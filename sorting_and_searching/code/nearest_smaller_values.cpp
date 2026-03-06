#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    stack<int> pos;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        while (!pos.empty() && arr[pos.top()] >= arr[i]) {
            pos.pop();
        }

        if (!pos.empty()) {
            cout << pos.top() << " ";
        } else {
            cout << 0 << " ";
        }
        pos.push(i);
    }

    return 0;
}   
