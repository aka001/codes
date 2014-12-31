/**Author: Akash Agrawall
  Institution: IIIT Hyderabad **/
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
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define c 1000000007
#define lld long long int
lld modpow(lld a,lld n,lld temp)
{
	lld res=1,y=a;
	while(n>0)
	{
		if(n&1)
		{
			if(res*y>temp)
				res=(res*y)%temp;
			else
				res=res*y;
		}
		if(y*y>temp)
			y=(y*y)%temp;
		else
			y=y*y;
		n>>=1;
	}
	if(res>temp)
		return res%temp;
	return res;
}
typedef long long LL;
string S;
int l;
string ans;
long long int power1(long long int x, long long int p)
{
	long long int temp,temp1;
	if(p==0)
		return 1;
	temp=power1(x,p/2);
	if(p%2==0)
	{
		if(temp*temp > c)
			return (temp*temp)%c;
		else
			return temp*temp;
	}
	else
	{
		//temp=temp%c;
		//long long int temp1=(temp*temp)%c;
		//return (temp1*x)%1000000007;
		if(temp*temp > c)
			temp=(temp*temp)%c;
		else
			temp=temp*temp;
		if(temp*x>c)
			return (temp*x)%c;
		else
			return temp*x;
	}
}
int getit()
{
	int s=0;
	char ch;
	ch=getchar_unlocked();
	while(ch!=' ' && ch!='\n')
	{
		s=s*10+ch-'0';
		ch=getchar_unlocked();
	}
	return s;
}
int main()
{
	int t,n;
	long long int ans,ans1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=modpow(n,n+1,1000000007)-n+1;
		if(n==1)
			ans1=0;
		else
			ans1=modpow(n-1,n,1000000007)-1;
		printf("%lld %lld\n",ans,ans1);
	}
	return 0;
}
