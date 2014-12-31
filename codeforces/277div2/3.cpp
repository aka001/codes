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
char ch[1000006],cst[1000006];
int main()
{
	ll n,p,i,szit,val,val1,cost,svit,svit1,ans,calc,temp,ans1;
	sl(n);
	sl(p);
	ss(ch);
	szit=strlen(ch);
	rep(i,szit)
		cst[i]=0;
	rep(i,szit/2)
	{
		val=ch[i];
		val1=ch[szit-i-1];
		if(val>=val1)
		{
			temp=val;
			val=val1;
			val1=temp;
		}
		cost=val1-val;
		calc=val-64;
		calc+=90-val1;
		cost=min(cost,calc);
		cst[i]=cost;
		cst[szit-i-1]=cost;
	}
	/*rep(i,szit)
	{
		printf("%d ",cst[i]);
	}*/
	p--;
	if(p>=szit/2)
		p=szit-p-1;
	svit=-1;
	calc=0;
	for(i=0;i<=p;i++)
	{
		if(cst[i]!=0 && svit==-1)
		{
			svit=i;
		}
		calc+=cst[i];
	}
	ans=0;
	if(svit==-1)
		ans=0;
	else
		ans+=calc+p-svit;
	//printf("ans=%d calc=%d\n",ans,calc);
	svit1=-1;
	calc=0;
	for(i=p+1;i<szit/2;i++)
	{
		if(cst[i]!=0)
		{
			svit1=i;
		}
		calc+=cst[i];
	}
	if(svit1==-1)
	{
		pln(ans);
		return 0;
	}
	ans1=calc;
	if(svit!=-1)
	{
		ans1+=2*(svit1-p)+ans;
	}
	else
	{
		ans1+=svit1-p;
	}
	ans+=calc+svit1-svit;
	ans=min(ans,ans1);
	pln(ans);
	return 0;
}










