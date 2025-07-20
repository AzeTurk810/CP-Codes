/*
Telebe of adicto yani AzeTurk810
without limits
*/
#pragma GCC optimize("Ofast")
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define maxN int(1e6 + 123)

vector<int> a;
vector<vector<int>> g;
vector<int> intime , outtime, pa , order;
int timer = -1;
int B = 650;

void dfs(int v , int pa = -1) {
    order.push_back(v);
    intime[v] = ++timer;
    for(int &to : g[v]) {
        if(to == pa) continue;
        dfs(to , v);
    }
    outtime[v] = timer;
}

bool is_ansestor(int u , int v) {
    return (intime[u] <= intime[v] && outtime[u] >= outtime[v]);
}

bool comp(const array<int, 4> &a , const array<int, 4> &b) {
    int ll = a[0] / B , rr = b[0] / B;
    if(ll == rr) {
        return (1 & ll ? a[1] < b[1] : a[1] > b[1]);
    }
    return ll < rr;
}

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
            // cout << pos <<endl;ctr();
            tree[pos] += val;
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
} f(maxN);

int mx = 5;
int cnt[maxN] , ans;

void add(int id) {
    int x = a[order[id]];
    f.update(cnt[x], -1);
    cnt[x] ++;
    f.update(cnt[x], 1);
}

void del(int id) {
    int x = a[order[id]];
    f.update(cnt[x], -1);
    cnt[x] --;
    cerr << cnt[x] << ln;
    f.update(cnt[x], 1);
}

void solve() {
    int n , q;
    cin >> n >> q;
    g.resize(n);
    intime.resize(n);
    outtime.resize(n);
    a.resize(n);
    for(int i = 0;i < n;i ++) {
        cin >> a[i];
    }
    for(int i = 0;i < n - 1;i ++) {
        int u , v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i <= n +  122;i++) {
        cnt[i] ++;
    }
    dfs(0);
    vector<array<int, 4>> querys(q);
    for(int i = 0;i < q;i++) {
        int u , k;
        cin >> u >> k;
        u--;
        querys[i] = {intime[u] , outtime[u] , k , i};
    }
    sort(querys.begin() , querys.end() , comp );
    int l = 0 , r = -1;
    int anss[q];
    for(auto &[ql , qr , k , id] : querys) {
        while (ql < l) {
            l--;
            add(l);
        }
        while(r < qr) {
            r++;
            add(r);
        }
        while(l < ql) {
            del(l);
            l++;
        }
        while(qr < r) {
            del(r);
            r--;
        }
        anss[id] = f.query(k + 1, maxN - 10);
    }
    for(int i = 0;i < q;i++) {
        cout << anss[i] << ln;
    }
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//   cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
