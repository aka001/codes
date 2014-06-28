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

int compare(const void *a, const void *b)
{
	return (*(float*)a - *(float*)b);
}
int main()
{
	int n,i,j,sizeit,cnt=1,maxit=-1,pointer,t,flag=0,flagit=0;
	float slope,a,b,x[3000],y[3000],store[3000];
	si(t);
	while(t--)
	{
		cnt=2;
		maxit=1;
		si(n);
		rep(i,n)
		{
			scanf("%f",&x[i]);
			scanf("%f",&y[i]);
		}
		rep(i,n)
		{
			cnt=1;
			sizeit=0;
			if(maxit>=n-i)
				break;
			FOR(j,i+1,n)
			{
				if(j!=i)
				{
					if(x[j]-x[i]==0)
						slope=5.667;
					else
						slope=(y[j]-y[i])/(x[j]-x[i]);
					store[sizeit++]=slope;
				}
			}
			sort(store,store+sizeit);
			//qsort(store,sizeit,sizeof(float),compare);
			pointer=0;
			j=1;
			if(maxit>sizeit)
				continue;
			while(j<sizeit)
			{
				if(store[pointer]!=store[j])
				{
					maxit=max(cnt,maxit);
					pointer=j;
					cnt=1;
				}
				else
				{
					cnt++;
				}
				j++;
			}
			maxit=max(maxit,cnt);
		}
		pin(maxit);
	}
	return 0;
}









