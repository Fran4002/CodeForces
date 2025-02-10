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
  char c1 = '0', c2 = '1';
  ll n, m, k;

  cin >> n >> m >> k;

  if (n < m) {swap(n, m); swap(c1,  c2);}

  if (n - m > k || n < k) {
    cout << "-1\n"; return;
  }

  for (ll i = 0; i < k; i++) {
    cout << c1;
  }

  n -= k;

  if (n == m) {
    for (ll j = 0; j < m; j++) {
      cout << c2 << c1;
    }
    cout << '\n';
    return;
  }

  while (m > n) {
    m--;
    cout << c2;
  }

  for (ll i = 0; i < n; i++) {
    cout << c1 << c2;
  }

  cout << '\n';
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
