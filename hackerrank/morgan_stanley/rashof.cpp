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
int visited[1000006],vv[1000006],cnt=0,tin[1000006];
vector<pair<pair<int,int>,int> > arr;
vector<int> grph[100009],cont,fin;
int dfs(int n, map<pair<int,int>, int> mapit,int cit)
{
	if(visited[n]==0)
		cit++;
	else 
		return cit;
	visited[n]=1;
	int i,sz,j,calc=0,calc1;
	sz=grph[n].size();
	rep(i,sz)
	{
		j=grph[n][i];
		calc1=dfs(j,mapit,0);
		mapit[mp(n,j)]=calc1;
		calc+=calc1;
	}
	tin[n]=calc;
	return calc;
}
int main()
{
	ll t,a,b,c,d,n,k,i,val,j,cit;
	ll ans,v1,v2,c1,c2,temp;
	sl(t);
	while(t--)
	{
		map<pair<int,int>,int> mapit;
		arr.clear();
		cont.clear();
		fin.clear();
		FOR(i,1,100006)
		{
			tin[i]=0;
			grph[i].clear();
		}
		ans=0;
		pair<pair<int,int>,int> calc;
		pair<int,int> vit;
		vector<pair<int,int> > newit;
		sl(n);
		sl(k);
		rep(i,n-1)
		{
			sl(a);
			sl(b);
			sl(c);
			sl(d);
			grph[a].pb(b);
			grph[b].pb(a);
			arr.pb(mp(mp(a,b),c));
			cont.pb(d);
		}
		/*rep(i,n-1)
		{
			v1=newit[i].F;
			if(v1>=0 || k<=0)
			{
				break;
			}
			k--;
			v2=newit[i].S;
			//printf("%d %d %d %lld  %lld\n",vit.F,vit.S,calc.S,v1,v2);
			arr[v2].S+=v1;
		}*/
		/*FOR(i,1,n+1)
		{
			cnt=0;
			FOR(j,1,n+1)
				visited[j]=0;
			dfs(i);
			vv[i]=cnt;
			printf("i=%d vv=%d\n",i,vv[i]);
		}*/
		dfs(1,mapit,0);
		rep(i,n-1)
		{
			calc=arr[i];
			vit=calc.F;
			v1=vit.F;
			v2=vit.S;
			
			/*FOR(j,1,n+1)
				visited[j]=0;
			visited[v2]=1;
			cnt=0;
			dfs(v1);
			c1=cnt;

			FOR(j,1,n+1)
				visited[j]=0;
			visited[v1]=1;
			cnt=0;
			dfs(v2);
			c2=cnt;*/
			if(mapit[mp(v1,v2)]==0)
			{
				temp=v1;
				v1=v2;
				v2=temp;
			}
			c1=tin[v1]-mapit[mp(v1,v2)];
			c2=mapit[mp(v1,v2)];
			printf("%lld %lld  %lld %lld\n",v1,v2,c1,c2);
			cit=(c1*c2)*(cont[i]-calc.S);
			c1=(c1*c2)*calc.S;
			newit.pb(mp(cit,i));
			fin.pb(c1);
		}
		sort(newit.begin(),newit.end());
		rep(i,n-1)
		{
			calc=arr[i];
			vit=calc.F;
			v1=newit[i].F;
			v2=newit[i].S;
			if(v1>=0 || k==0)
				break;
			k--;
			fin[v2]+=v1;
		}
		rep(i,n-1)
		{
			ans+=fin[i];
		}
		if(ans<0)
			return 1;
		pln(ans);
	}
	return 0;
}










