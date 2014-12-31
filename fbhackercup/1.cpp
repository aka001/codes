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

#define FOR(i,a,b) 	for(i= (int )a ; i < (int )b ; ++i)
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
#define pill(n)         printf("%lld\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int a[30][30];
int checkit(int n)
{
	int x=sqrt(n);
	if(x*x==n)
		return 1;
	else
		return 0;
}
int main()
{
	int chck,t,n,flag,si1,sj1,ei1,ej1,i1,i,j,check;
	char ch;
	si(t);
	rep(i1,t)
	{
		check=1;
		flag=0;
		si1=sj1=ei1=ej1=-1;
		si(n);
		ch=getchar();
		rep(i,n)
		{
			rep(j,n)
			{
				ch=getchar();
				if(ch=='.')
					a[i][j]=0;
				else
				{
					if(flag==0)
					{
						si1=i;
						sj1=j;
						flag=1;
					}
					ei1=i;
					ej1=j;
					a[i][j]=1;
				}
			}
			ch=getchar();
		}
		chck=checkit((ei1-si1)*(ej1-sj1));
		printf("Case #%d: ",i1+1);
		if(si1!=-1 && sj1!=-1 && ei1!=-1 && sj1!=-1 && ei1>=si1 && ej1>=sj1 && chck)
		{
			for(i=si1; i<=ei1; i++)
			{
				for(j=sj1;j<=ej1;j++)
				{
					if(a[i][j]==0)
					{
						check=0;
						break;
					}
				}
			}
			if(check)
			{
				printf("YES\n");
			}
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
}









