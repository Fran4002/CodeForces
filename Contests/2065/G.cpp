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

vll primes;
ll m;

void pre() {
  const ll n = 2e5;
  vector<bool> num(n + 1);
  num[0] = num[1] = false;
  for (ll i = 2; i < n; i++) {
    if (!num[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j < n; j += i) {
      num[j] = false;
    }
  }
  m = primes.size();
}

void solve () {
  ll n;
  cin >> n;

  map<ll, ll> solo, dos;
  map<ll, map<ll, ll>> combi;

  while (n--) {
    ll x;
    cin >> x;

    vpll pp;
    ll tt = 0;

    for (auto& p: primes) {
      if (p > x / 2) break;
      if (x % p) continue;

      ll c = 0;
      while (x % p == 0) {
        x /= p;
        if (tt++ > 2) break;
        c++;
      }

      pp.push_back({p, c});
    }

    if (tt > 2) continue;
    if (tt == 1) solo[pp.front().first]++;
    else if (pp.size() == 1) dos[pp.front().first]++;
    else combi[pp.front().first][pp.back().first]++;
  }

  ll soloT = 0;
  for (auto& p: solo) {
    soloT += p.second;
  }
  ll total = 0;
  for (auto& p: solo) {
    total += (soloT - p.second) * p.second;
  }

  total /= 2;

  for (auto& p: dos) {
    total += p.second * (p.second - 1) / 2 + p.second * solo[p.first] + p.second;
  }

  for (auto& p: combi) {
    ll cont = 0;
    for (auto& p2: p.second) {
      cont += p2.second;

      total += p2.second * (p2.second - 1) / 2 + p2.second * solo[p2.first] + p2.second;
    }

    total += cont * solo[p.first];
  }

  cout << total << '\n';
}
 
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);

  ll t = 1;
 
  cin >> t;
  
  pre();
  for (ll i = t; i > 0; i--) {
    //cout << "Test #" << t - i + 1 << ":\n";
    solve();
  }
}
