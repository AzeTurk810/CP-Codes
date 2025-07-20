/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> min_l(n) , min_r(n);
    for(int i = 0;i < n;i++) {
        int l , r;
        cin >> l >> r;
        if(l > r)
            swap(l , r);
        min_l = {l , r , i};
        min_r = {r , l , i};
    }
    sort(min_l.begin() , min_l.end()); 
    sort(min_r.begin() , min_r.end());
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
