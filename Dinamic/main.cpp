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

int dp[100013][22];

void rec(int l, int r, int opt_l, int opt_r, int j) {

}

void solve() {
   int n, k; cin >> n >> k;
   vector<int> a(n);
   for (int i = 0; i < n; i++) cin >> a[i];
   vector<int> cnt(n + 1);
   cnt[a[0]] = 1;
   for (int i = 1; i < n; i++) {
       cnt[a[i]]++;
       dp[i][1] = dp[i - 1][1] + cnt[a[i]] - 1;
   }
   for (int l = 2; l <= k; l++) {
       for (int i = 0; i < n; i++) {
           dp[i][l] = INF;
           if (i < l - 1) {
               continue;
           }
           cnt = vector<int>(n + 1);
           int st = 0;
           for (int j = l - 1; j <= i; j++) {
               st += cnt[a[j]]++;
           }
           for (int j = l - 2; j < i; j++) {
               dp[i][l] = min(dp[i][l], dp[j][l - 1] + st);
               st -= --cnt[a[j + 1]];
           }
       }
   }
   cout << dp[n - 1][k] << nl;
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