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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

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
vector<int> arr[10007];
int visited[100006],level[1000006],finalit[1000006],high;
void levelit(int lev, int node)
{
	int i,nodeit,sizeit;
	visited[node]=1;
	sizeit=arr[node].size();
	rep(i,sizeit)
	{
		nodeit=arr[node][i];
		if(visited[nodeit]==0)
		{
			//printf("node=%d nodeit=%d\n",node,nodeit);
			level[lev+1]++;
			high=max(high,lev+1);
			visited[nodeit]=1;
			levelit(lev+1,nodeit);
		}
	}
}
int main()
{
	int t,n,val1,val2,sizeit,i,j,low,chance,ans,cnt;
	si(t);
	while(t--)
	{
		rep(i,10001)
			arr[i].clear();
		high=-1;
		ans=0;
		cnt=0;
		chance=0;
		si(n);
		rep(i,10001)
		{
			level[i]=0;
			visited[i]=0;
		}
		rep(i,n-1)
		{
			si(val1);
			si(val2);
			arr[val1].pb(val2);
			arr[val2].pb(val1);
		}
		level[1]=1;
		high=1;
		visited[1]=1;
		levelit(1,1);
		low=1;
		/*FOR(i,1,n+4)
		{
			if(level[i]==0)
			{
				high=i-1;
				break;
			}
		}*/
		while(cnt<n && low<=high && low>0)
		{
			if(chance==0)
			{
				ans++;
				cnt+=level[low];
				level[low]=0;
				low++;
			}
			else if(chance==1)
			{
				ans++;
				cnt+=1;
				level[high]--;
				if(level[high]==0)
					high--;
			}
			chance+=1;
			chance%=2;
			//printf("ans=%d chance=%d low=%d high=%d cnt=%d\n",ans,chance,low,high,cnt);
		}
		pin(ans);
	}
	return 0;
}











