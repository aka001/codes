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
vector<int> nos;
void doit()
{
	int MAX=704977,cubit,i,j,calc,calc1,cnt=0;
	for(i=1;i<=MAX;i++)
	{
		cubit=pow(i,0.33333333);
		cnt=0;
		FOR(j,1,cubit+1)
		{
			calc=i-j*j*j;
			calc1=(int)((double)(pow(calc,0.33333333333)+0.5));
			if(calc1*calc1*calc1==calc)
			{
				cnt++;
				if(cnt>=4)
				{
					nos.pb(i);
					break;
				}
			}
		}
	}
}
int binary(int val)
{
	int low=0,high,mid,sz;
	sz=nos.size();
	high=sz-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(mid==sz-1 || (nos[mid]<=val && nos[mid+1]>val))
			return nos[mid];
		else if(val>=nos[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	int t,n,calc,i,sz;
	nos.pb(1729);
	nos.pb(4104);
	nos.pb(13832);
	nos.pb(20683);
	nos.pb(32832);
	nos.pb(39312);
	nos.pb(40033);
	nos.pb(46683);
	nos.pb(64232);
	nos.pb(65728);
	nos.pb(110656);
	nos.pb(110808);
	nos.pb(134379);
	nos.pb(149389);
	nos.pb(165464);	
	nos.pb(171288);	
	nos.pb(195841);
	nos.pb(216027);
	nos.pb(216125);
	nos.pb(262656);	
	nos.pb(314496);
	nos.pb(320264);
	nos.pb(327763);
	nos.pb(373464);	
	nos.pb(402597);
	nos.pb(439101);
	nos.pb(443889);
	nos.pb(513000);
	nos.pb(513856);
	nos.pb(515375);
	nos.pb(525824);
	nos.pb(558441);	
	nos.pb(593047);	
	nos.pb(684019);	
	nos.pb(704977);	
	sz=nos.size();
	//printf("sz=%d\n",sz);
	si(t);
	while(t--)
	{
		si(n);
		calc=binary(n);
		printf("%d\n",calc);
	}
	return 0;
}
















