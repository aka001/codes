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
int isprime[1000010];
vector<int> prm,sp2;
void seive()
{
	ll i,j,MAX=1000006;
	isprime[0]=1;
	isprime[1]=1;
	isprime[2]=0;
	for(i=4;i<MAX;i+=2)
	{
		isprime[i]=1;
	}
	for(i=3;i<MAX;i+=2)
	{
		if(isprime[i]==0)
		{
			for(j=i*i;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]==0)
			prm.pb(i);
	}
}
int arr[10000][5];
int main()
{
	int t,sz,i,j,n,k,calc,calc1,sqrtit,calc2,val,ans=0,sum,l;
	val=0;
	seive();
	sz=prm.size();
	rep(i,sz)
	{
		calc=prm[i];
		sqrtit=sqrt(calc);
		sqrtit++;
		rep(j,sqrtit)
		{
			calc1=calc-j*j;
			calc2=sqrt(calc1);
			if(calc2*calc2==calc1)
			{
				sp2.pb(prm[i]);
				val++;
				break;
			}
		}
		if(val>=510)
			break;
	}
	sz=sp2.size();
	si(t);
	while(t--)
	{
		si(n);
		si(k);
		n--;
		calc=sp2[n];
		for(i=0;i<=calc+2;i++)
			for(j=0;j<=k;j++)
				arr[i][j]=0;
		ans=0;
		for(i=1;i<=calc;i++)
		{
			for(j=1;j<=k;j++)
			{
				calc1=i-j;
				//printf("i=%d j=%d calc1=%d arr=%d\n",i,j,calc1,arr[i][j]);
				if(calc1<0 || (calc1==0 && i<=k))
					continue;
				sum=0;
				for(l=j;l<=k;l++)
				{
					sum+=arr[calc1][l];
				}
				arr[i][j]=sum;
			}
			if(i<=k)
				arr[i][i]=1;
		}
		for(i=1;i<=k;i++)
			ans+=arr[calc][i];
		pin(ans);

	}
	return 0;
}














