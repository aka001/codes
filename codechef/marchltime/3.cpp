/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


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
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
/*void initialize(int node, int l, int r)
{
	if(l>r)
		return;
	if(l==r)
	{
		arr[node]=1;
		return;
	}
	initialize(2*node, l, (l+r)/2);
	initialize(2*node+1, (l+r)/2+1, r);
	arr[node]=arr[2*node]+arr[2*node+1];
}*/
pair<int, int> pit[1000006];
int arr[1000006], papa[1000006], ans;
void update(int a, int rng, int flag, int flg)
{
	int p1,c1;
	p1=papa[a];
	c1=pit[p1].S-pit[p1].F+1;
	if(c1>=w)
		c1=c1-w+1;
	else
		c1=0;
	ans-=c1;
	if(flag==0)
		pit[p1].F=rng;
	else
		pit[p1].S=rng;
	c1=pit[p1].S-pit[p1].F+1;
	if(c1>=w)
		c1=c1-w+1;
	else
		c1=0;
	if(flg)
		ans+=c1;
}
int main()
{
	int t,cnt,n,w,i,j;
	si(t);
	while(t--)
	{
		cnt=0;
		si(n);
		si(w);
		rep(i,n)
			si(arr[i]);
		i=0;
		while(1)
		{
			pit[cnt].F=i;
			papa[i]=cnt;
			j=i+1;
			while(arr[j]==arr[i])
			{
				papa[j]=cnt;
				j++;
			}
			pit[cnt].S=j-1;
			i=j;
			cnt++;
			if(i>=n)
				break;
		}
		/*rep(i,n)
			printf("i=%d papa=%d\n",i,papa[i]);*/
		ans=0;
		rep(i,cnt)
		{
			printf("%d %d\n",pit[i].F,pit[i].S);
			calc=pit[i].S-pit[i].F+1;
			if(calc>=w)
				ans+=calc-w+1;
		}
		si(q);
		rep(i,q)
		{
			si(a);
			si(b);
			a--;
			old=arr[a];
			arr[a]=b;
			if(a!=0 && a!=n-1)
			{
				if(arr[a-1]==arr[a] && arr[a]==arr[a+1])
				{
					p1=papa[a-1];
					p2=papa[a+1];
					update(a-1, pit[p2].S, 1, 1);
					update(a+1, pit[p1].F, 0, 0);
					papa[a]=papa[a-1];
				}
				else if(arr[a]!=arr[a-1] && arr[a]!=arr[a+1])
				{
					papa[a]=cnt;
					pit[cnt].F=a;
					pit[cnt].S=a;
					cnt++;
					c1=1;
					if(c1>=w)
						ans+=c1-w+1;
					if(old==arr[a-1] && old==arr[a+1])
					{
						update(a-1, a-1, 1, 1);
						update(a+1, a+1, 0, 1);
					}
				}
			}
			else if(a!=0)
			{
				
			}
		}
	}
	return 0;
}








