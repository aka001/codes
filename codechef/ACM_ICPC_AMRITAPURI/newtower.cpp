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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
char ch[1000006];
int flag[1000006];
int main()
{
	int i,sz,calc,calc1,m,l,q,ans,j,size;
	ss(ch);
	sz=strlen(ch);
	si(q);
	while(q--)
	{
		ans=0;
		si(m);
		si(l);
		FOR(i,0,m)
			flag[i]=0;
		rep(i,sz)
		{
			calc=ch[i]-'0';
			vector<pair<int,int> > saveit;
			rep(j,m)
			{
				if(flag[j]!=0)
				{
					calc1=j*10+calc;
					calc1%=m;
					saveit.pb(mp(calc1,flag[j]));
					flag[j]=0;
				}
			}
			size=saveit.size();
			rep(j,size)
			{
				flag[saveit[j].F]+=saveit[j].S;
			}
			calc1=calc%m;
			flag[calc1]++;
			if(flag[l]!=0)
			{
				ans+=flag[l];
			}
		}
		pin(ans);
	}
	return 0;
}








