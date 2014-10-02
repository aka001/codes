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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int arr[10000006],M[10000006];
void initialize(int node, int b, int e)
{
	if(b==e)
	{
		M[node]=arr[b];
	}
	else if(b<e)
	{
		initialize(2*node, b, (b+e)/2);
		initialize(2*node+1, (b+e)/2+1, e);
		M[node]=M[2*node]&M[2*node+1];
	}
}
int query(int node, int b, int e, int x, int y)
{
	if(e<x || b>y)
		return 32767;
	else if(b>=x && e<=y)
		return M[node];
	else
	{
		int p1,p2;
		p1=query(2*node, b, (b+e)/2, x, y);
		p2=query(2*node+1, (b+e)/2+1, e, x, y);
		return p1&p2;
	}
}
int main()
{
	int t,n,k,i,high,calc,low,calc1,ans,cnt,fl,fl1;
	si(t);
	while(t--)
	{
		si(n);
		si(k);
		rep(i,n)
		{
			si(arr[i]);
		}
		initialize(1,0,n-1);
		rep(i,n)
		{
			//printf("i=%d\n",i);
			high=i+k;
			low=i-k;
			calc=32767;
			calc1=32767;
			//printf("%d i=%d low=%d high=%d\n",calc,i,low,high);
			fl=fl1=0;
			if(low<0)
			{
				cnt=1;
				low=-low;
				if(low>n)
				{
					printf("%d",query(1,0,n-1,0,n-1));
					if(i!=n-1)
						printf(" ");
					else
						printf("\n");
					continue;
				}
				else
				{
					low%=n;
					if(low==0)
						low=n;
					low--;
					low=n-low-1;
				}
				//printf("i=%d low=%d\n",i,low);
				//printf("first it\n");
				calc=query(1,0,n-1,low,n-1)&query(1,0,n-1,0,i);
				fl=1;
			}
			if(high>n-1)
			{
				if(high>=2*n)
				{
					printf("%d",query(1,0,n-1,0,n-1));
					if(i!=n-1)
						printf(" ");
					else
						printf("\n");
					continue;
				}
				high%=n;
				//printf("second it\n");
				calc1=query(1,0,n-1,0,high)&query(1,0,n-1,i,n-1);
				fl1=1;
			}
			if(low>=0 && low<=n-1 && high<=n-1 && high>=0 && low<=high && fl==0 && fl1==0)
			{
				//printf("third it\n");
				calc=query(1,0,n-1,low,high);
			}
			else if(low>=0 && low<=n-1 && fl1==1 && fl==0)
			{
				//printf("fourth it\n");
				calc=query(1,0,n-1,low,n-1);
			}
			else if(high>=0 && high<=n-1 && fl==1 && fl1==0)
			{
				//printf("fifth it\n");
				calc1=query(1,0,n-1,0,high);
			}
			ans=calc&calc1;
			//printf("calc=%d calc1=%d ans=%d i=%d low=%d high=%d ans=%d\n",calc,calc1,ans,i,low,high,ans);
			printf("%d",ans);
			if(i!=n-1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}











