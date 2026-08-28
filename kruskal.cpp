#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mkp make_pair
#define mkt(a,b,c) mkp(a,mkp(b,c))
#define endl '\n'

const int MAX = 2 + 2e5;

#define _ ios_base::sync_with_stdio(0).cin.tie(0);

using namespace std;

typedef pair<int,int> pii;
typedef pair<ll,pii> plii;

int pai[MAX], peso[MAX];

int find(int x){
	if(pai[x] == x) return(x);
	return( pai[x] = find(pai[x]) );
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	
	if(peso[x] > peso[y]) pai[y] = x;
	if(peso[y] > peso[x]) pai[x] = y;
	if(peso[x] == peso[y]){
		pai[y] = x;
		peso[x]++;
	}
	
}



int main(){
	int n,m ; cin >> n >> m;
	
	int i,a,b;
	ll d,s=0;
	pii pa;
	
	vector<plii> is(m);
	
	for(i=0 ; i<n ; i++){
		peso[i]=0;
		pai[i]=i;
	}
	
	for(i=0 ; i<m ; i++){
		cin >> a >> b >> d;
		a--;
		b--;
		is[i] = mkt(d,a,b);
	}
	
	sort(is.begin(),is.end());
	
	for(i=0 ; i<m ; i++){
		pa = is[i].second;
		if( find(pa.first) != find(pa.second) ){
			join(pa.first , pa.second);
			s+=is[i].first;
		}
	}
	
	cout << s;
	
return(0);
}