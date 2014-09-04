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

vector<ll> arr;
int main()
{
	ll val,minit=(ll)mod*(ll)mod,count1=0,count2=0,cnt1=1,cnt2=1,i,calc,n,calc2=0,cp=0;
	sl(n);
	rep(i,n)
	{
		sl(val);
		arr.pb(val);
	}
	sort(arr.begin(),arr.end());
	for(i=1;i<n;i++)
	{
		calc=arr[i]-arr[i-1];
		minit=min(minit,calc);
	}
	cp=1;
	for(i=1;i<n;i++)
	{
		calc=arr[i]-arr[i-1];
		if(calc==minit)
		{
			//printf("i=%lld\n",i);
			count1++;
		}
		if(minit==0 && calc==minit)
		{
			cp++;
		}
		else if(calc!=minit)
		{
			//printf("calc=%lld minit=%lld\n",calc,minit);
			calc2+=(cp*(cp-1))/2;
			cp=1;
		}
	}
	if(minit==0)
	{
		calc2+=(cp*(cp-1))/2;
		count1=calc2;
	}
	val=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]==val)
		{
			cnt1++;
		}
	}
	val=arr[n-1];
	for(i=n-2;i>=0;i--)
	{
		if(arr[i]==val)
			cnt2++;
	}
	if(arr[0]==arr[n-1])
	{
		count2=(cnt1*(cnt1-1))/2;
	}
	else
	{
		count2=cnt1*cnt2;
	}
	printf("%lld %lld\n",count1,count2);
	return 0;
}












