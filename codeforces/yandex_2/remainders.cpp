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
#define FOR(i,a,b) for(int i= a ; i < b ; ++i)
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
int arr[1000006],flagit[10000006],cntit[1000006],n;
ll ans=0;
int binary_search(int num)
{
	int low=0,high=n-1,mid=-1,flagit=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]<=num && arr[mid+1]>num || (mid==n-1 && arr[mid]<=num))
		{
			flagit=1;
			break;
		}
		else if(arr[mid]>num)
			high=mid-1;
		else
			low=mid+1;
	}
	if(flagit==0)
		return -1;
	else
		return mid;
}
void recursion(int num,int fresh, int pos)
{
	int i,val,val1;
	if(fresh==1)
	{
		if(cntit[num]==1)
			val=pos-1;
		else
			val=pos;
	}
	else
		val=binary_search(num);
	if(val==-1)
	{
		if(flagit[num]==0)
		{
			//printf("num=%d pos=%d\n",num,pos);
			ans++;
		}
		flagit[num]=1;
	}
	else
	{
		rep(i,val+1)
		{
			val1=num%arr[i];
			recursion(val1,0,-1);
		}
	}
}
int main()
{
	int i;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
		cntit[arr[i]]++;
	}
	sort(arr,arr+n);
	rep(i,n)
	{
		recursion(arr[i],1,i);
		//printf("ans=%lld\n",ans);
	}
	pln(ans);
	return 0;
}








