/*Author : Akash Agrawall
 Institution: IIIT Hyderabad*/

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
#define lli		long long int
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int getint()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!=' ')
	{
		s=s<<1 + s<<3 + ch-'0';
		ch=getchar();
	}
	return s;
}
inline int check(long long int n)
{
	if(n>99999999999999 && n<10000000000000000)
		return 1;
	else if(n>=10000000000000000)
		return 2;
	return 0;
}
int check1(long long int n)
{
	int flag=1;
	long long int x;
	while(n!=0)
	{
		x=n%10;
		if(x!=5 && x!=7)
		{
			flag=0;
			break;
		}
		n/=10;
	}
	return flag;
}
int main()
{
	long long int calc1,x=1,y=5,z=7,calc=x;
	int ans=0;
	while(1)
	{
		calc1=calc;
		if(check(calc1)==1 && check1(calc1)==1)
			ans++;
		while(1)
		{
			calc1*=7;
			if(check(calc1)==1 && check1(calc1)==1)
				ans++;
			else if(check(calc1)==2)
				break;
		}
		calc1=calc;
		while(1)
		{
			calc1*=5;
			if(check(calc1)==1 && check1(calc1)==1)
				ans++;
			else if(check(calc1)==2)
				break;
		}
		calc*=35;
		if(check(calc)==2)
			break;
	}
	printf("%d\n",ans);
	return 0;
}









