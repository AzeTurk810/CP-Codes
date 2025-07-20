/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

int cntl(int k , vector<int> &a) {
    return upper_bound(a.begin() , a.end() , k) - a.begin();
}

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<int> sorted_a(n);
    sorted_a = a;
    sort(sorted_a.begin() , sorted_a.end());
    vector<char> can(n , false);
    for(int i = 0;i < n;i++) {
        if(cntl(a[i] , sorted_a) >= k) {
            can[i] = true;
        }
    }
    int l = 0, r = n - 1;
    bool ok = true;
    int cnt = 0;
    while(r - l + 1 >= 1) {
        if(a[l] == a[r]) {
            l ++;
            r--;
            cnt ++ ;
        } else if(can[l]) {
            l++;
        } else if(can[r]) {
            r--;
        } else {
            ok = false;
            break;
        }
    }
    cout << (ok || cnt + cnt >= k ? "Yes\n" : "No\n");
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
