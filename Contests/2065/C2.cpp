#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
 
using ll = long long int;
using ui = unsigned int;
using ull = unsigned long long int;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
 
template<typename T>
istream& operator>> (istream& is, vector<T>& v) {
  for (auto& a: v) is >> a;
  return is;
}
 
template<typename T>
ostream& operator<< (ostream& os, vector<T>& v) {
  for (auto& a: v) os << a << " ";
  return os;
}
 
void solve () {
  ll n, m;
  cin >> n >> m;
  vll arr(n), brr(m);
  cin >> arr >> brr;

  sort(all(brr));

  ll low = LONG_LONG_MIN;

  for (auto& a: arr) {
    ll aux = a + low;
    ll lc_low = 1e9;
    auto it = lower_bound(all(brr), aux);

    if (it != brr.end()) {
      lc_low = *it - a;
    } else lc_low = a;

    if (a < lc_low && a >= low) lc_low = a;

    //cout << low << " " << lc_low << '\n';
    if (lc_low < low) {
      cout << "NO\n";
      return;
    }

    low = lc_low;
  }

  cout << "YES\n";
}
 
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
 
  ll t = 1;
 
  cin >> t;
 
  for (ll i = t; i > 0; i--) {
    //cout << "Test #" << t - i + 1 << ":\n";
    solve();
    //cout << '\n';
  }
}
