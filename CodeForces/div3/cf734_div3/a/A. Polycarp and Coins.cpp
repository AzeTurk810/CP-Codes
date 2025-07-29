/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: A. Polycarp and Coins
Contest: Codeforces Round 734 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/1551/problem/A
Memory Limit: 256
Time Limit: 1000
Start: Tue 29 Jul 2025 09:55:15 AM +04
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    int target = n / 3;
    cout << target + (n % 3 != 2 ? n % 3 : 0) << ' ' <<  target + (n % 3 == 2 ? 1 : 0) << ln;;
    
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

