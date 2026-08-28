#include<bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair<ll,int> pli;
typedef pair<pli,int> plii;

int main(){

	int n,m; cin >> n >> m;
	int i,a,b,u,j;
	ll d;
	
	vector<vector<pli>> is(n);
	set<plii> fila;
	set<plii>::iterator it;
	pli pa;
	
	vector<ll> dis(n);
	vector<int> t(n), pai(n), cam(n);
	
	for(i=0 ; i<n ; i++){
		pai[i]=i;
		dis[i]=-1;
		t[i]=0;
	}
	
	for(i=0 ; i<m ; i++){
		cin >> a >> b >> d;
		a--;
		b--;
		is[a].push_back(make_pair(d,b));
		is[b].push_back(make_pair(d,a));
		t[a]++;
		t[b]++;
	}
	
	fila.insert(make_pair(make_pair(0,0),0));
	
	while(!fila.empty()){
		it = fila.begin();
		
		u = (it->first).second;
		
		fila.erase(it);	
		
		if(dis[u]!=-1)continue;
		
		dis[u] = (it->first).first;
		pai[u] = it->second;
		
		for(i=0 ; i<t[u] ; i++){
			pa = is[u][i];
			fila.insert(make_pair(make_pair(dis[u] + pa.first,pa.second),u));
		}
	}
	if(dis[n-1]==-1) cout << -1;
	else{
		j=-1;
		i=n-1;
		while(i!=0){
			j++;
			cam[j]=i+1;
			i = pai[i];
		}
		cout << 1 << " ";
		for( ; j>=0 ; j--) cout << cam[j] << " ";
	}
	
return(0);
}