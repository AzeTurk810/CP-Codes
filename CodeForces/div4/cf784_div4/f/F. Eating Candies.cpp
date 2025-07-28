/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: F. Eating Candies
Contest: Codeforces Round 784 (Div. 4)
Judge: Codeforces
URL: https://codeforces.com/contest/1669/problem/F
Memory Limit: 256
Time Limit: 1000
Start: Tue 29 Jul 2025 01:51:58 AM +04
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0;i < n;i++) {
        cin >> w[i];
    }

    int l = 0, r = n - 1;
    int ans = 0 , suml = 0 , sumr = 0;
    while(l <= r) {
        if(suml < sumr) {
            suml += w[l];
            if (l == r) {
                break;
            }
            l ++;
        } else if(suml > sumr) {
            sumr += w[r];
            if(l == r)
                break;
            r--;
        } else {
            ans = n - r - 1 + l;
            suml += w[l];
            sumr += w[r];
            if(l == r - 1)
                break;
            l++;
            r--;
        }
    }
    cerr << l << ' ' << r << endl;
    if(suml == sumr && l <= r) {
        ans = n;
    }
    cout << ans << ln;
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

