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
double ans[102][32769];
int main()
{
	int t,i,j,k,n,calc,a,b;
	double fin,p;
	memset(ans,1,sizeof(ans));
	si(t);
	while(t--)
	{
		si(n);
		rep(i,n)
		{
			sd(p);
			si(a);
			si(b);
			calc=1<<a;
			if(i!=0)
			{
				rep(k,2)
				rep(j,32768)
				{
					if(j&(1<<a)!=0 && ans[i-1][j][k]!=1)
					{
						printf("i=%d j=%d  %lf\n",i,j,ans[i-1][j][k]);
						ans[i][j|(1<<a)][0]+=(p*ans[i-1][j][k])/100.0;
					}
				}
				rep(k,2)
				rep(j,32768)
				{
					if(j&(1<<a)!=0)
						ans[i][j|(1<<a)][1]=(p*ans[i-1][j][k])/100.0;
				}
			}
			else
			{
				ans[i][a][0]=(p/100.0);
				ans[i][b][1]=(p/100.0);
			}
		}
		rep(i,32768)
			if(ans[n-1][i][0]!=1)
				fin+=ans[n-1][i][0];
			if(ans[n-1][i][1]!=1)
				fin+=ans[n-1][i][1];
		printf("%lf\n",fin);
	}
	return 0;
}







