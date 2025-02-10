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

  vpll sarr;
  sarr.reserve(n);
  vll arr(m);

  for (ll i = 0; i < n; i++) {
    cin >> arr;
    ll t = 0;
    ll p = 0;

    for (ll j = 0; j < m; j++) {
      p += (m - j) * arr[j];
      t += arr[j];
    }

    sarr.push_back({t, p});
  }


  sort(all(sarr));

  ll total = 0;
  for (ll i = 0; i < n; i++) {
    //cout << sarr[i].first << " " << sarr[i].second << '\n';
    total += sarr[i].second;
    total += sarr[i].first * i * m;
  }

  cout << total << '\n';
}
 
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
 
  ll t = 1;
 
  cin >> t;
 
  for (ll i = t; i > 0; i--) {
    //cout << "Test #" << t - i + 1 << ":\n";
    solve();
  }
}
