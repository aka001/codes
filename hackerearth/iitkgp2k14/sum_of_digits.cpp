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
ll arr[100000],arr1[100000];
int main()
{
	ll left=0,right=0,sum,carry,cnt,n,i,temp,cnt1,sizeit,j;
	sl(n);
	char ch;
	ch=getchar();
	ch=getchar();
	cnt=0;
	while(ch!='\n' && ch!=' ' && ch!='\0')
	{
		arr[cnt++]=ch-'0';
		left+=arr[cnt-1];
		ch=getchar();
	}
	rep(i,cnt/2)
	{
		temp=arr[i];
		arr[i]=arr[cnt-i-1];
		arr[temp-i-1]=temp;
	}
	//printf("left=%lld cnt=%lld arr=%lld\n",left,cnt,arr[0]);
	//left%=9;
	cnt1=cnt;
	rep(j,n-1)
	{
		cnt=0;
		ch=getchar();
		while(ch!='\n' && ch!=' ' && ch!='\0')
		{
			arr1[cnt++]=ch-'0';
			left+=arr1[cnt-1];
			//printf("arr=%lld left=%lld\n",arr1[cnt-1],left);
			ch=getchar();
		}
		rep(i,cnt/2)
		{
			temp=arr[i];
			arr[i]=arr[cnt-i-1];
			arr[temp-i-1]=temp;
		}
		sizeit=min(cnt,cnt1);
		cnt1=max(cnt,cnt1);
		carry=0;
		rep(i,cnt1+1)
		{
			sum=arr[i]+arr1[i]+carry;
			carry=sum/10;
			sum=sum%10;
			arr[i]=sum;
		}
		//printf("left=%lld right=%lld\n",left,right);
		left%=9;
	}
	rep(i,cnt1+1)
	{
		right+=arr[i];
	}
	//printf("left=%lld right=%lld\n",left,right);
	right%=9;
	left-=right;
	pln(left);
	return 0;
}










