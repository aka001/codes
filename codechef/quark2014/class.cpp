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
char ch[10009];
int main()
{
	ll t,h,m,s,calc,hr,mi,c,i;
	sl(t);
	while(t--)
	{
		char ans[1000];
		rep(i,4)
		{
			ans[i]='0';
		}
		ss(ch);
		sl(s);
		h=10*(ch[0]-'0')+(ch[1]-'0');
		m=10*(ch[2]-'0')+(ch[3]-'0');
		calc=h*3600+m*60+s;
		hr=calc/3600;
		hr%=24;
		calc%=3600;
		mi=calc/60;
		calc%=60;
		if(calc>0)
			mi++;
		hr+=(mi/60);
		hr%=24;
		mi%=60;
		c=0;
		//pln(hr);
		//pln(mi);
		while(hr!=0)
		{
			ch[2+c]=(hr%10+'0');
			hr/=10;
			c++;
		}
		c=0;
		while(mi!=0)
		{
			ch[c++]=(mi%10+'0');
			mi/=10;
		}
		for(i=3;i>=0;i--)
			cout<<ch[i];
		cout<<endl;
	}
	return 0;
}












