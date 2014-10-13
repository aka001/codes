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
ll arr[1000006],flag[10000006],fin[1000006],binit[1000006],cnt,cnt1;
ll binaryit(ll n)
{
	ll low=0,high=cnt1-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		//printf("low=%d high=%d mid=%d binit[mid]=%d n=%d\n",low,high,mid,binit[mid],n);
		if(binit[mid]>=n && (mid==0 || binit[mid-1]<n))
			return mid;
		else if(n>=binit[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
ll binarybinary(ll left, ll right, ll n)
{
	ll l,h,mid;
	l=left;
	h=right;
	while(l<=h)
	{
		mid=(l+h)/2;
		//printf("low=%d high=%d mid=%d binit=%d n=%d\n",l,h,mid,binit[mid],n);
		if(binit[mid]<=n && (mid==right || binit[mid+1]>n))
			return mid-left+1;
		else if(n>=binit[mid])
			l=mid+1;
		else
			h=mid-1;
	}
	return -1;
}
int main()
{
	ll t,n,i,j,k,calc,calc1,ind,ans,val,n1;
	sl(t);
	while(t--)
	{
		val=-mod;
		ans=0;
		cnt=0;
		cnt1=0;
		FOR(i,1,1000001)
			flag[i]=0;
		sl(n);
		sl(k);
		rep(i,n)
		{
			sl(arr[i]);
			val=max(val,arr[i]);
			flag[arr[i]]++;
		}
		FOR(i,1,1000001)
		{
			if(flag[i]!=0)
			{
				n1=min(flag[i],2);
				//printf("n1=%d i=%d\n",n1,i);
				while(n1--)
					fin[cnt++]=i;
			}
			if(flag[i]>=1)
				binit[cnt1++]=i;
		}
		sort(fin,fin+cnt);
		sort(binit,binit+cnt1);
		/*printf("cnt=%d cnt1=%d\n",cnt,cnt1);
		rep(i,cnt1)
			printf("%d ",binit[i]);
		printf("\n");
		rep(i,cnt)
			printf("%d ",fin[i]);
		printf("\n");*/
		rep(i,cnt)
		{
			if(i==0 || fin[i]!=fin[i-1])
			{
				flag[arr[i]]--;
				FOR(j,i+1,cnt)
				{
					//if(j!=cnt-1 && fin[j]==fin[j+1])
					//	continue;
					if(j==i+1 || fin[j]!=fin[j-1])
					{
						calc=k-(fin[i]+fin[j]);
						if(calc<1)
							continue;
						//printf("i=%d j=%d arr[j]+1=%d ind=%d calc1=%d calc=%d\n",i,j,fin[j]+1,ind,calc1,calc);
						if(flag[arr[j]]==1)
							ind=binaryit(fin[j]+1);
						else
							ind=binaryit(fin[j]);
						//printf("i=%lld j=%lld arr[j]+1=%lld calc=%lld ind=%lld\n",i,j,fin[j]+1,calc,ind);
						if(ind==-1)
							continue;
						calc1=binarybinary(ind,cnt1-1,calc);
						//printf("i=%d j=%d arr[j]+1=%d ind=%d calc1=%d calc=%d\n",i,j,fin[j]+1,ind,calc1,calc);
						//printf("IND=%d high=%d calc1=%d\n",ind,cnt1-1,calc1);
						if(calc1!=-1)
							ans+=calc1;
					}
				}
			}
		}
		pln(ans);
	}
	return 0;
}













