//AI-generated, for reference only

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <queue>
#include <random>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <fstream>
#include <complex>
#include <array>
#include <string>
#include <bitset>
#include <cassert>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e18;
const int Ts = 2e6 + 16;
const int N = 200016;
const double eps = 1e-10;
const int MOD = 998244353;
const char nl = '\n';

int n, k;
int dp[100013][22];
int a[100013];
int cnt[100013];

void rec(int l, int r, int opt_l, int opt_r, int j) {
    if (l > r) return;
    int mid = (l + r) / 2;
    int opt = opt_l;
    int sm = 0;
    for (int i = opt_l; i <= mid; i++) {
        sm += cnt[a[i]]++;
    }
    for (int i = opt_l; i <= min(mid, opt_r); i++) {
        if (dp[mid][j] > dp[i - 1][j - 1] + sm) {
            dp[mid][j] = dp[i - 1][j - 1] + sm;
            opt = i;
        }
        sm -= --cnt[a[i]];
    }
    for (int i = min(mid, opt_r) + 1; i <= mid; i++) cnt[a[i]]--;
    rec(l, mid - 1, opt_l, opt, j);
    rec(mid + 1, r, opt, opt_r, j);
}

void solve() {
   cin >> n >> k;
   for (int i = 0; i <= n; i++) {
       for (int j = 0; j <= k; j++) dp[i][j] = INF;
   }
   dp[0][0] = 0;
   for (int i = 0; i < n; i++) cin >> a[i + 1];
   for (int i = 0; i < k; i++) {
       rec(1, n, 1, n, i + 1);
   }
   cout << dp[n][k];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

#ifdef LOCAL
    ifstream in("input.txt", ios::binary);
    cin.rdbuf(in.rdbuf());
    ofstream out("output.txt", ios::binary);
    cout.rdbuf(out.rdbuf());
#endif
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}