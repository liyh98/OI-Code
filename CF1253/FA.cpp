#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll source[MAXN], d0[MAXN], dis[MAXN], done[MAXN], par[MAXN];
vector<ll> C[MAXN];
vector<pll> G[MAXN];
vector< pair<ll, pll> > E;
set<pll> dj;

void change_key(ll node, ll last, ll now){
  dj.erase({last, node});
  dis[node] = now;
  dj.insert({now, node});
  return ;
}

ll A[MAXN], B[MAXN], ans[MAXN];
ll W;

ll get_par(ll u){
  if(par[u] == u) return u;
  return par[u] = get_par(par[u]);
}

bool merge(ll u, ll v){
  ll U = u, V = v;
  u = get_par(u); v = get_par(v);
  if(u == v) return false;
  //cerr << U << " " << V << '\n'; 
  if(C[u].size() < C[v].size()) swap(u, v);
  par[v] = u;
  for(auto x : C[v]){
  	C[u].pb(x);
  	if(get_par(A[x]) == get_par(B[x])) ans[x] = min(ans[x], W);
  }
  C[v].clear();
  return true;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(ans, 31, sizeof ans);
  for(int i = 0; i < MAXN; i++) par[i] = i;
	memset(dis, 31, sizeof dis);
	memset(d0, 31, sizeof d0);

	ll n, m, k, q;
	scanf("%lld%lld%lld%lld", &n, &m, & k, &q);
	ll u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%lld%lld%lld", &u, &v, &w);
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	ll p, f;
	for(int i = 1; i <= k; i++){
	p = i;
    source[p] = p;
    dj.insert({0, p});
    dis[p] = 0;
  }
  ll fr, d, adj;
  while(dj.size()){
    d = (*dj.begin()).F;
    fr = (*dj.begin()).S;
    //debug(fr);
    dj.erase(dj.begin());
    for(auto edge : G[fr]){
      adj = edge.F; w = edge.S;
      if(done[adj] == 1){
        E.pb({dis[adj] + dis[fr] + w ,{source[fr], source[adj]}});
      }
      if(dis[adj] > d + w){
        change_key(adj, dis[adj], d + w);
        source[adj] = source[fr];
      }
    }
    done[fr] = 1;
  }
	
	//ll A, B;
	for(int i = 0; i < q; i++){
		scanf("%lld%lld", A + i, B + i);
		C[A[i]].pb(i);
		C[B[i]].pb(i);
		
	}
	//printf("%lld", ans);
	
	
	
  sort(all(E));
  for(auto edge : E){
    W = edge.F;
	if(merge(edge.S.F, edge.S.S)) {
		//cerr << edge.F << '\n';
  	}
  }
	for(int i = 0; i < q; i++) printf("%lld\n", ans[i]);
	return 0;
}