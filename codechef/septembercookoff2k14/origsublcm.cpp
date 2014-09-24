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
int isprime[1000006],prm[1000006],cnt=0;
vector<int> fact[1000006];
void seive()
{
	int i,j;
	int MAX=1000006;
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
	{
		fact[i].pb(2);
		isprime[i] = 1; 
	}
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			j=2*i;
			for (; j < MAX; j += i)
			{
				isprime[j] = 1; 
				fact[j].pb(i);
			}
		}
	}
	for(i=2;i<MAX;i++)
	{
		if(!isprime[i])
		{
			fact[i].pb(i);
			prm[cnt++]=i;
		}
	}
}
int in()
{
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&(c!='b')&&(c!='-'));
	bool flag=(c=='-');
	if(flag) c=getchar();
	int x=0;
	while(c>='0'&&c<='9') {
		x=x*10+c-48;
		c=getchar();
	}
	return flag?-x:x;
}
void out(long long int x)
{
	if(x<0) {
		putchar('-');
		x=-x;
	}
	int len=0,data[15];
	while(x) {
		data[len++]=x%10;
		x/=10;
	}
	if(!len)
		data[len++]=0;
	while(len--) putchar(data[len]+48);
	putchar('\n');
}
int arr[1000006],flagit[1000006],sqr[1000006];
int main()
{
	int t,mx,sum=0,ans,sqrtit,j,i,val,n,sz,val1;
	seive();
	for(i=1;i<=1000000;i++)
		sqr[i]=sqrt(i);
	si(t);
	while(t--)
	{
		sum=0;
		ans=-1;
		si(n);
		n++;
		FOR(i,1,n)
		{
			si(arr[i]);
		}
		rep(i,1000006)
			flagit[i]=0;
		mx=0;
		FOR(i,1,n)
		{
			j=0;
			val=arr[i];
			sz=fact[val].size();
			//printf("val=%d\n",val);
			rep(j,sz)
			{
				val1=fact[val][j];
				//printf("fact=%d\n",val1);
				mx=max(mx,flagit[val1]);
				flagit[val1]=i;
			}
			/*if(i==1)
			{
				sum=1;
			}
			else
			{*/
			sum=i-mx;
		//	}
			//printf("sum=%d mx=%d\n",sum,mx);
			ans=max(ans,sum);
		}
		if(ans==1)
			ans=-1;
		out(ans);
		//pin(ans);
	}
	return 0;
}









