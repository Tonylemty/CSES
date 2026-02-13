#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ordered_set circle;
    for (int i = 1; i <= n; i++) {
        circle.insert(i);
    }

    int p = 0;
    
    while (!circle.empty()) {
        
        p = (p + k) % circle.size(); 

        auto it = circle.find_by_order(p); 
        
        cout << *it << " ";
        
        circle.erase(it);
    }
    
    cout << '\n';
    return 0;
}
