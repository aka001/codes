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
#define mapit(a) (int)(a + 200)

vector<int> prime;
int arrit[11][100006];
int flag[100006],buffer[1000],isprime[20000];
void seive()
{
	int i,j;
	int MAX=106;
	isprime[0] = isprime[1] = 1;
	prime.pb(2);
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
	for(i=3;i<=100;i++)
		if(!isprime[i])
			prime.pb(i);
}
ll countit(ll numit)
{
	int i,j,k,flageven=1,calc,sizeit,valit;
	ll ansit=0,sum,temp,val,xit=0,lenit;
	lenit=prime.size();
	sizeit=0;
	while(numit!=0)
	{
		buffer[sizeit++]=numit%10;
		numit/=10;
	}
	rep(i,sizeit/2)
	{
		temp=buffer[sizeit-i-1];
		buffer[sizeit-i-1]=buffer[i];
		buffer[i]=temp;
	}
	if(sizeit%2==0)
		flageven=0;
	calc=sizeit;
	//printf("sizeit=%d lenit=%lld prime[lenit-1]=%d\n",sizeit,lenit,prime[lenit-1]);
	//printf("calc=%d sizeit=%d\n",calc,sizeit);
	rep(i,sizeit)
	{
		val=buffer[i];
		calc--;
		rep(j,val)
		{
			rep(k,lenit)
			{
				sum=prime[k]-xit;
				if((i+flageven)%2==0)
				{
					valit=sum-j;
					/*if(arrit[calc][mapit(valit)])
						printf("1it j=%d arrit[%d][%d]=%d\n",j,calc,valit,arrit[calc][mapit(valit)]);*/
					ansit+=arrit[calc][mapit(valit)];
				}
				else if((i+flageven)%2==1)
				{
					//printf("hie\n");
					//printf("j+sum=%lld\n",j+sum);
					/*if(arrit[calc][mapit(j+sum)])
						printf("2it j=%d arrit[%d][%lld]=%d\n",j,calc,j+sum,arrit[calc][mapit(j+sum)]);*/
					ansit+=arrit[calc][mapit(j+sum)];
				}
				//printf("prime[k]=%d ansit=%lld calc=%lld j=%d\n",prime[k],ansit,calc,j);
			}
		}
		if((i+flageven)%2==0)
			xit+=buffer[i];
		else
			xit-=buffer[i];
	}
	return ansit;
}
int main()
{
	int i,j,flagit=0,k;
	ll t,a,b,sizeit,calc=0,ans,ans1,ans2,sqrtit,sum,cnt;
	seive();
	arrit[0][mapit(0)]=1;
	arrit[1][mapit(0)]=1;
	FOR(i,1,200)
	{
		arrit[1][mapit(i)]=0;
		arrit[0][mapit(i)]=0;
	}
	FOR(i,-200,-9)
	{
		arrit[1][mapit(i)]=0;
		arrit[0][mapit(i)]=0;
	}
	FOR(i,-9,0)
	{
		arrit[1][mapit(i)]=1;
		arrit[0][mapit(i)]=0;
	}
	FOR(i,2,10)
	{
		FOR(j,-50,50)
		{
			FOR(k,0,10)
			{
				if(i%2==0)
					arrit[i][mapit(j)]+=arrit[i-1][mapit(j-k)];
				else if(i%2==1)
					arrit[i][mapit(j)]+=arrit[i-1][mapit(j+k)];
			}
		}
	}
	/*printf("2 %d\n",arrit[4][mapit(2)]);
	printf("3 %d\n",arrit[4][mapit(3)]);
	printf("5 %d\n",arrit[4][mapit(5)]);
	printf("7 %d\n",arrit[4][mapit(7)]);
	printf("11 %d\n",arrit[4][mapit(11)]);
	printf("13 %d\n",arrit[4][mapit(13)]);
	printf("17 %d\n",arrit[4][mapit(17)]);
	printf("19 %d\n",arrit[4][mapit(19)]);

	ans=arrit[4][mapit(2)] + arrit[4][mapit(3)] + arrit[4][mapit(5)] + arrit[4][mapit(7)] + arrit[4][mapit(11)] + arrit[4][mapit(13)] + arrit[4][mapit(17)] + arrit[4][mapit(19)];
	pln(ans);*/
	sl(t);
	while(t--)
	{
		sl(a);
		sl(b);
		if(a>b)
		{
			printf("0\n");
			continue;
		}
		ans1=countit(b+1);
		ans2=countit(a);
		/*calc=b;
		sum=0;
		cnt=0;
		while(calc!=0)
		{
			if(cnt%2==0)
				sum-=calc%10;
			else
				sum+=calc%10;
			calc/=10;
		}*/
		//printf("ans1=%lld ans2=%lld\n",ans1,ans2);

		ans=ans1-ans2;
		/*if(sum>=0 && isprime[sum]==0)
			ans++;
		pln(sum);*/
		pln(ans);
	}
	return 0;
}














