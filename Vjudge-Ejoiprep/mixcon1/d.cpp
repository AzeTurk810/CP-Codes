/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define max_N int(2e5 + 10)

vector<vector<int>> g;
vector<int> path;
int dist[max_N] , pa[max_N];
int n;
int a , b;

void init() {
    g.clear();
    for(int i = 0;i < n;i++) {
        dist[i] = -1;
        pa[i] = -1;
    }
    path.clear();
}

void bfs(int start = a) {
    queue<int> q;
    q.push(start);
    dist[start] = 0 , pa[start] = start;
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for(auto to : g[from]) {
            if(dist[to] == -1) {
                dist[to] = dist[from] + 1;
                pa[to] = from;
                q.push(to);
            }
        }
    }
}

void path_find(int st = a,int fn = b) {
    path.push_back(fn);
    int cur = pa[fn];
    while(cur != a) {
        path.push_back(cur);
        cur = pa[cur];
    }
    if(st != fn)
        path.push_back(cur);
}

void pth_err() {
    cerr << "Path" << ln;
    for(int &i : path) {
        cerr << i + 1 << ' ';
    }
    cerr << ln;
}

int dfs(int v , int pa = -1) {
    int mx = 0;
    for(int &to : g[v]) {
        if(to != pa)
            mx = max(dfs(to , v) + 1, mx);
    }
    return mx;
}

void solve() {
    init();
    cin >> n;
    cin >> a >> b;
    a--;b--;
    g.resize(n);
    for(int i = 1;i < n;i++) {
        int u , v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    path_find();
//    cerr << path.size() << ln;
//    reverse(path.begin() , path.end());
    const int &node = path[path.size() >> 1];
    int cnt = dfs(node);
    cout << ((n - 1) << 1) - cnt + (path.size() >> 1) << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    n = max_N;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary
