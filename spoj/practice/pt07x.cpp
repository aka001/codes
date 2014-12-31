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
vector<int> arr[100006];
int f[100005],visited[100006];
int main()
{
	int n,i,sz,ans=0,a,b,val1,v1,v2,j;
	pair<int,int> val;
	set< pair<int,int> > st;
	si(n);
	rep(i,n-1)
	{
		si(a);
		si(b);
		arr[a].pb(b);
		arr[b].pb(a);
	}
	FOR(i,1,n+1)
	{
		sz=arr[i].size();
		f[i]=sz;
		st.insert(mp(f[i],i));
	}
	while(!(st.empty()))
	{
		ans++;
		val=*(st.begin());
		st.erase(st.begin());
		v1=val.F;
		v2=val.S;
		//printf("%d %d\n",v2,v1);
		visited[v2]=1;
		sz=arr[v2].size();
		rep(i,sz)
		{
			j=arr[v2][i];
			if(visited[j]==0)
			{
				val1=j;
				break;
			}
		}
		visited[val1]=1;
		if(st.find(mp(f[val1],val1))!=st.end())
		{
			st.erase(st.find(mp(f[val1],val1)));
		}
		f[val1]--;
		sz=arr[val1].size();
		rep(i,sz)
		{
			j=arr[val1][i];
			visited[val1]=1;
			if(st.find(mp(f[j],j))!=st.end())
			{
				st.erase(st.find(mp(f[j],j)));
				if(f[j]>=2)
					st.insert(mp(f[j]-1,j));
			}
			f[j]--;
		}
	}
	pin(ans);
	return 0;
}










