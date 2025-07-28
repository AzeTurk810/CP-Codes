/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: H. Maximal AND
Contest: Codeforces Round 784 (Div. 4)
Judge: Codeforces
URL: https://codeforces.com/contest/1669/problem/H
Memory Limit: 256
Time Limit: 2000
Start: Tue 29 Jul 2025 02:11:48 AM +04
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define K 31

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<int> cnt(K , 0);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < K;j++) {
            if(a[i] & (1 << j)) {
                cnt[j]++;
            }
        }
    }
    ll ans = 0;
    for(int j = K - 1;j >= 0;j--) {
        if(n - cnt[j] <= k) {
            ans |= (1 << j);
            k -= n - cnt[j];
        }
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

