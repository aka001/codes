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
#define ll long long
#define MAX 1000006
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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

int main()
{
	double a,b,c,d,e,f,g,h,calc,ans,m,n,o,v1,cit,v2;
	int i,j,k,l;
	ans=mod;
	sd(a); sd(c); sd(d); sd(b);
	calc=a*b-c*d;
	if(calc==0)
	{
		ans=0;
	}
	else
	rep(i,2)
	{
		rep(j,2)
		{
			rep(k,2)
			{
				rep(l,2)
				{
					e=f=g=h=1;
					if(i==0)
						e=-1;
					if(j==0)
						f=-1;
					if(k==0)
						g=-1;
					if(l==0)
						h=-1;
					o=(e*f-(g*h));
					//trace4(e,f,g,h);
					e*=a; f*=b; g*=c; h*=d;
					m=(e+f-(g+h));
					n=a*b-c*d;
					if(o==0)
					{
						calc=(-n)/m;
						calc=abs(calc);
						ans=min(ans,calc);
						//trace6(e,f,g,h,ans,"=================");
					}
					else
					{
						calc=m*m-4*o*n; 
						if(calc<0)
							continue;
						calc=sqrt(calc);
						calc/=(2*o);
						cit=((-m)/(2*o));
						v1=cit+calc;
						v2=cit-calc;
						
						//trace6(e,f,g,h,ans,o);
						ans=min(ans,abs(v1));
						ans=min(ans,abs(v2));
						//trace5(o,m,n,ans,v2);
					}
				}
			}
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}













