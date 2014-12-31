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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<int> arr[100006],ans;
int visited[1000006];
void dfs(int node, int cnt)
{
	int i,sz;
	sz=arr[node].size();
	if(visited[node]==1 || (sz==1 && node!=1))
	{
		//printf("node=%d\n",node);
		if(visited[node]==1)
			return;
		ans.pb(cnt);
		return;
	}
	visited[node]=1;
	rep(i,sz)
	{
		dfs(arr[node][i],cnt+1);
	}
}
int main()
{
	int t,n,k,x,y,i,sz,flag;
	si(t);
	while(t--)
	{
		si(n);
		si(k);
		FOR(i,1,n+1)
		{
			visited[i]=0;
			arr[i].clear();
		}
		rep(i,n-1)
		{
			si(x);
			si(y);
			arr[x].pb(y);
			arr[y].pb(x);
		}
		dfs(1,0);
		sz=ans.size();
		flag=0;
		rep(i,sz)
		{
			if(ans[i]%2==0)
				flag=1;
		}
		if(k%2==0)
			flag=1-flag;
		if(flag==0)
			printf("Eli\n");
		else
			printf("Babri\n");
	}
	return 0;
}











