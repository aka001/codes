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
int arr[101][101],brr[101][101];
int main()
{
	int m,n,i,j,k,x,flag;
	si(m);
	si(n);
	rep(i,m)
	{
		rep(j,n)
			si(arr[i][j]);
	}
	rep(i,m)
		rep(j,n)
			brr[i][j]=-1;
	rep(i,m)
	{
		rep(j,n)
		{
			if(arr[i][j]==0)
			{
				FOR(k,0,n)
					brr[i][k]=0;
				FOR(k,0,m)
					brr[k][j]=0;
			}
			else
			{
				flag=0;
				FOR(k,0,n)
				{
					if(brr[i][k]==1 || brr[i][k]==-1)
					{
						brr[i][k]=1;
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					FOR(k,0,m)
					{
						if(brr[k][j]==1 || brr[k][j]==-1)
						{
							brr[k][j]=1;
							flag=1;
							break;
						}
					}
				}
				if(flag==0)
				{
					//printf("NO %d %d\n",i,j);
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	/*rep(i,m)
	{
		rep(j,n)
		{
			if(arr[i][j])
				brr[i][j]=1;
		}
	}*/
	rep(i,m)
		rep(j,n)
			if(brr[i][j]==-1)
				brr[i][j]=0;
	flag=1;
	rep(i,m)
	{
		rep(j,n)
		{
			x=0;
			FOR(k,0,n)
				x=x|brr[i][k];
			FOR(k,0,m)
				x=x|brr[k][j];
			if(x!=arr[i][j])
			{
				//printf("%d %d\n",i,j);
				flag=0;
				break;
			}
		}
		if(flag==0)
			break;
	}
	if(flag==0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		rep(i,m)
		{
			rep(j,n)
			{
				printf("%d",brr[i][j]);
				if(j!=n-1)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
















