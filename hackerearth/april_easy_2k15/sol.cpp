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
#include<stdio.h>
#include<math.h>
#include<cassert>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

vector<pair<ll,ll> > arr,brr;
vector<ll> bin;
void modify()
{
	ll i,sz,a,b,tp=0;
	brr.pb(arr[0]);
	sz=arr.size();
	FOR(i,1,sz)
	{
		a=arr[i].F;
		b=arr[i].S;
		if(a>brr[tp].S)
		{
			tp++;
			brr.pb(mp(a,b));
		}
		else
		{
			brr[tp].S=max(brr[tp].S,b);
		}
	}
}
ll binary(ll sz, ll val)
{
	ll low=0,high=sz,mid,calc;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(bin[mid]<val && (mid==sz || bin[mid+1]>=val))
		{
			if(mid==sz)
				return -1;
			else
			{
				calc=val-bin[mid];
				return brr[mid].F+calc-1;
			}
		}
		else if(val>bin[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	ll t,n,q,a,b,sz,i,calc,k,cit;
	cit=-1000000000000000000;
	sl(t);
	assert(t>=1 && t<=100);
	while(t--)
	{
		arr.clear();
		brr.clear();
		bin.clear();
		sl(n);
		sl(q);
		assert(n>=1 && n<=100);
		assert(q>=1 && q<=1000);
		rep(i,n)
		{
			sl(a);
			sl(b);
			assert(a>=cit && a<=-cit);
			assert(b>=cit && b<=-cit);
			arr.pb(mp(a,b));
		}
		sort(arr.begin(),arr.end());
		modify();
		sz=brr.size();
		bin.pb(0);
		rep(i,sz)
		{
			calc=brr[i].S-brr[i].F+1+bin[i];
			bin.pb(calc);
		}
		rep(i,q)
		{
			sl(k);
			calc=binary(sz,k);
			pln(calc);
		}
	}
	return 0;
}














