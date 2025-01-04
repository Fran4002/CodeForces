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
