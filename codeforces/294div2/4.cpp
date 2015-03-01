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
vector<ll> arr[30];
char ch[1000006];
ll val[30],calc[1000006];
vector<int> rep;
int main()
{
	ll i,sz,ans=0,cit,c2,low,high,j;
	rep(i,26)
		sl(val[i]);
	ss(ch);
	sz=strlen(ch);
	rep(i,sz)
	{
		arr[ch[i]-'a'].pb(i);
		if(i==0)
			calc[i]=val[ch[i]-'a'];
		else
			calc[i]=val[ch[i]-'a']+calc[i-1];
	}
	rep(i,26)
	{
		sz=arr[i].size();
		rep.clear();
		if(sz==0)
			continue;
		map<int,int> mapit;
		low=arr[i][0];
		//printf("i=%lld low=%lld\n",i,low);
		cit=0;
		FOR(j,1,sz)
		{
			high=arr[i][j];
			cit=calc[high-1]-calc[low];
			if(cit==0)
				ans++;
			if(j==1)
				c2=cit;
			else
				c2=cit-val[i];
			//printf("i=%lld high=%lld cit=%lld c2=%lld\n",i,high,cit,c2);
			rep.pb(c2);
			mapit[c2]++;
		}
		rep.pb(0);
		rep.erase( unique( rep.begin(), rep.end() ), rep.end() );
		sort(rep.begin(),rep.end());
		sz=rep.size();
		rep(j,sz)
		{
			c2=mapit[rep[j]];
			c2--;
			c2=(c2*(c2+1))/2;
			ans+=c2;
		}
		//printf("i=%lld ans=%lld\n",i,ans);
	}
	pln(ans);
	return 0;
}










