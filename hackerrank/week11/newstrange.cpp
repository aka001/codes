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
ll arr[10000007],cnt,up;
inline ll cntit(ll n)
{
	ll ct=0;
	while(n!=0)
	{
		ct++;
		n/=10;
	}
	return ct;
}
ll solve(ll n)
{
	ll low=0,high=up-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]<=n && (mid==cnt-1 || arr[mid+1]>n))
			return mid+1;
		else if(n>=arr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	ll i,calc,calc1,sv,MAX,t,l,r,val,flag=0;
	MAX=(ll)mod*(ll)mod;
	FOR(i,0,10)
		arr[i]=i;
	cnt=4;
	up=10;
	while(1)
	{
		val=arr[cnt];
		calc=2;
		while(calc<=18)
		{
			calc1=val*calc;
			if(calc1>=MAX)
			{
				flag=1;
				break;
			}
			sv=cntit(calc1);
			if(sv==calc)
			{
				//printf("up=%lld\n",up);
				//printf("val=%lld calc1=%lld up=%lld\n",val,calc1,up);
				arr[up++]=calc1;
			}
			else if(sv<calc)
				break;
			calc++;
		}
		if(arr[up-1]>=MAX || flag==1)
			break;
		cnt++;
	}
	sort(arr,arr+up);
	sl(t);
	while(t--)
	{
		sl(l);
		sl(r);
		calc=solve(l-1);
		if(calc==-1)
			calc=0;
		calc1=solve(r);
		if(calc1==-1)
			calc1=0;
		calc1-=calc;
		pln(calc1);
	}
	return 0;
}











