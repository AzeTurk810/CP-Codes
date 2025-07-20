/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
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
    int m , x;
    cin >> m >> x;
    vector<int> c(m);
    for(int j = 0;j < m;j++) {
        cin >> c[j];
    }
    int sum = 0;
    multiset<int> mst;
    int cur = x;
    for(int i = 1;i < m;i++) {
        if(sum + c[i] <= cur) {
            mst.insert(c[i]);
            sum += c[i];
            cur += x;
        } else {
            cur += x;
            if(mst.empty()) 
                continue;
            if(*mst.rbegin() <= c[i])
                continue;
            sum -= *mst.rbegin();
            mst.erase((--mst.end()));
            sum += c[i];
            mst.insert(c[i]);
        }
    }
    cout << mst.size() << ln;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary 
