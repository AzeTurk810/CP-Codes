/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct problem {
    int t , n;
    vector<int> a , cnt;
    void input() {
        cin >> t >> n;
        a.resize(n);
        for(int i = 0;i < n;i++) {
            cin >> a[i];
        }
        for(int i = 0;i < n;i++) {
            a.push_back(a[i]);
        }
    }

    void init() {
        cnt.assign(t , 0);
    }

    pair<int, int> solve()  {
        int l = 0 , r = -1;
        int mn = INFi;
        pair<int, int> ans;
        while(r + 1 < 2 * n) {
            r++;
            cnt[a[r]]++;
            while(cnt[a[r]] > 1) {
                ;
                cnt[a[l]]--;
                l++;
            }
            int cl , cr;
            cl = l - 1;
            cr = r - n + 1;
            if(r + 1 == n) {
                cr = (r + 1) % n;
            }
            if(cl > cr)
                swap(cl , cr);
            if((cr - cl + 1) < mn && l / n != (r + 1) / n) {
                ans = {(cr), (cl)};
                mn = cr - cl + 1;
            }
        }
        return  ans;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    problem pr;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        pr.input();
        assert(pr.a.size() == pr.n * 2);
        pr.init();
        auto ans = pr.solve();
        if(ans.first > ans.second)
            swap(ans.first , ans.second);
        cout << ans.first << ' ' << ans.second << ln;
    }
}
// Just Imaginary
