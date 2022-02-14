#include <bits/stdc++.h>
using namespace std;

long long int fatorial[5001];
const int MOD = 1000000007;
int exp_mod(int a, int b, int m);

long long int nCr(int n, int r){
	if(r > n){
	return 0;
	}
	// nCr = (n!) / (r! * (n-r)!)
	long long int dividendo = fatorial[n];
	long long int divisor = (fatorial[r] * fatorial[n-r])%MOD;
	return (dividendo * exp_mod(divisor, MOD-2, MOD))%MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fatorial[0] = 1;
	for(int i = 1; i < 5001;i++){
		fatorial[i] = (fatorial[i-1] * i) % MOD;
	}
	int n, k;
	while(cin >> n >> k){
		if(n == 0 and k == 0) return 0;
		
		long long int right_answer = (nCr(n-2, ceil((k+1)/2.0) - 1)
		* nCr(n-2, floor((k+1)/2.0) - 1)) % MOD;
		
		cout << (2 * right_answer) % MOD << endl;
	}
return 0;
}

int exp_mod(int a, int b, int m){
	if(b==0){ // qualquer número elevado a 0 é igual a 1.
		return 1;
	}
	// calcula a resposta para metade do expoente.
	long long int x = exp_mod(a, b/2, m);
	if(b%2==0){
		// Como já sabemos o valor de a^(b/2) podemos elevar
		// ao quadrado e obteremos o valor a^b.
		return (x*x)%m;
	}else{
		// Devido o expoente ser impar, ao elevarmos ao quadrado
		// o resultado sera igual a a^(b-1) e será necessário
		// multiplicar pela base para adicionar 1 no expoente.
		return (a*((x*x)%m))%m;
	}
}
