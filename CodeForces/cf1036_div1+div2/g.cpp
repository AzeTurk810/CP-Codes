#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static constexpr ll INF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        // 1) Compute prefix‐minima pmin[i] and their prefix‐sum psum[i].
        vector<ll> pmin(n+1, INF), psum(n+1, 0);
        for(int i = 1; i <= n; i++){
            pmin[i] = min(pmin[i-1], a[i]);
            psum[i] = psum[i-1] + pmin[i];
        }
        ll orig = psum[n];

        // 2) Precompute suffix_sum[j] = orig - psum[j-1].
        //    Also track two helpers as we scan i=1..n:
        //    (a) first_good: earliest i with a[i] >= pmin[i-1]  (zero‐penalty positions)
        //    (b) best_delta & pos_delta: minimal (pmin[i-1] - a[i]) among i where a[i]<pmin[i-1]
        vector<ll> suffix_sum(n+2, 0);
        for(int j = 1; j <= n; j++){
            suffix_sum[j] = orig - psum[j-1];
        }

        int first_good = -1;
        ll    best_delta = INF;
        int   pos_delta  = -1;

        // 3) Prepare a bucket for best gain at each cost c = 0..(n-1).
        //    Initialize with very negative, except cost=0 can always have gain=0 (no-op).
        vector<ll> bestGain(n, LLONG_MIN);
        bestGain[0] = 0;

        // 4) Sweep j from 2..n, updating our helpers with i=j-1, and then
        //    generating up to two (cost,gain) candidates for operations ending at j.
        for(int j = 2; j <= n; j++){
            int i = j-1;
            // --- incorporate the new index i into our helper state ---
            if(a[i] >= pmin[i-1]){
                if(first_good < 0) 
                    first_good = i;
            } else {
                ll delta = pmin[i-1] - a[i];
                if(delta < best_delta){
                    best_delta = delta;
                    pos_delta  = i;
                }
            }

            ll ssum = suffix_sum[j];

            // (1) zero‐penalty candidate, if any good i exists in [1..j-1]
            if(first_good >= 1){
                int cost = j - first_good;
                // gain = sum of suffix‐prefix‐mins (we zero that suffix)
                ll gain = ssum;
                bestGain[cost] = max(bestGain[cost], gain);
            }

            // (2) penalty candidate, if we have seen at least one delta‐source
            if(pos_delta >= 1){
                int cost = j - pos_delta;
                ll penalty = min(a[j], best_delta);
                ll gain = ssum - penalty;
                bestGain[cost] = max(bestGain[cost], gain);
            }
        }

        // 5) Build a suffix maximum of bestGain over costs >= c.
        //    so suffMax[c] = max_{k>=c} bestGain[k].
        vector<ll> suffMax(n+1, LLONG_MIN);
        ll running = LLONG_MIN;
        for(int c = n-1; c >= 0; c--){
            running = max(running, bestGain[c]);
            suffMax[c] = running;
        }

        // 6) Output answers for x = 0..n-1 (i.e. cost threshold x).
        //    For x=0 we can also choose no‑op gain=0, which is already in suffMax[0].
        //    For x>=1 we must pick a real operation (guaranteed to exist).
        for(int x = 0; x < n; x++){
            ll best = suffMax[x];
            // best might be LLONG_MIN if truly impossible, but problem guarantees
            // an answer exists for each x>=1. For safety, we clamp below.
            if(best < LLONG_MIN/2) best = 0;
            cout << (orig + best) << (x+1<n? ' ' : '\n');
        }
    }

    return 0;
}

