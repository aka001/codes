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
char ch[1000006];
int flg[1000006];
inline int isvowel(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 1;
	return 0;
}
int main()
{
	int n,flag,i,j,prtit=0,sz;
	si(n);
	rep(i,n)
	{
		ss(ch);
		if(prtit)
			continue;
		sz=strlen(ch);
		flag=0;
		rep(j,sz)
		{
			if(ch[j]>='A' && ch[j]<='Z')
			{
				flg[j]=1;
				ch[j]+=32;
			}
		}
		rep(j,sz)
		{
			if(isvowel(ch[j]))
			{
				if(j+1<=sz-1 && isvowel(ch[j+1])==1 && ch[j+1]!=ch[j] && flg[j+1]==flg[j])
				{
					flag=1;
					break;
				}
			}
			else
			{
				if(j+1<=sz-1 && isvowel(ch[j+1])==0 && j+2<=sz-1 && isvowel(ch[j+2])==0)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<ch<<endl;
			return 0;
			prtit=1;
		}
	}
	return 0;
}













