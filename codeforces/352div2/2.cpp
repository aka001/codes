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
int flg[100002];
vector<int> value;
vector<int> position[100002];
int valid[100002];
vector<pair<int,int> > answer;
int main()
{
	int i,n,sizeit,val,size1,calc,flag,diffit1,j,diffit;
	si(n);
	rep(i,n)
	{
		si(val);
		flg[val]++;
		if(flg[val]==1)
			value.pb(val);
		position[val].pb(i);
	}
	sort(value.begin(),value.end());
	sizeit=value.size();
	rep(i,sizeit)
	{
		val=value[i];
		sort(position[val].begin(), position[val].end());
		size1=position[val].size();
		if(size1==1)
		{
			answer.pb(make_pair(val,0));
			continue;
		}
		diffit=position[val][1]-position[val][0];
		if(size1==2)
		{
			answer.pb(make_pair(val,diffit));
			continue;
		}
		flag=1;
		calc=position[val][1];
		FOR(j,2,size1)
		{
			diffit1=position[val][j]-calc;
			if(diffit1!=diffit)
			{
				flag=0;
				break;
			}
			calc=position[val][j];
		}
		if(flag==1)
			answer.pb(make_pair(val,diffit));
	}
	sizeit=answer.size();
	pin(sizeit);
	rep(i,sizeit)
	{
		printf("%d %d\n",answer[i].first,answer[i].second);
	}
	return 0;
}











