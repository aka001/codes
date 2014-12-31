#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define MAXN 5000
typedef vector < pair < int , int > > VPII;

//for maximum bipartite matching
struct HopcroftKarp{
	vector<int> g[MAXN];
	int n,distX[MAXN],distY[MAXN],mateX[MAXN],mateY[MAXN];
	queue<int> q;
	inline void reset(int m){ n=m; REP(i,n) g[i].clear(); memset(mateX,-1,n*sizeof(int)); memset(mateY,-1,n*sizeof(int)); }
	inline void add_edge(int u,int v){ g[u].push_back(v); }
	inline bool bfs(){
		bool found=false; REP(i,n) if(mateX[i]==-1) q.push(i); REP(i,n) distX[i]=distY[i]=0;
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(int i=0;i<(int)(g[u].size());i++){
				if(distY[g[u][i]]==0){
					distY[g[u][i]]=distX[u]+1;
					if(mateY[g[u][i]]==-1) found=true;
					else distX[mateY[g[u][i]]]=distY[g[u][i]]+1,q.push(mateY[g[u][i]]);
				}
			}
		}
		return found;
	}
	bool dfs(int u){
		for(int i=0;i<(int)(g[u].size());i++){
			if(distY[g[u][i]]==distX[u]+1){
				distY[g[u][i]]=0;
				if(mateY[g[u][i]]==-1||dfs(mateY[g[u][i]])){ mateX[u]=g[u][i]; mateY[g[u][i]]=u; return true; }
			}
		}
		return false;
	}
	int find(){
		int res=0; while(bfs()) REP(i,n) if(mateX[i]==-1) if(dfs(i)) res++;
		return res;
	}
}graph;

vector < int > foo(int n)
{
	vector < int > ret;
	while (n%2 == 0)
	{
		ret.push_back(2);
		n = n/2;
	}
	for (int i = 3; i*i <= (n); i = i+2)
	{
		while (n%i == 0)
		{
			ret.push_back(i);
			n = n/i;
		}
	}
	if (n > 2)
		ret.push_back(n);
	return ret;
}
int main(){
	vector < vector < int > > factor;
	int n,m,a,b,ar[109],prefix1[109]={},prefix2[109]={};
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> ar[i];
		vector < int > my=foo(ar[i]);
		factor.push_back(my);
		prefix1[i]=prefix1[i-1];
		prefix2[i]=prefix2[i-1];
		if(i%2)
			prefix1[i]+=(int)my.size();
		else
			prefix2[i]+=(int)my.size();
		/*
		   cout << ar[i] << "::   " ;
		   for(int j=0; j<my.size(); j++)
		   cout << my[j] << " " ;
		   cout << endl;*/
		//        cout << " :: " << prefix[i] << endl;
	}
	//    cout << prefix1[n] << " ::;   \n";
	//    cout << prefix2[n] << " ::;   \n";
	graph.reset(prefix1[n]+prefix2[n]+1);
	for(int i=0; i<m; i++){
		cin >> a >> b;
		if(a%2==0)swap(a,b);
		for(int j=0; j<factor[a-1].size(); j++)
			for(int k=0; k<factor[b-1].size(); k++)
				if(factor[a-1][j]==factor[b-1][k])
				{
					graph.add_edge(prefix1[a-1]+j+1,prefix1[n]+prefix2[b-1]+k+1);
				}
	}
	cout << graph.find() << endl;
	return 0;
}
