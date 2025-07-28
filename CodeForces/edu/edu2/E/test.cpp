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
    freopen("E. Lomsat gelral_input4.txt", "w" , stdout);
    const int N = 1e3;
    cout << N << ln;
    for(int i = 1;i <= N;i++) {
        cout << i << ' ';
    }
    for(int i = 1;i <= N - 1;i ++) {
        cout << i << ' ' << i + 1 << ln;
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
