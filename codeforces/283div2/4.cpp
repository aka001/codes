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
int c[4],n;
int binary(int arr[],int val)
{
	int l=0,h=n-1,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(arr[mid]==val && (mid==0 || arr[mid-1]<val))
			return mid;
		else if(arr[mid]>=val)
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}
int main()
{
	int sq,i;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
		c[arr[i]]++;
		if(i==0)
		{
			x[i]=(arr[i]==1);
			y[i]=(arr[i]==2);
		}
		else
		{
			x[i]=x[i-1]+(arr[i]==1);
			y[i]=y[i-1]+(arr[i]==2);
		}
		c[arr[i]]++;
	}
	calc=c[arr[n-1]];
	sq=sqrt(calc);

	return 0;
}












