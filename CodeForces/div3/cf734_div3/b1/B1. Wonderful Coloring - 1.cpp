/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: B1. Wonderful Coloring - 1
Contest: Codeforces Round 734 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/1551/problem/B1
Memory Limit: 256
Time Limit: 1000
Start: Tue 29 Jul 2025 09:58:46 AM +04
*/
#include <iostream>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    set<char> a , b;
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    vector<int> cnt(26 , 0);
    for(int i = 0;i < n;i++) {
        cnt[s[i] - 'a']++;
    }
    int tr = 0;
    for(int j = 0;j < 26;j++) {
        if(cnt[j] >= 2) {
            ans++;
        } else if(cnt[j] == 1) {
            tr ++ ;
        }
    }
    cout << ans + (tr / 2) << ln;
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

