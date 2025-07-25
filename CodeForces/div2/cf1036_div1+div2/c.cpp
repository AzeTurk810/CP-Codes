/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

ll lcm(ll a, ll b) {
    return a * b / __gcd(a , b);
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i];
    }
    ll g = 1;
    reverse(a.begin() , a.end());
    for(int i = 0;i  < n -1;i++) {
            g = lcm(g , lcm(a[i] , a[i + 1]) / a[i]);
    }
    if(g == 0) g = 1;
    cout << g << ln;
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
