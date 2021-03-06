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
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll arr[1000006], mat[5][5], d;
ll modpow(ll n)
{
	ll res[5][5],i,j,calc,k,c[5][5];
	rep(i,4)
		rep(j,4)
			res[i][j]=0;
	res[0][0]=res[1][1]=res[2][2]=res[3][3]=1;
	//trace1(n);
	while(n>0)
	{
		if(n%2==1)
		{
			for(i=0;i<4;++i)
			{
				for(j=0;j<4;++j)
				{
					c[i][j]=0;
					for(k=0;k<4;++k)
					{
						c[i][j]=c[i][j]+(res[i][k]*mat[k][j]);
						c[i][j]%=mod;
					}
				}
			}
			rep(i,4)
				rep(j,4)
				{
					res[i][j]=c[i][j];
					res[i][j]%=mod;
				}
		}
		rep(i,4)
		{
			rep(j,4)
			{
				c[i][j]=0;
				rep(k,4)
				{
					c[i][j]=c[i][j]+(mat[i][k]*mat[k][j]);
					c[i][j]%=mod;
				}
			}
		}
		rep(i,4)
			rep(j,4)
			{
				mat[i][j]=c[i][j];
				mat[i][j]%=mod;
			}
		n/=2;
	}
	rep(i,4)
		rep(j,4)
		{
			mat[i][j]=res[i][j];
			mat[i][j]%=mod;
		}
	/*rep(i,4)
	{
		rep(j,4)
			printf("%lld ",mat[i][j]);
		printf("\n");
	}*/
	calc=mat[0][0]*arr[3]+mat[0][1]*arr[2]+mat[0][2]*arr[1]+mat[0][3]*d;
	calc%=mod;
	return calc;
}
int main()
{
	ll t,n,i,ans,j,n1,a,b,c;
	sl(t);
	while(t--)
	{
		sl(a);
		sl(b);
		sl(c);
		sl(d);
		sl(arr[1]);
		sl(arr[2]);
		sl(arr[3]);
		sl(n);
		rep(i,4)
			rep(j,4)
			mat[i][j]=0;
		mat[0][0]=a;mat[0][1]=b;mat[0][2]=c;mat[0][3]=1;
		mat[1][0]=1;mat[2][1]=1;mat[3][3]=1;

		n1=n-3;
		/*rep(i,4)
		{
			rep(j,4)
				printf("%lld ",mat[i][j]);
			printf("\n");
		}*/
		if(n1<=0)
			pln(arr[n]);
		else
		{
			ans=modpow(n1);
			pln(ans);
		}
	}
	return 0;
}













