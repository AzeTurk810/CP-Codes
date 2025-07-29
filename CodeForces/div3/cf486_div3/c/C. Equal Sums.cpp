/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: C. Equal Sums
Contest: Codeforces Round 486 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/988/problem/C
Memory Limit: 256
Time Limit: 2000
Start: Tue 29 Jul 2025 04:01:49 PM +04
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int k;
    cin >> k;
    vector<vector<int>> a(k);
    int n[k] , sun[k];;
    map<int , pair<int,int>> cnt;
    pair<int , int> ii , jj = {-1 , -1};
    for(int i = 0;i < k;i++) {
        cin >> n[i];
        int sum = 0;
        a[i].resize(n[i]);
        for(int j = 0;j < n[i];j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        for(int j = 0;j < n[i];j++) {
            if(cnt.find(sum - a[i][j]) != cnt.end()) {
                ii = cnt[sum - a[i][j]], jj = {i + 1 , j + 1};
                goto _output;
            }
        }
        for(int j = 0;j < n[i];j++) {
            cnt[sum - a[i][j]] = {i + 1 , j + 1};
        }
        sort(a[i].begin() , a[i].end());
        sun[i] = sum;
    }
_output:
    if(jj.first != -1) {
        cout << "YES\n";
        cout << ii.first << ' ' << ii.second << ln;
        cout << jj.first << ' ' << jj.second << ln;
    } else {
        cout << "NO\n";
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

