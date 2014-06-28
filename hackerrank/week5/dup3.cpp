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
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
typedef struct node
{
	int val,color;
}node;
typedef struct nodeit
{
	int redbef,redaft,nodbef,nodaft;
}nodeit;
vector<node> arr[100001];
nodeit str[100001];
int visited[100001],strt;
int bfs(int nod, int redbef, int vert)
{
	if(visited[vert]==0)
	{
		strt=vert;
		int i,sizeit;
		visited[vert]=1;
		str[vert].redbef=redbef;
		str[vert].nodbef=nod;
		sizeit=arr[vert].size();
		rep(i,sizeit)
		{
			if(arr[vert][i].color==1)
				bfs(nod+1,redbef+1,arr[vert][i].val);
			else
				bfs(nod+1,redbef,arr[vert][i].val);
		}
	}
}
int bfsnew(int nod, int redbef, int vert)
{
	if(visited[vert]==0)
	{
		//printf("vert=%d\n",vert);
		int i,sizeit;
		visited[vert]=1;
		str[vert].redaft=redbef;
		str[vert].nodaft=nod;
		sizeit=arr[vert].size();
		rep(i,sizeit)
		{
			//printf("vert=%d i=%d sizeit=%d\n",vert,arr[vert][i].val,sizeit);
			if(arr[vert][i].color==1)
			{
				bfsnew(nod+1,redbef+1,arr[vert][i].val);
			}
			else
			{
				bfsnew(nod+1,redbef,arr[vert][i].val);
			}
		}
	}
}
int main()
{
	int n,i,e1,e2,col,sizeit,flag=0,valit;
	ll calc;
	si(n);
	rep(i,100001)
		visited[i]=0;
	rep(i,n)
	{
		si(e1);si(e2);si(col);
		if(flag==0)
		{
			strt=e1;
			flag=1;
		}
		node temp;
		temp.val=e2;
		temp.color=col;
		arr[e1].pb(temp);
		temp.val=e1;
		arr[e2].pb(temp);
	}
	valit=arr[5].size();
	bfs(0,0,strt);
	rep(i,100001)
		visited[i]=0;
	//printf("strnew=%d\n",strt);
	bfsnew(0,0,strt);
	rep(i,100001)
	{
		if(str[i].redbef!=0 && str[i].
	}
	rep(i,10)
	{
		//printf("i=%d nodebef=%d nodeaft=%d redbef=%d redaft=%d\n",i,str[i].nodbef,str[i].nodaft,str[i].redbef,str[i].redaft);
	}
	return 0;
}












