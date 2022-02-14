#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = __int128;
using pll = pair<ll, ll>;

int g[11][101];

int beast[11];
int b, z;
int vis[11][101];
int cycle[11];
int begin_of_cycle[11];

ll gcd(ll a, ll b, ll& x, ll& y);

ll MMC(ll x, ll y) {
    return x * 1ll * y / __gcd(x, y);
}

pll MergeEquations(pll a, pll b){
    ll x, y;
    ll d = gcd(a.S, b.S, x, y);
    
    if((b.F - a.F) % d) return {-1, -1};
    ll ans, K = MMC(a.S, b.S);
    ll k1 = (x * ((b.F - a.F)/d)) % K;
    ans = a.F + (k1*a.S) % K;
    ans %= K;
    
    if(ans < 0) ans += K;
    
    return {ans, MMC(a.S, b.S)}; 
}

pll CRT(vector<pll> equations){
	
    pll answer = equations[0];
    
    for(auto eq : equations){
        answer = MergeEquations(answer, eq);

        if(answer.F == -1ll) return answer;
    }
    
	return answer;
}

bool CaptureAll(){
	for (int i = 1; i <= b; i++){
		if(beast[i] != beast[1]) return false;
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(vis, -1, sizeof vis);
	
	cin >> b >> z;
	for (int i = 1; i <= b; i++){
		int startpos;
		cin >> startpos;
		
		beast[i] = startpos;
        vis[i][beast[i]] = 0;
		for(int u = 1; u <= z; u++){
			int v;
			cin >> v;
			g[i][u] = v;
		}
	}
    for(int t = 0; t <= 2*z; t++){
		if(CaptureAll()){
			cout << beast[1] << " " << t << endl;
			return 0;
		}
		
		for(int i = 1; i <= b; i++){
			if(vis[i][g[i][beast[i]]] != -1 and cycle[i] == 0){
				cycle[i] = t + 1 - vis[i][g[i][beast[i]]];

			}
            vis[i][beast[i]] = t;
			beast[i] = g[i][beast[i]];
		}
	}
  
  long long int ans = 9223372036854775807ll;
  int found = -1;
  for(int zoo = 1; zoo <= z; zoo++){
		bool failed = false;
		for(int i = 1; i<= b; i++){
			if(vis[i][zoo] <= z){
				failed = true;
			}
		}
		if(failed) continue;
		
		vector<pair<ll, ll>> equations;
		for(int i = 1; i <= b; i++){
            equations.emplace_back(vis[i][zoo] % cycle[i], cycle[i]);
		}
        
        pll sol = CRT(equations);
        if(sol.F == -1ll) continue;
        if(ans >= sol.F) found = zoo, ans = min(ans, (long long) sol.F);
    }
	
    if(found != -1){
        cout << found << " " << ans << endl;
        return 0;
    }
    
	cout << '*' << endl;
      
	return 0;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

