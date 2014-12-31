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
int l,n,ans1,ans2,aka=0;
string ans;
char a[1000][1000];
char ch[10000];
/*void doit(int i, int j, int p)
{
	int flag=0;
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		return;
	}
	//printf("i=%d j=%d\n",i,j);
	if(i<n && ch[p]==a[i+1][j])
	{
		flag=1;
		doit(i+1,j,p+1);
	}
	if(j<n && ch[p]==a[i][j+1])
	{
		flag=1;
		doit(i,j+1,p+1);
	}
	if(i>0 && ch[p]==a[i-1][j])
	{
		flag=1;
		doit(i-1,j,p+1);
	}
	if(j>0 && ch[p]==a[i][j-1])
	{
		flag=1;
		doit(i,j-1,p+1);
	}
	if(flag==0)
	{
		return;
	}
}*/
void doit1(int i, int j, int p)
{
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		return;
	}
	//printf("%d %d\n",i,j);
	if(i>0 && ch[p]==a[i-1][j])
		doit1(i-1,j,p+1);
	else
		return;
}
void doit2(int i, int j, int p)
{
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		//printf("p=%d l=%d\n",p,l);
		return;
	}
	//printf("%d %d\n",i,j);
	if(i<n-1 && ch[p]==a[i+1][j])
		doit2(i+1,j,p+1);
	else
	{
		//printf("i=%d\n",i);
		return;
	}
}
void doit3(int i, int j, int p)
{
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		return;
	}
	if(j>0 && ch[p]==a[i][j-1])
		doit3(i,j-1,p+1);
	else
		return;
}
void doit4(int i, int j, int p)
{
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		return;
	}
	if(j<n-1 && ch[p]==a[i][j+1])
		doit4(i,j+1,p+1);
	else
		return;
}
void doit5(int i, int j, int p)
{
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		return;
	}
	if(i<n-1 && j<n-1 && ch[p]==a[i+1][j+1])
		doit5(i+1,j+1,p+1);
	else
		return;
}
void doit6(int i, int j, int p)
{
	if(p==l)
	{
		ans1=i;
		ans2=j;
		aka=1;
		return;
	}
	if(i>0 && j>0 && ch[p]==a[i-1][j-1])
		doit6(i-1,j-1,p+1);
	else
		return;
}
int main()
{
	int i,agru;
	char chit;
	si(n);
	rep(i,n)
	{
		ss(a[i]);
	}
	while(1)
	{
		ss(ch);
		chit=getchar();
		if(strcmp(ch,"0")==0)
			break;
		l=strlen(ch);
		agru=0;
		aka=0;
		rep(i,n)
		{
			rep(j,n)
			{
				if(a[i][j]==ch[0])
				{
					//printf("%d %d\n",i,j);
					doit1(i,j,1);
					if(aka)
					{
						printf("%d,%d %d,%d\n",i+1,j+1,ans1+1,ans2+1);
						agru=1;
						break;
					}
					doit2(i,j,1);
					if(aka)
					{
						printf("%d,%d %d,%d\n",i+1,j+1,ans1+1,ans2+1);
						agru=1;
						break;
					}
					doit3(i,j,1);
					if(aka)
					{
						printf("%d,%d %d,%d\n",i+1,j+1,ans1+1,ans2+1);
						agru=1;
						break;
					}
					doit4(i,j,1);
					if(aka)
					{
						printf("%d,%d %d,%d\n",i+1,j+1,ans1+1,ans2+1);
						agru=1;
						break;
					}
					doit5(i,j,1);
					if(aka)
					{
						printf("%d,%d %d,%d\n",i+1,j+1,ans1+1,ans2+1);
						agru=1;
						break;
					}
					doit6(i,j,1);
					if(aka)
					{
						printf("%d,%d %d,%d\n",i+1,j+1,ans1+1,ans2+1);
						agru=1;
						break;
					}
				}
			}
			if(agru==1)
				break;
		}
		if(agru!=1)
			printf("Not found\n");
	}
	return 0;
}













