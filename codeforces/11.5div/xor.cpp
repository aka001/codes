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

vector<vector<int> > akash;
int visited[300000];
int init[300000];
int goal[300000];
int cnt=0;
vector<int> answer;
void definelevel(int value,int level,int even_times,int odd_times)
{
	int len,i,times,valit,val,flag=0;
	visited[value]=1;
	len=akash[value].size();
	rep(i,len)
	{
		valit=akash[value][i];
		if(visited[valit]==0)
		{
			visited[valit]=1;
			if((level+1)&01)
			{
				flag=1;
				times=odd_times;
			}
			else
				times=even_times;
			val=(init[valit]+times)%2;
			init[valit]=val;
			if(init[valit]!=goal[valit])
			{
				answer.pb(valit);
				if(flag)
					definelevel(valit,level+1,even_times, odd_times+1);
				else
					definelevel(valit,level+1,even_times+1, odd_times);
			}
			else
			{
				definelevel(valit,level+1,even_times,odd_times);
			}
		}
	}
}
int main()
{
	int n,u,v,initit,goalit,lev,i;
	si(n);
	FOR(i,1,1000000)
		akash.pb(vector<int>());
	rep(i,n-1)
	{
		si(u);si(v);
		akash[u].pb(v);
		akash[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		si(initit);
		init[i]=initit;
	}
	for(i=1;i<=n;i++)
	{
		si(goalit);
		goal[i]=goalit;
	}
	if(init[1]!=goal[1])
	{
		answer.pb(1);
		definelevel(1,0,1,0);
	}
	else
	{
		definelevel(1,0,0,0);
	}
	lev=answer.size();
	pin(lev);
	rep(i,lev)
		pin(answer[i]);

	/*garb=akash.size();
	printf("length of array:%d\n",garb);
	FOR(i,1,garb+1)
	{
		printf("%d->",i);
		garb1=akash[i].size();
		FOR(j,0,garb1)
		{
			printf("%d ",akash[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}













