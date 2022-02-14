#include <bits/stdc++.h>
using namespace std;


long long int MDC(long long int x, long long int y) {
return __gcd(x, y);
}

long long MMC(long long int x,long long int y) {
return x * 1ll * y / MDC(x, y);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	long long int atual = 1;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		atual = MDC(k, MMC(atual, c));
	}
	if(atual == k){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
return 0;
}
