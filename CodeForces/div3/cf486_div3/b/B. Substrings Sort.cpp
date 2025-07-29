/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: B. Substrings Sort
Contest: Codeforces Round 486 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/988/problem/B
Memory Limit: 256
Time Limit: 1000
Start: Tue 29 Jul 2025 03:54:05 PM +04
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

bool is(string &a , string &b) {
    for(int  i = a.size();i <= b.size();i++) {
        if(a == b.substr(i - a.size(), a.size())) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int , string>> a(n);
    for(auto &i : a) {
        cin >> i.second;
        i.first = i.second.size();
    }
    sort(a.begin() , a.end());
    for(int i = 1;i < n;i++) {
        if(!is(a[i - 1].second , a[i].second)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0;i < n;i++) {
        cout << a[i].second << ln;
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

