/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define maxK 25
#define maxN int(1e5 + 123)

vector<vector<int>> g;

struct segmentTree {
    int N , Null_val;
    vector<int> t;

    segmentTree(int _n) {
        t.resize(_n * 4);
        N = _n;
    }

    void build(int v , int l , int r , vector<int> &a) {
        if(l == r) {
            t[v] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a);
        build((v << 1)|1 , mid + 1 , r , a);
        t[v] = max(t[(v << 1)] , t[(v << 1)|1]);
    }

    void upd(int v , int l , int r  , int &val , int &pos) {
        if(l == r) {
            t[v] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos);
        else upd((v << 1)|1 , mid + 1 , r , val , pos);
        t[v] = max(t[(v << 1)] , t[(v << 1)|1]);
    }

    int ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return max(ask((v << 1) , l , mid , ql , qr),
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

vector<int> pref , depth;
vector<pair<int, int>> d;
int up[maxK][maxN];

int lc(int v , int k) {
    for(int i = maxK - 1; i >= 0;i--) {
        if((1LL << i) & k) {
            v = up[i][v];
        }
    }
    return v;
}

void dfs(int v , int pa = -1) {
    if(pa != -1) {
        depth[v] = depth[pa] + 1;
        pref[v]  = pref[pa]  + d[v].second;
        up[0][v] = pa;
    }
    else {
        pref[v]  = 0;
        depth[v] = 0;
        up[0][v] = v;
    } 
    for(int i = 1;i < maxK;i++) {
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for(int &to : g[v]) {
        if(to != pa)
            dfs(to ,v);
    }
}

void solve() {
    int n , q;
    cin >> n >> q;
    d.resize(n + 1);
    g.resize(n + 1);
    pref.resize(n + 1);
    depth.resize(n + 1);
    d[0] = {0 , INFi};
    for(int i = 1;i <= n;i ++) {
        int u , v;
        cin >> u >> v;
        d[i] = {u , v};
    }
    segmentTree t(n + 1);
    t.Null_val = 0;
    vector<int> dc(n + 1);
    for(int i = 0;i <= n;i++) {
        dc[i] = d[i].first;
    }
    t.build(1 , 0 , n , dc);
    vector<int> pa(n + 1);
    pa[0] = 0;
    for(int i = 1;i <= n;i++) {
        int l = i ,best = -1,  r = n;
        while(l <= r) {
            int mid = (r + l) >> 1;
//            cerr << t.ask(1 , 0 , n , i , mid) << ' '<< mid << ' ' <<i  << ' ' << dc[i] << ln;
            if(t.ask(1 , 0 , n , i , mid) <= dc[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
                best = mid;
            }
        }
        if(best == -1) {
            g[0].push_back(i);
        } else {
            g[best].push_back(i);
        }
    }
//    cerr << g[0].size() << " sala" << ln;
    dfs(0);
    while (q--) {
        int u;
        ll v;
        cin >> u >> v;
        int l = 0 , r = depth[u] + 1;
//        cerr << u << ' ' << depth[u] << ' '<< lc(u , r) << ln;
        assert(lc(u , r) == 0);
        while(l <= r) {
            int mid = (r + l) >> 1;
            int w = pref[lc(u , mid + 1)] - pref[u];
            w *= -1;
//            cerr << u << ' '<< mid + 1<< ' '<< w << ' '<< v << ln;
            if(w >= v) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << lc(u , max(0 , l)) << ln;
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
