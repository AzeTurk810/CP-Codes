/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: Exam
Contest: QOJ
Judge: Virtual Judge
URL: https://vjudge.net/problem/QOJ-6983
Memory Limit: 512
Time Limit: 1000
Start: Sun 03 Aug 2025 12:15:50 PM +04
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
    vector<int> a(n) , b(n);;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int j = 0;j < n;j++) {
        cin >> b[j];
    }
    int ans = 0;
    for(int mask = 0;mask < (1 << (n + 2)); i ++) {
        if(__builtin_popcount(mask) & 1)
            continue;
        vector<int> cur = a;
        for(int i = 0;i < n;i++) {
        }
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

