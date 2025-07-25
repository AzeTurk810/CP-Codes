/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ff = "RGB";
    sort(ff.begin() , ff.end());
    int ans = n;
    string res;
    do {
        int  cur = 0;
        for(int i = 0;i < n;i+=3) {
            for(int j = 0;j < min(n - i , 3);j++) {
                if(ff[j] != s[i + j])
                    cur++;
            }
        }
        if(cur < ans) {
            ans = cur;
            res = ff;
        }
    } while (next_permutation(ff.begin() , ff.end())); 
    cout << ans << ln;
    for(int i = 0;i < n;i+=3) {
        for(int j = 0;j < min(n - i , 3);j++) {
            cout << res[j];
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
