/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: $(PROBLEM)
Contest: $(CONTEST)
Judge: $(JUDGE)
URL: $(URL)
Memory Limit: $(MEMLIM)
Time Limit: $(TIMELIM)
Start: $(DATE)
*/
#include <cstdio>
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    const int N = 1e4;
    freopen("E. Lomsat gelral_output3.txt" , "w" , stdout);
    ll sum = 0;
    for(int i = N;i >= 1;i--) {
        sum += i;
    }
    for(int i = 1;i <= N;i++) {
        cout << sum << ' ';
        sum -= i;
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
