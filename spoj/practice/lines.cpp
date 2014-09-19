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
#define FOR(i,a,b) for(int i= a ; i < b ; ++i)
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
int main()
{
	int n,i,j,ans=0;
	double x,y,m,x1,y1,x2,y2;
	si(n);
	while(n!=0)
	{
		ans=0;
		map<double,int> mapit;
		vector< pair<double,double> > values;
		rep(i,n)
		{
			sd(x);
			sd(y);
			values.pb(mp(x,y));
		}
		rep(i,n)
		{
			x1=values[i].first;
			y1=values[i].second;
			FOR(j,i+1,n)
			{
				x2=values[j].first;
				y2=values[j].second;
				if(x1==x2)
					m=mod;
				else
					m=(y2-y1)/((x2-x1)*1.0);
				if(mapit[m]==0)
				{
					//printf("i=%d j=%d m=%lf\n",i,j,m);
					ans++;
				}
				mapit[m]++;
			}
		}
		printf("%d\n",ans);
		si(n);
	}
	return 0;
}










