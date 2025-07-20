/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> cnt;
    for(char &c : s) {
//        c = (c == '(' ? ')' : '(');
    }
    int sum = 0;
    cnt[0]++;
    ll ans = 0;
    int mx = 0;
    int l = 0;
    for(char &c : s) {
        sum += (c == ')' ? -1 : 1);
        ans += cnt[sum];
        cnt[sum]++;
        while(l + l > sum)
            l--;
        l--;
        while(l + l < sum) {
            cnt[l] = 0;
            l ++;
        }
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
