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
 
long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
				{
					isprime[j] = 1; 
				}
		}
	}
}
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
	if(i.first == j.first)
		return i.second-j.second;
	return i.first-j.first;
}
map<int, map<int,int> > mymap;
map<int, map<ll,ll> > flag;
vector<pair<int,int> > akash;
int flagrow[1000000],ans[1000000];
int main()
{
	int i,n,m,p,i1,j1,len,n1;
	int calc,calc1;
	si(n);si(m);si(p);
	n1=m-1;
	FOR(i,1,n+1)
		ans[i]=n1;
	rep(i,p)
	{
		si(i1);si(j1);
		mymap[i1][j1]++;
		if(mymap[i1][j1]==1)
			akash.pb(make_pair(i1,j1));
	}
	len=akash.size();
	if(m==1)
	{
		n1=n+1;
		FOR(i,1,n1)
			ans[i]=0;
		FOR(i,1,n1)
			pin(ans[i]);
		return 0;
	}
	rep(i,len)
	{
		i1=akash[i].first;
		j1=akash[i].second;
		calc=mymap[i1][j1];
		if(j1==m)
		{
			if(flagrow[i1]==0)
			{
				ans[i1]+=calc;
			}
		}
		else if(j1==1)
		{
			if(flagrow[i1]==0)
				ans[i1]-=calc;
		}
		if(j1!=m)
		{
			calc1=mymap[i1][j1+1];
			if(calc>calc1+1)
			{
				if(flagrow[i1]==0)
				{
					ans[i1]=-1;
					flagrow[i1]=1;
				}
			}
		}
	}
	n1=n+1;
	FOR(i,1,n1)
		pin(ans[i]);
	return 0;
}







