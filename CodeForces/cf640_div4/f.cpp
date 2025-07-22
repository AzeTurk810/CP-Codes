/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n[3];
    for(int i = 0;i < 3;i++) {
        cin >> n[i];
    }
    string ans;
    for(int i = 0;i < n[1] + 1;i ++) {
        if(i & 1) 
            ans.push_back('0');
        else
            ans.push_back('1');
    }
    if(n[1] == 0 && n[0] != 0) 
        ans = "0";
    else if(n[1] == 0)
        ans = "1";
    for(int i = 0;i < n[2];i++) {
        ans = '1' + ans;
    }
    for(int i = 0;i < n[0];i++) {
        ans.push_back('0');
    }
    cout << ans << ln;
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
