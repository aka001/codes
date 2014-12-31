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
int check(double a)
{
	double b=(double)((ll)a);
	if(b==a)
		return 1;
	return 0;
}
int main()
{
	int t,ans;
	ll d,p,calc,calc1,calc2,val1,val2,cal1,cal2,cal3,cal4,val3,val4;
	si(t);
	while(t--)
	{
		sl(d);
		sl(p);
		if(d<0)
		{
			printf("0\n");
			continue;
		}
		calc=d*d+4*p;
		if(calc<0)
		{
			printf("0\n");
			continue;
		}
		calc1=sqrt(calc);
		calc2=calc1*calc1;
		if(calc2==calc)
		{
			val1=(-d+calc1)/2.0;
			val2=(-d-calc1)/2.0;
			val3=(d+calc1)/2.0;
			val4=(d-calc1)/2.0;
			cal1=d+val1;
			cal2=d+val2;
			cal3=-d+val3;
			cal4=-d+val4;
			set<pair<int,int> > listit;
			ans=0;
			if(check(val1) && check(cal1))
				listit.insert(mp(val1,cal1));
			if(check(val2) && check(cal2))
				listit.insert(mp(val2,cal2));
			if(check(val3) && check(cal3))
				listit.insert(mp(val3,cal3));
			if(check(val4) && check(cal4))
				listit.insert(mp(val4,cal4));
			//printf("%lf %lf %lf %lf\n",val1,val2,val3,val4);
			ans=listit.size();
			if(ans==3)
				return 1;
			pin(ans);
			/*if(val1==val2)
				printf("1\n");
			else if(val1==-val2)
				printf("2\n");
			else
				printf("4\n");*/
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}








