/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n; 
    cin >> n;
    vector<int> p(n);
    for(int i = 0;i < n;i++) {
        cin >> p[i];
    }
    int l = 0 , r = n - 1;
    vector<int> ans;
    int last = 0;
    bool boyuyur = false;
    string res;
    while(l <= r) {
        if(boyuyur) {
            if(p[l] <= last) {
                ans.push_back(p[l]);
                res.push_back('L');
                last = p[l];
                boyuyur = false;
                l++;
                continue;
            }
            if(p[r] < last) {
                ans.push_back(p[r]);
                res.push_back('R');
                last = p[r];
                boyuyur = false;
                r--;
                continue;
            }
            int mn = max(p[l] , p[r]);
            if(mn == p[l]) {
                ans.push_back(p[l]);
                res.push_back('L');
                last = p[l];
                l++;
                continue;
            }
            ans.push_back(p[r]);
            res.push_back('R');
            last = p[r];
            r--;
            continue;
        } else {
            if(p[l] > last) {
                ans.push_back(p[l]);
                res.push_back('L');
                last = p[l];
                boyuyur = true;
                l++;
                continue;
            }
            if(p[r] > last) {
                ans.push_back(p[r]);
                res.push_back('R');
                last = p[r];
                boyuyur =  true;
                r--;
                continue;
            }
            int mn = min(p[l] , p[r]);
            if(mn == p[l]) {
                ans.push_back(p[l]);
                res.push_back('L');
                last = p[l];
                l++;
                continue;
            }
            ans.push_back(p[r]);
            res.push_back('R');
            last = p[r];
            r--;
            continue;
        }
    }
    assert(ans.size() == n);
    cout << res ;
    cout << ln;
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
