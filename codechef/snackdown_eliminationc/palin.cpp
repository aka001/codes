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
#define mini 100005
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
char ch[MAX];
vector<ll> arr[26];
ll brr[26][mini];
ll upperit(ll x, ll ind)
{
	int low=0, high=arr[ind].size()-1,mid, sz=arr[ind].size()-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[ind][mid]>=x && (mid==0 || arr[ind][mid-1]<x))
			return mid;
		else if(arr[ind][mid]>=x)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
ll lowerit(ll x, ll ind)
{
	int low=0, high=arr[ind].size()-1,mid, sz=arr[ind].size()-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[ind][mid]<=x && (mid==sz || arr[ind][mid+1]>x))
			return mid;
		else if(arr[ind][mid]<=x)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	ll i,sz,j,k,l,i1,j1,k1,l1,lit,q,sit,m,pit,calc,cit,l2,k2,i2,j2,c1,c2,k3,l3;
	pair<ll,ll> r1;
	ss(ch);
	sz=strlen(ch);
	rep(i,sz)
	{
		arr[ch[i]-'a'].pb(i+1);
	}
	trace1(1);
	rep(i,26)
	{
		sz=arr[i].size();
		brr[i][0]=0;
		sit=0;
		FOR(j,1,sz+1)
		{
			sit+=arr[i][j-1];
			brr[i][j]=sit;
		}
	}
	sl(q);
	while(q--)
	{
		sl(i); sl(j); sl(k); sl(l);
		lit = j-i+1;
		j2 = min(j,k-1);
		i2 = min(i2, j2);
		k2=k; l2=l;
		rep(m,2)
		{
			i1 = upperit(i2,m); j1 = lowerit(j2,m);
			cit = l+k;
			k3 = cit - j;
			l3 = cit - i;
			k = max(k, k3);
			l = min(l, l3);
			k1 = upperit(k,m); l1 = lowerit(l,m);
			if(i1==-1 && j1==-1 && k1==-1 && l1==-1)
				continue;
			else
			{
				i1++; j1++; k1++; l1++; 
				trace5(m,i2,j2,k,l);
				trace5(m,i1,j1,k1,l1);
				r1.F=i1;
				if(k1==0)
					r1.S=j1;
				else
					r1.S=min(j1,k1-1);
				r1.F = min(r1.F,r1.S);
				pit = l1-k1+1;
				trace6(r1.F, r1.S, k1, l1, k2, l2);
				trace1(pit);
				c1 = brr[m][r1.S] - brr[m][r1.F-1];
				c2 = -(brr[m][k1] - brr[m][l1-1]) + pit*(k2+l2);
				calc = c1 + c2;
				trace4(m,c1,c2,calc);
			}
		}
		trace4(i1,j1,k1,l1);
	}
	return 0;
}













