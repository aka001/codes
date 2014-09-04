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

int arr[100];
int main()
{
	ll t,calc,akash,val,n,n1,sizeit,sz,temp,t1,flagit=0,small=0,flagit1,i,cnt=0,cnt1=0,cat,val1;
	double mean=0,prob=0,bro,sis;
	sl(t);
	t1=t;
	while(t--)
	{
		flagit=0;
		flagit1=0;
		akash=1;
		val=0;
		small=0;
		sizeit=0;
		cnt=0;
		cnt1=0;

		sl(n);
		if(n==0)
		{
			continue;
		}
		n1=n;
		while(n!=0)
		{
			calc=n%2;
			if(calc==1)
			{
				flagit=1;
			}
			if(calc==1 && flagit1==1)
			{
				val+=akash;
				flagit1=0;
			}
			if(calc==0)
			{
				val+=akash;
				flagit1=1;
				small=1;
			}
			akash<<=1;
			n>>=1;
			sizeit++;
		}
		if(small)
		{
			val=val^n1;
		}
		else
			val=-1;
		sz=0;
		n=n1;
		while(n1!=0)
		{
			arr[sz++]=n1%2;
			n1>>=1;
		}
		/*rep(i,sz/2)
		{
			temp=arr[sz-i-1];
			arr[sz-i-1]=arr[i];
			arr[i]=temp;
		}*/
		flagit1=0;
		flagit=0;
		cat=-1;
		rep(i,sz)
		{
			if(arr[i]==1)
			{
				cnt++;
				flagit1=1;
			}
			if(arr[i]==1 && flagit==0)
				cnt1++;
			if(arr[i]==0 && flagit1==1)
			{
				flagit=1;
				flagit1=0;
				cat=i;
				break;
			}
		}
		//printf("sz=%lld\n",sz);
		//printf("flagit=%d\n",flagit);
		if(flagit==0 && cnt==1)
		{
			val1=modpow(2,sz,mod);
		}
		else
		{
			if(cat==-1)
			{
				//printf("n=%lld\n",n);
				cat=sz;
				sz++;
			}
			akash=1;
			arr[cat]=1;
			cnt1--;
			cnt=0;
			if(cnt1==0)
			{
				rep(i,cat)
					arr[i]=0;
			}
			while(cnt1--)
			{
				arr[cnt++]=1;
			}
			FOR(i,cnt,cat)
				arr[i]=0;
			val1=0;
			rep(i,sz)
			{
				if(arr[i]==1)
					val1+=akash;
				akash<<=1;
			}
		}
		mean+=(val1-val);
		if(val==-1 || val1==-1)
		{
			prob+=0;
		}
		else
		{
			bro=n/(val*1.0);
			sis=val1/(n*1.0);
			//printf("%lf %lf %lld\n",bro,sis,n);
			if(bro==sis)
				prob+=1;
		}
	}
	mean=mean/(t1*1.0);
	prob=prob/(t1*1.0);
	printf("%lf %lf\n",prob,mean);
	return 0;
}










