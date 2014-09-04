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

int arr[1000006],arr1[1000006];
int main()
{
	int n,i,sizeit,low,high,ans=0,val,val1,val2,val3,j,k,mid,l,flagit=0,ans1;
	si(n);
	//printf("n=%d\n",n);
	rep(i,n)
	{
		si(val);
		arr[i]=val;
	}
	sort(arr,arr+n);
	sizeit=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				val=arr[i];
				val1=arr[j];
				val2=arr[k];
				val3=val*val1+val2;
				//printf("sizeit=%lld\n",sizeit);
				arr1[sizeit++]=val3;
			}
		}
	}
	sort(arr1,arr1+sizeit);
	/*rep(i,sizeit)
		printf("%d\n",arr1[i]);
	printf("\n");*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				val=arr[i];
				val1=arr[j];
				val2=arr[k];
				if(val2==0)
					continue;
				val3=(val+val1)*val2;
				ans1=upper_bound(arr1,arr1+sizeit,val3)-lower_bound(arr1,arr1+sizeit,val3);
				//printf("val3=%d ans1=%d\n",val3,ans1);
				ans+=ans1;
				//printf("%lld\n",ans);
			}
		}
	}
	pin(ans);
	return 0;
}










