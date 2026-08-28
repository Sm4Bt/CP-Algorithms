#include<bits/stdc++.h>

#define ll long long
#define PB push_back
#define endl '\n'

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e5;

int main(){
	
	vector<ll> primos;
	int k;
	ll i,j;
	
	ll ini,p;
	int n_primos=0;
	int vezes=10000;
	char crivo[MAX]; // usa char pq ocupa 1 so byte, daria pra tentar concatenar valores pra trabalhar com bits ao inves de bytes
	
	for(i=0 ; i<MAX ; i++){ // crivo[i] guarda se i+k*MAX eh primo
		crivo[i]=1;
	}
	crivo[0]=0;
	crivo[1]=0;

	for(i=0 ; i<MAX ; i++){
		if(crivo[i]){
			primos.PB(i);
			n_primos++;
			for(j=i*i ; j<MAX ; j+=i){
				crivo[j]=0;
			}
		}
	}
	
	for(k=1 ; k<vezes ; k++){
		for(i=0 ; i<MAX ; i++){
			crivo[i]=1;
		}
		
		for(i=0 ; i<n_primos ; i++){
			ini = k*MAX-1;
			p = primos[i];
			if(p*p> ini+MAX) break;
			for(j= p-1-(ini%p) ; j<MAX ; j+=p){
				crivo[j]=0;
			}
		}
		for(i=0 ; i<MAX ; i++){
			if(crivo[i]){
				primos.PB(i+k*MAX);
				n_primos++;
			}
		}
	}
	
	/*for(i=0 ; i<n_primos ; i++){
		cout << primos[i] << endl;
	}*/
	cout << n_primos;
	
	
return(0);
}