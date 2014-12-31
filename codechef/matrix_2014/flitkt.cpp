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
char ch[10000];
ll hash(char chit[10000])
{
	int i,sz;
	ll ans=0,calc;
	calc=1;
	sz=strlen(chit);
	rep(i,sz)
	{
		ans=calc*chit[i];
		calc*=26;
		ans%=mod;
		calc%=mod;
	}
	return ans;
}
vector<int> arr[105];
vector<pair<int,int> > store;
int n,visited[1000],val;
void dfs(int node, int cnt)
{
	int sz,i;
	sz=arr[node].size();
	//printf("node=%d sz=%d\n",node,sz);
	if(sz==0)
	{
		//printf("cnt=%d node=%d n=%d\n",cnt,node,n);
		if(cnt==2*n)
		{
			//printf("hie\n");
			val=1;
		}
		else
		{
			//printf("hie1\n");
			val=0;
		}
		return;
	}
	//printf("%d %d\n",node,arr[node][0]);
	if(visited[node]==1)
	{
		val=0;
		return;
	}
	visited[node]=1;
	store.pb(mp(node,arr[node][0]));
	//printf("node=%d sz=%d\n",node,sz);
	FOR(i,0,sz)
	{
		dfs(arr[node][i],cnt+2);
	}
}
int main()
{
	int t,i,cnt,val1,sz,j;
	ll ans=0,calc;
	si(t);
	while(t--)
	{
		map<ll,int> mapit;
		string disp[1000];
		si(n);
		cnt=1;
		rep(i,n)
		{
			ss(ch);
			calc=hash(ch);
			if(mapit[calc]==0)
			{
				mapit[calc]=cnt++;
			}
			val=mapit[calc];
			disp[val]=ch;

			ss(ch);
			calc=hash(ch);
			if(mapit[calc]==0)
			{
				mapit[calc]=cnt++;
			}
			val1=mapit[calc];
			disp[val1]=ch;
			arr[val].pb(val1);
			//printf("%d %d\n",val,val1);
		}
		//pin(cnt);
		FOR(i,1,cnt)
		{
			sz=arr[i].size();
			/*if(sz!=0)
				printf("%d %d\n",i,arr[i][0]);*/
		}
		FOR(i,1,cnt)
		{
			FOR(j,1,cnt)
				visited[j]=0;
			sz=arr[i].size();
			store.clear();
			dfs(i,0);
			//printf("i=%d val=%d\n",i,val);
			if(val==1)
			{
				sz=store.size();
				rep(i,sz)
				{
					cout<<disp[store[i].F];
					cout<<"-";
					cout<<disp[store[i].S];
					//printf("%s-%s",disp[store[i].F],disp[store[i].S]);
					if(i==sz-1)
						printf("\n");
					else
						printf(" ");
				}
				break;
			}
		}
		FOR(i,1,cnt)
		{
			arr[i].clear();
			mapit[i]=0;
		}
	}
	return 0;
}


















