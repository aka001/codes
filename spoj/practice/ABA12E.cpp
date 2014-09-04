/*******************
  Akash Agrawall
  IIIT HYDERABAD
  akash.agrawall094@gmail.com
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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

ll pref[1000006],arr[1000006],n,k;
ll searchit(ll val)
{
	ll left=0,right=0,calc,flagit=0;
	ll ans=0;
	ll j,sum=0;
	while(left<=right && left<=n-1 && right<=n-1)
	{
		sum+=arr[right];
		if(sum>val)
		{
			flagit=1;
			if(left==right)
			{
				sum-=arr[left];
				left++;
				right++;
				continue;
			}
			ans+=right-left;
			sum-=arr[left];
			sum-=arr[right];
			if(left!=right)
				left++;
			/*if(val==4)
			  printf("left=%d right=%d sum=%d ans=%lld\n",left,right,sum,ans);*/
		}
		else
			right++;
	}
	if(sum<=val)
	{
		if(sum==val && left==right)
			ans++;
		else
			ans+=((right-left)*(right-left+1))/2;
	}
	if(flagit==0)
		ans=(n*(n+1))/2;
	return ans;
}
int main()
{
	ll low,high,mid,ans=0,val,val1,i,j;
	sl(n);
	sl(k);
	rep(i,n)
		sl(arr[i]);
	/*pref[0]=arr[0];
	  FOR(i,1,n)
	  {
	  pref[i]=pref[i-1]+arr[i];
	  }*/
	//printf("%lld\n",searchit(3));
	low=0;
	high=(ll)((ll)mod*(ll)10000000);
	//printf("low=%lld high=%lld\n",low,high);
	while(low<=high)
	{
		mid=(ll)(low+high)/2;
		val=searchit(mid);
		val1=searchit(mid+1);
		//printf("low=%lld high=%lld mid=%lld val=%lld mid+1=%lld val1=%lld\n",low,high,mid,val,mid+1,val1);
		if(val<k && val1>=k)
		{
			ans=mid+1;
			break;
		}
		else if(val>=k)
		{
			high=mid-1;
		}
		else
			low=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}










