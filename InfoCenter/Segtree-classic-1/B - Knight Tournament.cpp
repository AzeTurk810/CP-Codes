/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: B - Knight Tournament
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/B
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n , m;
    cin >> n >> m;
    set<int> st;
    for(int i = 1;i <= n;i++) {
        st.insert(i);
    }
    vector<int> ans(n + 1 , 0);
    while (m--) {
        int l , r , x;
        cin >> l >> r >> x;
        auto it = st.lower_bound(l);
        while (it != st.end()) {
            if(*it > r)
                break;
            if(*it == x) {
                it++;
                continue;
            }
            auto cur = it++;
            ans[*cur] = x;
            st.erase(cur);
        }
    }
    for(int i = 1;i <= n;i++) {
        cout << ans[i] << ' ';
    }
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary


