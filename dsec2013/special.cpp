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
int find(int n)
{
	int flag=0,a;
	while(n!=0)
	{
		a=n%10;
		if(a==3 || a==5 || a==6)
		{
			flag=1;
			break;
		}
		n/=10;
	}
	return flag;
}
int main()
{
	int i,t,n,calc,doit,ans;
	si(t);
	rep(i,t)
	{
		ans=0;
		si(n);
		if(find(n))
			ans++;
		calc=sqrt(n);
		calc++;
		FOR(j,2,calc)
		{
			if(n%j==0)
			{
				doit=j;
				if(find(doit)==1)
				{
					//pil(doit);
					ans++;
				}
				if(j*j != n)
				{
					doit=n/j;
					if(find(doit)==1)
					{
						//pil(doit);
						ans++;
					}
				}
			}
		}
		pil(ans);
	}
	return 0;
}





