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
char ch[1000006],c;
int main()
{
	int i,t,ans=0,r,b,sz,j,g,a;
	si(t);
	while(t--)
	{
		ans=r=b=0;
		a=0;
		ss(ch);
		sz=strlen(ch);
		i=0;
		while(1)
		{
			a+=1;
			c=ch[i];
			j=i+1;
			if(c=='R')
				r++;
			else
				b++;
			//pin(j);
			while(j<sz && ch[j]==ch[i])
				j++;
			if(j==sz)
				break;
			i=j;
		}
		ans=-mod;
		FOR(i,1,sz-1)
		{
			if(ch[i]!=ch[i-1] && ch[i]!=ch[i+1])
			{
				if(ch[i]=='B')
				{
					g=1;
					if(b>1)
						g=2;
					
				}
				if(ch[i]=='R')
				{
					g=1;
					if(r>1)
						g=2;
				}
				ans=max(ans,g);
			}
		}
		if(sz>1)
		{
			if(ch[0]!=ch[1])
			{
				if(ch[0]=='B' && b>1)
				{
					g=1;
					ans=max(ans,g);
				}
				if(ch[0]=='R' && r>1)
				{
					g=1;
					ans=max(ans,g);
				}
			}
			if(ch[sz-1]!=ch[sz-2])
			{
				if(ch[sz-1]=='B' && b>1)
				{
					ans=max(ans,1);
				}
				if(ch[sz-1]=='R' && r>1)
				{
					ans=max(ans,1);
				}
			}
		}
		if(ans!=-mod)
			a-=ans;
		pin(a);
	}
	return 0;
}













