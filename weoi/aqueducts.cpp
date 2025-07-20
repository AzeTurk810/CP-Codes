// Telebe of Adicto yani azeturk810
#include <algorithm>
#include <array>
#include <utility>
#include <vector>

using namespace std;


int lwbound(vector<array<int, 3>> &__nums , pair<int, int> __num) {
    int l = 0 , r = __nums.size() - 1 , mid;
    int _n = __nums.size();
    while(l < r) {
        mid = (l + r) >> 1;
        if(__nums[mid][0] <= __num.first) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    l = r + 1 , r = _n - 1;

    while(l < r) {
        mid = (l + r) >> 1;
        if(__nums[mid][1] <= __num.second) {
            l = mid + 1;
        } else { 
            r = mid - 1;
        }
    }
    int idx = r + 1;

}

vector<int> count(int N, vector<int> S, vector<int> P) {
    vector<int> C(N);
    for(int &i : C)
        i = 0;
    for(int &i : P) {
        i = int(1e6) - i;
    }

    vector<array<int, 3>> __nums(N);
    for(int i = 0;i < N;i++) {
        __nums[i] = {S[i] , P[i] , i};
    }

    sort(__nums.begin() , __nums.end());

    return C;
}
