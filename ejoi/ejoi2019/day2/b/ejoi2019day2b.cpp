/*
Telebe of adicto yani AzeTurk810
without limits
*/
#include <array>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

int dx[] = {0 ,  1  , 0 , -1};
int dy[] = {-1 , 0  , 1 ,  0};

vector<vector<int>> g;
vector<vector<int>> dist;
int n , m;

bool is_valid(int i , int j) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void dijikstra(pair<int, int> start) {
    dist[start.first][start.second] = 0;
    priority_queue<array<int, 3>, vector<array<int, 3>> , greater<array<int, 3>>> pq;
    pq.push({0 , start.first , start.second});
    while (!pq.empty()) {
        auto [dst , fromi , fromj] = pq.top();
        pq.pop();
        cerr << dst << ' ' << fromi << ' ' << fromj << ln;
        if(dist[fromi][fromj] != dst) 
            continue;
        if(g[fromi][fromj] == -1) 
            continue;
        for(int cur=0;cur < 4;cur++) {
            int i = fromi + dx[(cur + g[fromi][fromj]) % 4] , j = fromj + dy[(cur + g[fromi][fromj]) % 4];
            if(!is_valid(i , j))
                continue;
            int cost = cur + dst;
            if(dist[i][j] > cost) {
                cerr << cost << ' ' << fromi << ' ' << fromj << ' ' << i << ' ' << j << ' '<< g[fromi][fromj] << endl;
                pq.push({cost , i , j});
                dist[i][j] = cost;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n, vector<int> (m));
    dist.assign(n, vector<int>(m , INFi));
    for(int i =0;i < n;i++) {
        for(int j= 0 ; j < m;j++) {
            char x;
            cin >> x;
            if(x == 'X' ) {
                g[i][j] = -1;
            } else if(x == 'N') {
                g[i][j] = 0;
            } else if(x == 'S') {
                g[i][j] = 2;
            } else if(x == 'W') {
                g[i][j] = 3;
            } else {
                g[i][j] = 1;
            }

        } 
    }
    dijikstra({0 , 0});
    cout << dist[n - 1][m - 1] << ln;
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
