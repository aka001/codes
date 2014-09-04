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

ll arr[100][100],fact[100];
int main()
{
	ll t,i,j,ans=1,n,m,cnt=0,calc,calc1,k,n1,m1;
	fact[0]=1;
	FOR(i,1,25)
	{
		fact[i]=ans;
		ans=ans*(i+1);
	}
	FOR(i,0,21)
	{
		FOR(j,0,i+1)
		{
			arr[i][j]=fact[i]/(fact[j]*fact[i-j]);
		}
	}
	sl(t);
	while(t--)
	{
		sl(n);
		sl(m);
		sl(k);
		n1=n;
		m1=m;
		k++;
		cnt=0;
		while(cnt<n1+m1)
		{
			if(n!=0)
				calc=fact[n+m-1]/((fact[n-1])*(fact[m]));
			if(m!=0)
				calc1=fact[n+m-1]/((fact[n])*(fact[m-1]));
			//printf("n=%lld m=%lld k=%lld calc=%lld calc1=%lld\n",n,m,k,calc,calc1);
			if(n==0)
			{
				printf("V");
				m--;
				cnt++;
				continue;
			}
			else if(m==0)
			{
				printf("H");
				n--;
				cnt++;
				continue;
			}
			if(k>calc)
			{
				k-=calc;
				printf("V");
				m--;
			}
			else
			{
				printf("H");
				n--;
			}
			//printf("k=%lld\n",k);
			cnt++;
		}
		printf("\n");
	}
	return 0;
}















