// Telebe of adicto yani AzeTurk810
// Why i am not a teacher?  ?(idea from Ayxan007)
#include <bits/stdc++.h>

using namespace std;
using ll= int64_t;
using ull=unsigned int64_t;

# define mpll map<ll,ll>
# define umpll unordered_map<ll,ll>
# define vv vector<vector
# define vint vector<int>
# define vull vector<unsigned long long>
# define sint set<int>
# define vpri vector<pair<int,int>>
# define vll vector<long long>
# define vbl vector<bool>
# define vvint vector<vector<int>>
# define vvll vector<vector<long long>>

/* Other defines*/
# define qint queue<int>

//# define endl '\n'
# define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# define range(a,b,c) for(int i=a;i<b;i+=c)
# define ranger(a,b,c) for(int r=a;r<b;r+=c)
# define arange(a,b,c) for(int i=a;i>b;i-=c)
# define bend(x) (x).begin(),(x).end()
# define pb push_back
# define sortv(v) sort((v).begin() , (v).end());
# define fori(x) for(int i=0;i<x;i++)
# define forj(y) for(int j=0;j<y;j++)
# define fori1(x) for(int i=1;i<=x;i++)
# define forj1(y) for(int j=1;j<=y;j++)
# define forn(x,c) for(int i=0;i<n;i+=c)
# define ff first
# define ss second
# define INFi 1e9
# define INFll 1e18
# define printfprs(v) for(int alma = 0;alma<(v).size();alma++){cout<<(v)[alma].ff<< ' '<<(v)[alma].ss<<endl;};
# define printfv(v) {for(int alol = 0 ; alol < (v).size() ; alol++){cout<<(v)[alol]<<' ';}cout << endl;}
# define ln '\n'
//# define T int_fast32_t
# define int ll

int loopcnt = 6;
void ctr()
{
    loopcnt--;
    if(loopcnt <= 0)exit(0);
}

const int antiminus =1e6 + 10;

int maxN = 1e6 + 123;

int N, U , D , I , J , lc , L;
vvint lifts;
struct DSU
{
	vector<int> par;
	int n , components;
	DSU(int _n) 
	{
		n = _n;
		components = n;
		par.assign(n , -1);
	}
	int Find(int u)
	{
		if(par[u] < 0 ) return u;
		return par[u] = Find(par[u]);
	}
	bool ino(int u , int v) {
		return (Find(u) == Find(v));
	}
	bool Union(int u , int v)
	{
		// cerr << u << ' ' << v << endl;
		u = Find(u);
		v = Find(v);
		if(u != v) {
			components--;
			if(par[u] > par[v]) {
				par[v] += par[u];
				par[u] = v;
				return true;
			}
			par[u] += par[v];
			par[v] = u;
			return true;
		} else {
			return false;
		}
	}
};

int stsk1(int n) {
	int c[n] , t[n] , sum = 0 , ans = 0;
	fori(n) {
		cin >> t[i] >> c[i] ;
		sum += t[i];
		// sum++;
		ans += sum * c[i];
	}
	return ans;
}

void solve() {
	int a[3] , b , c , ans , ab;
	cin >> a[0] >> a[1] >> a[2];
	ans = INFi;
	fori(11) {
		ans = min(ans , (abs(i -  a[0])) + abs(i - a[1]) + abs(i - a[2]));
	}
	cout << ans << ln;
}
signed main()
{
    fastio;
    int t = 1;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> t;
    while(t--) {
    	solve();
    }
    return 0;
}


