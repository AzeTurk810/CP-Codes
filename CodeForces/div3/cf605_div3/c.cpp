/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
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
#define int ll

void solve() {
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> keys;
    for(int i = 0;i < k;i++) {
        char temp;
        cin >> temp;
        keys.insert(temp);
    }
    vector<bool> flags(n , true);
    vector<int> rf(n , -1);
    for(int i = 0;i < n;i++) {
        if(keys.find(s[i]) == keys.end()) {
            flags[i] = false;
            rf[i] = i;
        }  else if(i) {
            rf[i] = rf[i - 1];
        }
    }
    vector<int> nums;
    int cnt = 0;
    for(int i = 0;i < n;i++) {
        cnt += flags[i];
        if(!flags[i] && cnt > 0) {
            nums.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt) {
        nums.push_back(cnt);
    }
    ll ans = 0;
    for(int &i : nums) {
        ans += ((i) * (i + 1)) >> 1LL;
    }
    cout << ans << ln;
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
