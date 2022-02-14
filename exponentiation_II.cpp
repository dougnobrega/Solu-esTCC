#include <iostream>
using namespace std;

const int M = 1e9 + 7;
int exp_mod(int a, int b, int m);

int main(){
	int n;
	int a, b , c;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		int y = exp_mod(b, c, M-1);
		cout << exp_mod(a, y, M) << endl;
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
