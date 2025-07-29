/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: D. Points and Powers of Two
Contest: Codeforces Round 486 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/988/problem/D
Memory Limit: 256
Time Limit: 4000
Start: Tue 29 Jul 2025 05:10:39 PM +04
*/
#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define K 31
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0;i < n;i++) {
        cin >> x[i];
    }
    sort(x.begin() , x.end());
    vector<int> res = {-1};
    for(int i = 0;i < n;i++ ) {
        for(int j = 0;j < K;j++) {
            int l = x[i] - (1 << j);
            int r = x[i] + (1 << j);
            bool isl = (*lower_bound(x.begin() , x.end() , l) == l);
            auto it = lower_bound(x.begin() , x.end() , r);
            bool isr = false;
            if(it != x.end())  {
                if(*it == r) {
                    isr = true;
                }
            }
            if(isl && isr) {
                res = {l , r , x[i]};
                goto _output;
            } 
            if(isl) {
                res = {l , x[i]};
            } 
            if(isr) {
                res = {x[i] , r};
            } 
            if (res[0] == -1){
                res = {x[i]};
            }
        }
    }
_output:
    cout << res.size() << '\n';
    for(int i = 0;i < res.size();i++) {
        cout << res[i] << ' ';
    }
    cout << ln;
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

