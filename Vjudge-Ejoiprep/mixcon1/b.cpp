/*

Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
*/
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

void solve() {
    int n , m;
    cin >> n >> m;
    vector<int> a(n + m + 2) , b(n + m + 2);
    for(int i = 1;i <= n + m + 1;i++) {
        cin >> a[i];
    }
    for(int j = 1;j <= n + m + 1;j++) {
        cin >> b[j];
    }
    vector<int> prefix(n + m + 2) , prefix_a(n + m + 2) , prefix_b(n + m + 2);
    vector<pair<int, int>> pref(n + m + 2);
    prefix_a[0] = prefix_b[0] = prefix[0] = 0;
    pref[0] = {0 , 0};
    int qal_n = n , qal_m = m;
    for(int i = 1;i <= n + m + 1;i++) {
        prefix[i] = prefix[i - 1] + max(a[i] , b[i]);
        prefix_a[i] = prefix_a[i - 1] + a[i];
        prefix_b[i] = prefix_b[i - 1] + b[i];
        if(a[i] > b[i]) {
            pref[i] = {pref[i - 1].first + 1 , pref[i - 1].second};
        } else {
            pref[i] = {pref[i - 1].first , pref[i - 1].second + 1};
        }
    }
    int ans[n + m + 2];
    int sum = 0;
    for(int i = 1;i <= n + m + 1;i++) {
        int l = i + 1 , r = n + m + 1 , mid;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(pref[mid].first - pref[i].first <= qal_n && pref[mid].second - pref[i].second <= qal_m) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans[i] = sum;
        ans[i] += prefix[l - 1] - prefix[i];
        ans[i] += (
                pref[l - 1].first - pref[i].first < qal_n && qal_n != 0? 
                prefix_a[n + m + 1] - prefix_a[l - 1] : 
                prefix_b[n + m + 1] - prefix_b[l - 1]
                );
        if(qal_n == 0) {
            sum += b[i];
            qal_m--;
        } else if(qal_m == 0) {
            sum += a[i];
            qal_n--;
        } else if(a[i] > b[i]) {
            sum += a[i];
            qal_n--;
        } else {
            sum += b[i];
            qal_m--;
        }
    }
    for(int i = 1;i <= n + m + 1;i++) {
        cout << ans[i] << ' ';
    }
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
