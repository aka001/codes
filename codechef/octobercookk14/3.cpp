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
ll arr[1000006],ans[1000006];
int main()
{
	ll t,n,calc,i,j,calc1,lit,hit,cnt,doit,low,sz,lenit,doit1,akash,temp;
	sl(t);
	while(t--)
	{
		vector<ll> val;
		sl(n);
		calc=modpow(2,n,mod);
		rep(j,calc)
		{
			sl(arr[j]);
		}
		sort(arr,arr+calc);
		/*rep(i,calc)
			printf("%d ",arr[i]);
		printf("\n");*/
		if(n==1)
		{
			printf("%lld\n",arr[1]);
			continue;
		}
		calc1=4;
		lenit=calc;
		ans[1]=arr[1];
		ans[2]=arr[2];
		val.pb(ans[1]+ans[2]);
		cnt=2;
		lit=0;
		doit=4;
		FOR(i,3,lenit)
		{
			if(cnt==n)
				break;
			low=lower_bound(val.begin()+lit,val.end(),arr[i])-(val.begin());
			sz=val.size();
			/*printf("low=%d arr[%d]=%d lit=%d sz=%d val[%d]=%d\n",low,i,arr[i],lit,sz,low,val[low]);
			FOR(j,lit,sz)
				printf("%d ",val[j]);
			printf("\n");*/
			if(low!=sz && val[low]==arr[i])
			{
				lit++;
				//printf("lit=%d\n",lit);
			}
			else
			{
				cnt++;
				ans[cnt]=arr[i];
				if(cnt==n)
					break;
				doit1=doit*2;
				FOR(j,doit+1,doit1)
				{
					calc=j;
					akash=1;
					temp=0;
					while(calc!=0)
					{
						if(calc%2==1)
						{
							temp+=ans[akash];
						}
						calc/=2;
						akash++;
					}
					//printf("temp=%d\n",temp);
					val.pb(temp);
				}
				doit*=2;
				sort(val.begin()+lit,val.end());
			}
		}
		FOR(i,1,cnt+1)
		{
			printf("%lld",ans[i]);
			if(i==cnt)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}










