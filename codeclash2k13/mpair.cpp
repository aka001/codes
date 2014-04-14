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
int l;
string ans;
int a[1000000],b[1000000],c[1000000];
int main()
{
	int j,n,m,x,y,x1,y1,cnt=0,co;
	long long int calc=0,s=0;
	si(n);
	si(m);
	FOR(i,1,n+1)
	{
		a[i]=i;
		b[i]=i;
	}
	rep(i,m)
	{
		si(x);
		si(y);
		x1=x;
		y1=y;
		while(1)
		{
			if(a[x]==x)
			{
				a[x]=y;
				break;
			}
			else
				x=a[x];
		}
		x=x1;
		y=y1;
		while(1)
		{
			if(b[y]==y)
			{
				b[y]=x;
				break;
			}
			else
				y=b[y];
		}
		printf("%d %d\n",y,x);
	}
	printf("\n");
	FOR(i,1,n+1)
		printf("%d %d\n",i,a[i]);
	printf("\n");
	FOR(i,1,n+1)
	{
		printf("%d %d\n",i,b[i]);
	}
	FOR(i,1,n+1)
	{
		if(b[i]==i)
		{
			x=i;
			co=0;
			while(a[x]!=x)
			{
				co++;
				x=a[x];
			}
			s+=co+1;
			c[cnt++]=co+1;
		}
	}
	printf("%lld\n",s);
	rep(i,cnt)
	{
		s-=c[i];
		calc=calc+c[i]*s;
	}
	printf("%lld\n",calc);
	return 0;
}




