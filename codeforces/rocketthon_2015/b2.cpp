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
ll n,k,doit;
vector<ll> arr,ans,fin,ans1,newit;
int visited[100005];
ll checkit(ll calc,ll high)
{
	if(calc==1)
		return 0;
	ll low=0,mid,val;
	val=modpow(2,n-2,doit);
	while(low<=high)
	{
		mid=(low+high)/2;
		//printf("calc=%lld arr[%lld]=%lld\n",calc,mid,arr[mid]);
		if(calc>arr[mid] && (calc<=arr[mid+1]))
		{
			return mid+1;
		}
		else if(calc>arr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
}
ll check_again(ll calc,ll high)
{
	if(calc<=arr[0])
		return 0;
	ll low=0,mid,val;
	val=modpow(2,n-2,doit);
	printf("calc=%lld high=%lld\n",calc,high);
	while(low<=high)
	{
		mid=(low+high)/2;
		//printf("calc=%lld arr[%lld]=%lld\n",calc,mid,arr[mid]);
		if(calc>newit[mid] && (calc<=newit[mid+1]))
		{
			return mid+1;
		}
		else if(calc>newit[mid])
			low=mid+1;
		else
			high=mid-1;
	}
}
/*ll check_again(ll calc,ll high)
{
	if(high==0)
		return 0;
	ll v1=calc/high,ret=0;
	while(v1!=0)
	{
		ret++;
		if(high==0)
			break;
		v1=(v1*high)/(high/2);
	}
	return ret;
}*/
int main()
{
	doit=1000000000000000000L;
	ll cnt,calc,did,val,i,up,flag,sz,j,val1,start,end,vv;
	sl(n);
	sl(k);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	else if(n==2)
	{
		if(k==1)
			printf("1 2\n");
		else
			printf("2 1\n");
		return 0;
	}
	FOR(i,1,n+1)
	{
		fin.pb(i);
		ans.pb(i);
	}
	cnt=n;
	arr.pb(1);
	val=modpow(2,n-1,doit);
	calc=2;
	while(calc<=val)
	{
		arr.pb(calc);
		calc*=2;
	}
	up=arr.size();
	rep(i,up)
	{
		newit.pb(arr[up-i-1]);
	}
	rep(i,up)
	{
		if(i!=0)
			newit[i]+=newit[i-1];
	}
	cnt=n;
	end=n-1;
	start=0;
	k--;
	vv=1;
	while(cnt>0)
	{
		if(k>=arr[up-2])
		{
			//printf("1st k=%lld\n",k);
			k-=arr[up-2];
			fin[end]=vv;
			end--;
		}
		else
		{
			fin[start]=vv;
			start++;
		}
		vv++;
		cnt--;
		up--;
	}
	rep(i,n)
	{
		if(i==n-1)
			printf("%lld\n",fin[i]);
		else
			printf("%lld ",fin[i]);
	}
	return 0;
}










