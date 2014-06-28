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
vector<int> primes;
vector<int> actual;
vector<int> dummy;
int position[1000000];
int distanceit[1000000];
void seive()
{
	int i,j;
	int MAX=1000001;
	int isprime[1000001];
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
	rep(i,1000001)
	{
		if(isprime[i]==0)
		{
			primes.pb(i);
		}
	}
}
vector<pair<int,int> > answer;
int flag[1000000];
int main()
{
	int n,i,len,st,end,pos,pos1,temp,cnt=0,val,lenit,low,high,mid;
	seive();
	st=0;
	end=1;
	distanceit[0]=0;
	distanceit[1]=0;
	len=primes.size();
	for(i=2;i<100001;i++)
	{
		if(i>=primes[st] && i<primes[end])
		{
			distanceit[i]=st;
		}
		else
		{
			distanceit[i]=end;
			st=end;
			end++;
		}
	}
	lenit=primes.size();
	si(n);
	rep(i,n)
	{
		int val;
		si(val);
		actual.pb(val);
		dummy.pb(val);
		position[val]=i;
	}
	sort(dummy.begin(),dummy.end());
	rep(i,n)
	{
		pos=position[dummy[i]];
		while(pos!=i && cnt<=5*n)
		{
			pos=position[dummy[i]];
			val=distanceit[position[dummy[i]]+1];
			while(1)
			{
				pos1=pos+1-primes[val];
				if(flag[pos1]==0)
					break;
				val--;
			}
			temp=actual[pos];
			actual[pos]=actual[pos1];
			actual[pos1]=temp;
			position[dummy[i]]=pos1;
			position[actual[pos]]=pos;
			answer.pb(make_pair(pos1,pos));
			pos=pos1;
			cnt++;
		}
		flag[i]=1;
	}
	len=answer.size();
	pin(len);
	rep(i,len)
	{
		printf("%d %d\n",answer[i].first+1,answer[i].second+1);
	}
	return 0;
}









