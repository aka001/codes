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
char ch[1000006];
int cit[1000006],flag[1000006],das[1000006];
ll modit(int calc,int l, int m)
{
	ll val=1;
	while(calc<0)
	{
		calc+=val*l;
		l<<=1;
	}
	calc%=l;
	return calc;
}
int main()
{
	int i,cnt=0,q,n,m,l,sz,calc,calc1,ans,val,j;
	ss(ch);
	si(q);
	while(q--)
	{
		ans=0;
		vector<int> arr;
		si(m);
		si(l);
		sz=strlen(ch);
		calc=ch[0]-'0';
		cnt=1;
		das[0]=1%m;
		rep(i,m)
			flag[i]=0;
		FOR(i,1,m+1)
		{
			das[i]=(das[i-1]*10)%m;
		}
		calc%=m;
		calc*=das[sz-1];
		calc%=m;
		arr.pb(calc%m);
		FOR(i,1,sz)
		{
			calc=ch[i]-'0';
			calc1=arr[i-1]*10+calc;
			calc1%=m;
			//printf("calc=%d i=%d calc1=%d das=%d\n",calc,i,calc1,das[sz-i-1]);
			calc1=calc1*das[sz-i-1];
			calc1%=m;
			arr.pb(calc1);
		}
		rep(i,sz)
			printf("%d ",arr[i]);
		printf("\n");
		for(i=sz-1;i>=0;i--)
		{
			if(arr[i]==l)
				ans++;
			flag[arr[i]]++;
			if(i==0)
				continue;
			//printf("i=%d arr[i]=%d\n",i,arr[i]);
			val=arr[i-1];
			FOR(j,0,m)
			{
				if(flag[j]>=1)
				{
					calc=j-val;
					if(calc>=0)
						calc%=m;
					else
						calc=modit(calc,l,m);
					if(calc==l)
					{
						//printf("j=%d \n",j);
						ans+=flag[j];
					}
				}
			}
		}
		pin(ans);
	}
	return 0;
}











