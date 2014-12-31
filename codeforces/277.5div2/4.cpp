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
vector<int> arr[3001];
int visited[100001];
int main()
{
	int n,m,i,j,a,b,sz;
	ll calc,ans=0;
	pair<int,int> val;
	si(n);
	si(m);
	rep(i,m)
	{
		si(a);
		si(b);
		arr[a].pb(b);
	}
	FOR(i,1,n+1)
	{
		queue<pair<int,int> > vec;
		vector<int> pushit;
		vec.push(mp(i,0));
		while(!(vec.empty()))
		{
			val=vec.front();
			if(val.S==1)
			{
				//printf("%d %d\n",val.F,val.S);
				while(!(vec.empty()))
				{
					val=vec.front();
					vec.pop();
					sz=arr[val.F].size();
					//printf("here %d %d\n",val.F,sz);
					rep(j,sz)
					{
						calc=arr[val.F][j];
						if(visited[calc]==0)
						{
							pushit.pb(calc);
						}
						visited[calc]++;
					}
				}
			}
			else
			{
				vec.pop();
				sz=arr[val.F].size();
				rep(j,sz)
				{
					calc=arr[val.F][j];
					vec.push(mp(calc,1));
				}
			}
		}
		sz=pushit.size();
		FOR(j,1,n+1)
		{
			if(j==i)
			{
				visited[j]=0;
				continue;
			}
			calc=visited[j];
			//printf("i=%d j=%d calc=%lld\n",i,j,calc);
			ans+=(calc*(calc-1))/2;
			visited[j]=0;
		}
	}
	pln(ans);
	return 0;
}










