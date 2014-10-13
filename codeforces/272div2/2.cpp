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
ll num=0,den=0;
int sz1,cnt;
char ch[100],ch1[100];
int prob(int i, int val)
{
	if(i==sz1)
	{
		//printf("val=%d\n",val);
		if(val==cnt)
			num++;
	}
	else
	{
		if(ch1[i]=='+')
			prob(i+1,val+1);
		else if(ch1[i]=='-')
			prob(i+1,val-1);
		else
		{
			prob(i+1,val+1);
			prob(i+1,val-1);
		}
	}
}
int main()
{
	int sz,i;
	double ans;
	cnt=0;
	ss(ch);
	sz=strlen(ch);
	rep(i,sz)
	{
		if(ch[i]=='+')
			cnt++;
		else
			cnt--;
	}
	ss(ch1);
	sz1=strlen(ch1);
	rep(i,sz1)
	{
		if(ch1[i]=='?')
			den++;
	}
	den=modpow(2,den,mod);
	if(sz1==0)
	{
		ans=0;
		printf("%.09f\n",ans);
		return 0;
	}
	prob(0,0);
	ans=num/(den*1.0);
	printf("%.09f\n",ans);
	return 0;
}










