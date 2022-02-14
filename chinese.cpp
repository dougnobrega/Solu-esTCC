#include <bits/stdc++.h>
using ll = __int128;
using namespace std;

ll gcd(ll a, ll b, ll& x, ll& y);

ll MMC(ll x, ll y) {
	return x * 1ll * y / __gcd(x, y);
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int a, n, b, m;
		cin >> a >> n >> b >> m;
		ll x, y;
		ll d = gcd(n, m, x, y);
		
		if ((b - a) % d != 0 ){
			cout << "no solution" << endl;
		}else{
			
		ll ans, K = MMC(n, m);
		ll k1 = (x * ((b - a)/d)) % K;
		ans = a + (k1*n) % K;
		ans %= K;
		if(ans < 0) ans += K;
		
		cout << (long long int)ans << " " << (long long int)K << endl;
		}
	}
return 0;
}
