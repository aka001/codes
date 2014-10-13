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
vector<int> arr;
vector<pair<int,int> > rsk,newit;
int cnt=1,cnt1=0;
int k;
void doit()
{
	int val,val1;
	newit.pb(mp(rsk[0].F,rsk[0].S));
	cnt=1;
	cnt1=1;
	while(cnt<k)
	{
		//printf("cnt=%d\n",cnt);
		val=rsk[cnt].F;
		val1=rsk[cnt].S;
		if(val>newit[cnt1-1].S)
		{
			newit.pb(mp(val,val1));
			cnt1++;
		}
		else
		{
			newit[cnt1-1].S=max(newit[cnt1-1].S,val1);
		}
		cnt++;
	}
}
int binaryit(int n)
{
	int low=0,high=cnt1-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(newit[mid].F<=n && (mid==cnt1-1 || newit[mid+1].F>n))
		{
			return mid;
		}
		else if(n>=newit[mid].F)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	int n,ans=0,val,val1,i;
	si(n);
	si(k);
	rep(i,n)
	{
		si(val);
		arr.pb(val);
	}
	rep(i,k)
	{
		si(val);
		si(val1);
		rsk.pb(mp(val,val1));
	}
	sort(rsk.begin(),rsk.end());
	doit();
	/*rep(i,cnt1)
	{
		printf("%d %d\n",newit[i].F,newit[i].S);
	}*/
	rep(i,n)
	{
		val=binaryit(arr[i]);
		if(val!=-1 && newit[val].F<=arr[i] && arr[i]<=newit[val].S)
			ans++;
	}
	pin(ans);
	return 0;
}

















