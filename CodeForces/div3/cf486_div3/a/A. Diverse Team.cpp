/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: A. Diverse Team
Contest: Codeforces Round 486 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/988/problem/A
Memory Limit: 256
Time Limit: 1000
Start: Tue 29 Jul 2025 03:50:23 PM +04
*/
#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n , k;
    cin >> n >> k;
    set<int> st;
    vector<int> ind;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if(st.find(x) == st.end()) {
            ind.push_back(i);
        }
        st.insert(x);
    }
    if(st.size() >= k) {
        cout << "YES\n";
        for(int i = 0;i < k;i++) {
            cout << ind[i] + 1 << ' ';
        }
        cout << ln;
    } else {
        cout << "NO\n";
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

