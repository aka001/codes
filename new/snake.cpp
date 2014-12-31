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
int l,cnt;
string ans;
int a[1000];
int lead(int i)
{
	if(a[i]==i)
		return i;
	cnt++;
	lead(a[i]);
}
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int m,r,n,act,i,x,y,mvt,calc,act1,calc2,mv1,mv,mv2,flag;
		int ar[10000];
		act=1;flag=0;
		mv1=mv2=mv=mvt=1;
		si(n);si(m);si(r);
		for(i=1;i<=n;i++)
			a[i]=i;
		while(m--)
		{
			si(x);si(y);
			a[x]=y;
		}
		for(i=1;i<=r;i++)
			si(ar[i]);
		for(i=1;i<=r;i++)
		{
			cnt=0;
			if(act==1)
			{
				mv=mv1;
				mvt=mv2;
			}
			else
			{
				mv=mv2;
				mvt=mv1;
			}
			calc=mv+ar[i];
			if(calc>n)
			{
				if(ar[i]!=6)
					act=3-act;
				continue;
			}
			if(calc<=n)
			{
				calc2=lead(calc);
				if(calc2==n)
				{

					if(act==1)
					{
						if(calc2<=n)
						{
							mv1=calc2;
							mv2=mvt;
						}
					}
					else
					{
						if(calc2<=n)
						{
							mv2=calc2;
							mv1=mvt;
						}
					}
					flag=1;
					break;
				}
			}
			act1=act;
			if(calc2==mvt)
			{
				mvt=1;
			}
			else
			{
				if(!(ar[i]==6 || cnt>=1))
					act=3-act;
			}
			if(act1==1)
			{
				if(calc2<=n)
				{
					mv1=calc2;
					mv2=mvt;
				}
			}
			else
			{
				if(calc2<=n)
				{
					mv2=calc2;
					mv1=mvt;
				}
			}
			//printf("%d %d %d %d\n",calc,mv1,mv2,act);
		}
		if(flag)
			printf("%d %d %d\n",act,mv1,mv2);
		else
			printf("0 %d %d\n",mv1,mv2);
	}
	return 0;
}










