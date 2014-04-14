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
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l,n,a[100];
//long long int ans;
int ans;
long long int ans1;
int getit()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!='\n')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
//int calc(int i, long long int doit, char ch)
int calc(int i, int doit, char ch)
{
	//printf("%c %d %d\n",ch,i,doit);
	if(i==n-1)
		ans=min(ans,doit);
	else
	{
		calc(i+1,doit*a[i+1],'*');
		calc(i+1,doit+a[i+1], '+');
		calc(i+1,doit-a[i+1], '-');
	}
}
int calc1(int i, long long int doit, char ch)
{
	//printf("%c %d %d\n",ch,i,doit);
	if(i==n-1)
		ans1=min(ans1,doit);
	else
	{
		calc1(i+1,doit*a[i+1],'*');
		calc1(i+1,doit+a[i+1], '+');
		calc1(i+1,doit-a[i+1], '-');
	}
}
int main()
{
	int x,t,i;
	si(t);
	while(t--)
	{
		si(n);
		rep(i,n)
			si(a[i]);
		//a[i]=getit();
		if(n==1)
		{
			pil(a[0]);
			continue;
		}
		else if(n>7)
		{
			ans1=1000000000;
			calc1(0,a[0],'-');
			printf("%lld\n",ans1);
		}
		else
		{
			ans=1000000000;
			calc(0,a[0],'-');
			printf("%d\n",ans);
		}
		//printf("abhi\n");
	}
	return 0;
}




