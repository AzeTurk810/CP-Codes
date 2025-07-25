/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <set>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define K 32

void solve() {
    int n , k;
    cin >> n >> k;
    multiset<int> mst;
    int mn = 0;
    for(int i = 0;i < K;i++) {
        if((1 << i) & n) {
            mn++;
            mst.insert(i);
        }
    }
    if(mn > k || k > n) {
        cout << "NO" << ln;
        return;
    }
    k -= mn;
    while(k > 0) {
        k--;
        int cur = *mst.rbegin();
        mst.erase((--mst.end()));
        cur--;
        mst.insert(cur);
        mst.insert(cur);
    }
    cout << "YES" << ln;
    for(int i : mst) {
        cout << (1 << i)<< ' ';
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
