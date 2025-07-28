/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: E1. Submedians (Easy Version)
Contest: Codeforces Round 1039 (Div. 2)
Judge: Codeforces
URL: https://codeforces.com/contest/2128/problem/E1
Memory Limit: 512
Time Limit: 3000
Start: Mon 28 Jul 2025 08:53:54 PM +04
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

vector<int> a , pref;
int n , k;

bool f(int mid, int &l , int &r) {
    pref[0] = 0;
    for(int i = 1;i <= n;i++) {
        pref[i] = pref[i - 1] + (a[i] >= mid ? 1 : -1);
    }
    int mn = INFi , lidx = 0;
    for(int i = k ;i <= n;i++) {
        if(mn > pref[i - k]) {
            mn = pref[i - k];
            lidx = i - k + 1;
        }
        if(pref[i] - mn >= 0) {
            l = lidx , r = i;
            return true;
        }
    }
    return false;
}


void solve() {
    cin >> n >> k;
    a.resize(n + 1);
    pref.resize(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    int l = 1 , r = n , mid;
    int ans = 1 , ans_l = -1 , ans_r = -1;
    while (l <= r) {
        mid = (l  + r) >> 1;
        if(f(mid , ans_l , ans_r)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << ' ' << ans_l << ' '<< ans_r << '\n';
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

