/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll arr[301][301];
vector<int> graph[301],leafit,graph1[301];
int visited[301],maxit=-1;
int flgit[1000006];
void dfs(int node)
{
	int i,sz,val;
	if(visited[node]==0)
	{
		visited[node]=1;
		sz=graph[node].size();
		if(sz==1 && visited[graph[node][0]]==1)
			leafit.pb(node);
		rep(i,sz)
		{
			val=graph[node][i];
			dfs(val);
		}
	}
}
void dfs1(int node,int cnt)
{
	int i,sz,val;
	if(visited[node]==0)
	{
		maxit=max(maxit,cnt);
		visited[node]=1;
		sz=graph[node].size();
		if(sz==1 && visited[graph[node][0]]==1)
			leafit.pb(node);
		rep(i,sz)
		{
			val=graph[node][i];
			dfs1(val,cnt+1);
		}
	}
}
int main()
{
	int n,k1,v,u,i,j,k,sz,ans=0,val,it,fin=mod,k2;
	si(n);
	si(k1);
	/*FOR(i,1,n+1)
	  {
	  FOR(j,1,n+1)
	  {
	  if(i==j)
	  arr[i][j]=0;
	  else
	  arr[i][j]=mod;
	  }
	  }*/
	FOR(i,1,n)
	{
		si(u);
		si(v);
		graph[u].pb(v);
		graph[v].pb(u);
		//		arr[u][v]=1;
		//		arr[v][u]=1;
	}
	n++;
	/*FOR(i,1,n)
	  {
	  FOR(j,1,n)
	  {
	  FOR(k,1,n)
	  {
	  arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
	  }
	  }
	  }*/
	it=1;
	while(it<=n-1)
	{
		FOR(i,1,n)
			graph1[i]=graph[i];
		k2=k1;
		while(k1>0)
		{
			leafit.clear();
			FOR(i,1,n)
				visited[i]=0;
			dfs(it);
			sz=leafit.size();
			vector<pair<int,int> > newit;
			rep(i,sz)
			{
				maxit=-1;
				FOR(j,1,n)
				{
					visited[j]=0;
				}
				val=leafit[i];
				dfs1(val,0);
				if(it==3)
					printf("val=%d maxit=%d\n",val,maxit);
				newit.pb(mp(maxit,val));
			}
			sort(newit.begin(),newit.end());
			sz=newit.size();
			for(i=sz-1;i>=0 && k1>0;i--)
			{
				val=graph[newit[i].S][0];
				//printf("newit=%d val=%d\n",newit[i].S,val);
				//printf("sz1=%d sz2=%d\n",(int)graph[val].size(),(int)graph[newit[i].S].size());
				graph[val].erase(std::remove(graph[val].begin(),graph[val].end(),newit[i].S),graph[val].end());
				graph[newit[i].S].clear();
				//printf("sz1=%d sz2=%d\n",(int)graph[val].size(),(int)graph[newit[i].S].size());
				//printf("newit=%d\n",newit[i].S);
				k1--;
			}
		}
		ans=1;
		FOR(i,1,n)
		{
			maxit=-1;
			FOR(j,1,n)
				visited[j]=0;
			dfs1(i,0);
			ans=max(ans,maxit);
		}
		FOR(i,1,n)
			graph[i]=graph1[i];
		fin=min(fin,ans);
		printf("fin=%d ans=%d it=%d n=%d\n",fin,ans,it,n);
		k1=k2;
		it++;
	}
	pin(fin);
	return 0;
}



















