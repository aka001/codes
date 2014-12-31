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

int main()
{
	int n,i,a,b,c,d,temp,x,y,val;
	double calc,calc1,calc2;
	si(n);
	if(n==0)
	{
		printf("YES\n1\n1\n3\n3\n");
	}
	else if(n==1)
	{
		si(val);
		printf("YES\n%d\n%d\n%d\n",val,3*val,3*val);
	}
	else if(n==2)
	{
		si(a);
		si(b);
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		x=4*a-b;
		y=3*a;
		printf("YES\n%d\n%d\n",x,y);
	}
	else if(n==3)
	{
		vector<int> arr;
		rep(i,3)
		{
			si(val);
			arr.pb(val);
		}
		sort(arr.begin(),arr.end());
		a=arr[0];
		b=arr[1];
		c=arr[2];
		if((b+c-4*a)==0)
		{
			x=(b+c+2*a)/2;
			printf("YES\n%d\n",x);
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		vector<int> arr;
		rep(i,4)
		{
			si(val);
			arr.pb(val);
		}
		sort(arr.begin(),arr.end());
		a=arr[0];
		b=arr[1];
		c=arr[2];
		d=arr[3];
		calc=(a+b+c+d)/4.0;
		calc1=(b+c)/2.0;
		calc2=d-a;
		if(calc==calc1 && calc1==calc2)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}








