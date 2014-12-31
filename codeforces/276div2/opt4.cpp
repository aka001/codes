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
#define MAX 1000006
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int arr[1000006],lowit[1000006];
int lowerit(int val,int n)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]<val && (mid==n-1 || arr[mid+1]>=val))
			return arr[mid];
		else if(val>=arr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	int n,maxit=-mod,ans=0,i,val,val1,findit;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
		lowit[arr[i]+1]=arr[i];
		maxit=max(maxit,arr[i]);
	}
	FOR(i,1,1000006)
	{
		if(lowit[i]==0)
			lowit[i]=lowit[i-1];
	}
	sort(arr,arr+n);
	rep(i,n)
	{
		val=arr[i];
		if(i!=0 && val==arr[i-1])
			continue;
		val1=2*val;
		while(1)
		{
			if(val1>=MAX)
				findit=lowit[MAX-1];
			else
				findit=lowit[val1];
			//printf("val=%d val1=%d findit=%d\n",val,val1,findit);
			if(findit<val)
			{
				continue;
			}
			findit%=val;
			ans=max(ans,findit);
			if(val1>=maxit)
				break;
			val1+=val;
		}
	}
	pin(ans);
	return 0;
}











