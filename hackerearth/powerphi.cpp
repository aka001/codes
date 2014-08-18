/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

struct node
{
	ll a,b,c,d;
};
ll findpower(ll n,node arr)
{
	node res,temp;
	res.a=1;res.b=0;res.c=1;res.d=0;
	while(n!=0)
	{
		if(n&01)
		{
			temp.a=res.a*arr.a+res.b*arr.c;
			temp.b=res.a*arr.b+res.b*arr.d;
			temp.c=res.c*arr.a+res.d*arr.c;
			temp.d=res.c*arr.b+res.d*arr.d;
			if(temp.a>=mod)
				temp.a%=mod;
			if(temp.b>=mod)
				temp.b%=mod;
			if(temp.c>=mod)
				temp.c%=mod;
			if(temp.d>=mod)
				temp.d%=mod;
			res=temp;
		}
		temp.a=arr.a*arr.a+arr.b*arr.c;
		temp.b=arr.a*arr.b+arr.b*arr.d;
		temp.c=arr.c*arr.a+arr.d*arr.c;
		temp.d=arr.c*arr.b+arr.d*arr.d;
		if(temp.a>=mod)
			temp.a%=mod;
		if(temp.b>=mod)
			temp.b%=mod;
		if(temp.c>=mod)
			temp.c%=mod;
		if(temp.d>=mod)
			temp.d%=mod;
		arr=temp;
		n>>=1;
	}
	return res.a;
}
int main()
{
	int t;
	ll n,val;
	si(t);
	while(t--)
	{
		sl(n);
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("2\n");
		else
		{
			node arr;
			arr.a=1;
			arr.b=1;
			arr.c=1;
			arr.d=0;
			val=findpower(n,arr);
			pln(val);
		}
		/*else if(n==1)
			printf("2\n");
		else if(n==2)
			printf("3\n");
		else
		{
			node arr;
			arr.a=1;
			arr.b=1;
			arr.c=1;
			arr.d=0;
			n--;
			val=findpower(n,arr);
			val1=modpow(5,mod-1,mod);
			val=(val*sqrt(5))/val1;
			val=round(val);	
			ans=(ll)val;
			ans%=mod;
			pln(ans);
		}*/
	}
	return 0;
}

















