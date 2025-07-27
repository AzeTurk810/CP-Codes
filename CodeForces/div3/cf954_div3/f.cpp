/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll 

struct prob {
    vector<int> tin , low , sz ;
    vector<vector<int>> g;
    vector<bool> used;
    int timer , n , m;

    vector<pair<int, int>> bridges;

    void dfs(int v , int pa = -1) {
        used[v] = true;
        sz[v] = 1;
        tin[v] = low[v] = timer++;
        for(int &to : g[v]) {
            if(to == pa) 
                continue;
            if(!used[to]) {
                dfs(to , v);
                sz[v] += sz[to];
                low[v] = min(low[v] , low[to]);
                if(low[to] > tin[v]) {
                    bridges.push_back({to , v});
                }
            } else {
                low[v] = min(low[v] , tin[to]);
            }
        }
    }

    void init() {
        timer = 0;
        g.clear();
    }
    void in() {
        cin >> n >> m;
        g.resize(n);
        tin.resize(n);
        low.resize(n);
        sz.resize(n);
        used.assign(n , false);
        for(int i = 0;i < m;i++) {
            int u , v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        ll ans = (n * (n - 1)) >> 1LL;
        ll cur = ans;
        for(auto &[u , v] : bridges) {
            ll ss =  cur - (ll)(min(sz[v],sz[u]) * (n - min(sz[u] , sz[v])));
            ans = min(ans ,ss); 
        }
        cout << ans << ln;
    }
    void solve() {
        
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
         prob probs;
         probs.init();
         probs.in();
         probs.solve();
    }
}
// Just Imaginary
