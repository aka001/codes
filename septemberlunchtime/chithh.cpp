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
int a[1000000];
int main()
{
	int p,calc,c,flag,m,i,x,q,n,l,v,k,cnt=1,dig=0;
	si(n);
	rep(i,n)
	{
		si(a[i]);
	}
	si(m);
	while(m--)
	{
		si(l);
		si(v);
		si(k);
		q=0;dig=0;
		x=l+v*q;
		flag=0;cnt=1;
		while(x<=n)
		{
			dig=0;
			p=a[x-1];
			while(p!=0)
			{
				dig++;
				p/=10;
			}
			if(k<=dig)
			{
				p=a[x-1];
				calc=dig-k;
				c=0;
				while(1)
				{
					p/=10;
					c++;
					if(c==calc)
						break;
				}
				pil(p%10);
				flag=1;
				break;
			}
			else
				k=dig-k;
			//pil(a[x-1]);
			q++;
			x=l+v*q;
			cnt++;
		}
		if(flag==0)
			printf("So sad\n");
	}
}
