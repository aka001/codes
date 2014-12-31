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
char a[7][7];
int r=-1,c=-1,cnt[7][7];
int m,n;
int search(char ch)
{
	int i,j,flag=0;
	rep(i,m)
	{
		rep(j,n)
		{
			if(ch==a[i][j])
			{
				if(((i==r && (j-c==1 || j-c==-1)) && cnt[i][j]==0) || ((j==c && (i-r==-1 || i-r==1)) && cnt[i][j]==0) || (r==-1 || j==-1))
				{
					flag=1;
					cnt[i][j]++;
					r=i;c=j;
					break;
				}
			}
		}
		if(flag)
			break;
	}
	return flag;
}
int main()
{
	int len,t,i,j,flag;
	char ch1[10000];
	si(m);
	si(n);
	rep(i,m)
		scanf("%s",a[i]);
	si(t);
	while(t--)
	{
		scanf("%s",ch1);
		len=strlen(ch1);
		flag=1;
		rep(i,len)
		{
			if(search(ch1[i])==0)
			{
				flag=0;
				break;
			}
			printf("%d %d\n",r,c);
		}
		if(flag)
		{
			printf("%s\n",ch1);
		}
	}
	return 0;
}
