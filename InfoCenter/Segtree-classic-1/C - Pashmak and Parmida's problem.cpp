#pragma GCC optimize("Ofast")
/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: C - Pashmak and Parmida's problem
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/C
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct BIT
{
    ll ferq = 0;
    vector<ll>tree;
    int N;
    BIT(int _n)
    {
        N = _n - 1;
        tree.resize(_n , 0);
    }
    void update(int pos, int val)
    {
        while(pos <= N)
        {
            tree[pos]+=val;
            pos += (pos &(-pos));
        }
    }
    ll query(int l , int r)
    {
        if(l != 1)
        {
            return query(1 , r) - query(1 , l - 1);
        }
        ll res = 0;
        while(r > 0)
        {
            res += tree[r];
            r -= (r & (-r));
        }
        return res;
    }
    void restart()
    {
        tree.assign(tree.size() , 0);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int , int> cnt;
    BIT t(n + 10);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
        t.update(cnt[a[i]] , 1);
    }
    unordered_map<int , int> um;
    ll ans = 0;
    for(int i = n - 1;i >= 0;i--) {
        t.update(cnt[a[i]] - um[a[i]] , -1);
        um[a[i]]++;
        ans += t.query(um[a[i]] + 1 , n);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
   // cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary

