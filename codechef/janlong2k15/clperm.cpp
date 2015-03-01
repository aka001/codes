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
#include<cassert>
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
ll arr[1000006];
inline ll calcit(ll n)
{
	ll c=(n*(n+1))/2;
	return c;
}
int main()
{
	ll t,n,k,flag,calc,v1,l,u,nl,nu,i,sum;
	sl(t);
	while(t--)
	{
		sl(n);
		sl(k);
		if(k==0)
		{
			calc=(n*(n+1))/2;
			calc++;
		}
		else
		{
			rep(i,k)
			{
				sl(arr[i]);
			}
			arr[k]=n+1;
			sort(arr,arr+k+1);
			if(arr[0]==1)
			{
				calc=1;
			}
			else
			{
				l=1;
				sum=calcit(arr[0]-1);
				u=sum;
				//printf("l=%lld u=%lld k=%lld\n",l,u,k);
				flag=0;
				FOR(i,0,k)
				{
					/*if(i==k-1)
					{
						
					}
					else*/
					{
						if(arr[i+1]<=arr[i]+1)
							continue;
						//printf("%lld %lld\n",arr[i+1],arr[i]);
						nl=arr[i]+1;
						v1=calcit(arr[i+1]-1)-calcit(nl-1);
						nu=v1+sum;
						//printf("nl=%lld nu=%lld  v1=%lld sum=%lld\n",nl,nu,v1,sum);
						sum+=v1;
						if(nl>u+1)
						{
							calc=u+1;
							flag=1;
							break;
						}
						l=nl;
						u=nu;
					}
				}
				if(flag==0)
				{
					calc=u+1;
				}
			}
		}
		if(calc<0)
			assert(-1>0);
		//pln(calc);
		if(calc%2==0)
			printf("Mom\n");
		else
			printf("Chef\n");
	}
	return 0;
}
















