/*
Telebe of Adicto && Mamedov yani AzeTurk810.
Ve Osman_112
I see humans but no humanity.
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

bool comp(const pair<int, int> &a , const pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

bool cmp(const array<int, 3> &a , const array<int, 3> &b) {
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

void solve() {
      int n, m, k;
      cin >> n >> m >> k;
      vector < pair < int , int > > fnt(k);
      vector < pair < int , int > > fntt(k);
      vector<array<int, 3>> fountains(k);
      for(int i = 0; i < k; i++) {
          cin >> fnt[i].first >> fnt[i].second;
          fountains[i] = {fnt[i].first , fnt[i].second , i};
      }
      fntt = fnt;
      sort(fnt.begin(), fnt.end(), comp);
      int mx = 0, ans = 0;
      for(auto i : fnt){
          if(i.second != 1)  continue;
          mx++;
      }
      for(auto i : fnt){
          if(i.first < mx)  
              continue;
          ans += (i.first - mx) * (i.second - 1);
          mx = max(mx, i.first);
      }
      ans += (n - mx) * m;
      vector<bool> anss(k);
      sort(fountains.begin() , fountains.end() , cmp);
      anss[fountains[0][2]] = fountains[0][1] != fountains[1][1];
      int _mx_ = fountains[0][0];
      for(int i = 1;i < fountains.size() - 1; i++) {
          if(fountains[i][1] != fountains[i + 1][1] && _mx_ < fountains[i][0]) {
              anss[fountains[i][2]] = true;
          } else {
              anss[fountains[i][2]] = false;
          }
          _mx_ = max(_mx_ , fountains[i][0]);
      }
      anss[fountains[fountains.size() - 1][2]] = (fountains.back()[0] > _mx_);
      cout << ans << ln;
      for(int i = 0;i < k;i ++){
          cout << anss[i] << ' ';
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
