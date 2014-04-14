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
#define min1(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define min(a,b,c,d) min1(min1(min1(a,b),c),d)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l;
string ans;
typedef struct doit
{
	int left,top,right,down;
	int val;
}doit;
doit *ar[51];
int main()
{
	int mind,i,j,k,t,a[51][51],r,c,cnt;
	char ch[100];
	si(t);
	rep(i,t)
	{
		cnt=0;
		rep(j,51)
		{
			ar[j]=(doit*)malloc(51*sizeof(doit));
		}
		si(r);si(c);
		rep(j,r)
		{
			scanf("%s",ch);
			rep(k,c)
			{
				//printf("%c",ch[k]);
				if(ch[k]=='^')
					a[j][k]=1;
				else if(ch[k]=='#')
					a[j][k]=0;
			}
		}
		/*rep(j,r)
		{
			rep(k,c)
			{
				pi(a[j][k]);
			}
			printf("\n");
		}*/
		rep(j,r)
		{
			rep(k,c)
			{
				//if(k>0 && a[j][k-1]==1)
				if(a[j][k-1]==1)
					ar[j][k].left=1;
				else
					ar[j][k].left=0;
				//if(j>0 && a[j-1][k]==1)
				if(a[j-1][k]==1)
					ar[j][k].top=1;
				else
					ar[j][k].top=0;
				//if(k<c-1 && a[j][k+1]==1)
				if(a[j][k+1]==1)
					ar[j][k].right=1;
				else
					ar[j][k+1].right=0;
				//if(j<r-1 && a[j+1][k]==1)
				if(a[j+1][k]==1)
					ar[j][k].down=1;
				else
					ar[j][k].down=0;
				//pi(ar[j][k].left);
				//pi(ar[j][k].top);
				//pi(ar[j][k].right);
				//pi(ar[j][k].down);
				//printf(" ");
			}
			//printf("\n");
		}
		rep(j,r)
		{
			FOR(k,1,r)
			{
				ar[j][k].left+=ar[j][k-1].left;
			}
		}
		rep(j,c)
		{
			FOR(k,1,r)
			{
				ar[k][j].top+=ar[k-1][j].top;
			}
		}
		rep(j,r)
		{
			for(k=c-2;k>=0;k--)
			{
				ar[j][k].right+=ar[j][k+1].right;
			}
		}
		rep(j,c)
		{
			for(k=r-2;k>=0;k--)
			{
				ar[k][j].down+=ar[k+1][k].down;
			}
		}
		rep(j,r)
		{
			rep(k,r)
			{
				mind=min(ar[j][k].left,ar[j][k].top,ar[j][k].right,ar[j][k].down);
				if(a[j][k]==1 && mind>=2)
				{
					//pi(j);
					//pil(k);
					cnt++;
				}
			}
		}
		pil(cnt);
	}

}












