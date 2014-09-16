

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
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
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
#define pil(n) printf("%d\n",n)
#define pll(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (ll)(1e9 + 7)
#define ll long long int

int main()
{
	ll n,a,b,low,high,mid,area=(ll)mod*(ll)mod,ans1,ans2,calc,calc1,val,flagit=0,low1,calc2,flagit1=0,temp;
	sl(n);
	sl(a);
	sl(b);
	calc=6*n;
	if(a*b>=calc)
	{
		printf("%lld\n%lld %lld\n",a*b,a,b);
		return 0;
	}
	if(b<a)
	{
		temp=a;
		a=b;
		b=temp;
		flagit1=1;
	}
	calc1=calc;
	val=a;
	calc2=sqrt(6*n);
	calc2++;
	while(val<=calc2)
	{
		low1=b;
		low=b;
		high=mod;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(val*mid>=calc1 && val*(mid-1)<calc1)
			{
				if(val*mid<area)
				{
					//printf("area=%lld val*mid=%lld ans1=%lld ans2=%lld\n",area,val*mid,val,mid);
					area=val*mid;
					ans1=val;
					ans2=mid;
				}
				flagit=1;
				break;
			}
			else if(val*mid>calc1)
				high=mid-1;
			else
				low=mid+1;
		}
		val++;
		if(val*low1>calc)
			break;
	}
	if(flagit1==0)
		printf("%lld\n%lld %lld\n",area,ans1,ans2);
	else
		printf("%lld\n%lld %lld\n",area,ans2,ans1);
	return 0;
}








