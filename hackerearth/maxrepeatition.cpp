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
 
long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
char ch[100000];
int pos[100000],temp[100000],sa[100000],lcp[100000];
ll gap=1,length;
bool compareit(int i, int j)
{
	if(pos[i]!=pos[j])
		return pos[i]<pos[j];
	i+=gap;
	j+=gap;
	return (i<length && j<length) ? pos[i]<pos[j] : i>j;

}
int main()
{
	int t,i,j,k;
	ll ans,cnt,maxit;
	si(t);
	while(t--)
	{
		ans=0;
		gap=1;
		maxit=-1;
		lcp[0]=0;
		ss(ch);
		length=strlen(ch);
		rep(i,length)
		{
			pos[i]=ch[i];
			sa[i]=i;
		}
		temp[0]=0;
		for(gap=1;;gap*=2)
		{
			sort(sa,sa+length,compareit);
			rep(i,length-1)
				temp[i+1]=temp[i]+compareit(sa[i],sa[i+1]);
			rep(i,length)
				pos[sa[i]]=temp[i];
			if(temp[length-1]==length-1)
				break;
		}
		for(i=1;i<length;i++)
		{
			j=sa[i-1];
			k=sa[i];
			cnt=0;
			while(ch[j]==ch[k] && j<length && k<length)
			{
				j++;
				k++;
				cnt++;
			}
			lcp[i]=cnt;
			maxit=max(maxit,lcp[i]);
		}
		pln(maxit);
	}
	return 0;
}










