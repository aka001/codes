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
ll arr[1000006],brr[1000006],vis[201],markit[1000006];

int main()
{
	vector<int> doit,summatch,sumsum;
	ll t,n,k,i,cnt,ans=0,len,flag=0,szit,j;
	ll sum=0,calc1,calc,val,sumit,low,high,ansflag,szak,fnd,flgit;
	sl(t);
	while(t--)
	{
		summatch.clear();
		sumsum.clear();
		ans=0;
		sum=0;
		sl(n);
		sl(k);
		len=0;
		rep(i,200)
			vis[i]=0;
		rep(i,n)
		{
			sl(arr[i]);
			sum+=arr[i];
		}
		sort(arr,arr+n);
		/*len=0;
		rep(i,n-1)
		{
			if(arr[i]!=arr[i+1])
				brr[len++]=arr[i];
		}
		brr[len++]=arr[n-1];
		n=len;*/
		if(sum%k==0)
		{
			calc=modpow(2,n,mod);
			sum/=k;
			for(i=calc-1;i>0;i--)
			{
				doit.clear();
				val=i;
				cnt=0;
				sumit=0;
				while(val!=0)
				{
					if(val&01==1)
					{
						doit.pb(cnt);
						sumit+=arr[cnt];
					}
					val>>=1;
					cnt++;
				}
				if(sumit==sum)
				{
					summatch.pb(i);
					/*szit=doit.size();
					flag=1;
					rep(j,szit)
					{
						if(vis[doit[j]]==1)
						{
							flag=0;
							break;
						}
					}
					if(flag)
					{
						ans++;
						rep(j,szit)
						{
							vis[doit[j]]=1;
						}
					}*/
				}
			}
			cnt=summatch.size();
			if(cnt<k)
			{
				printf("no\n");
				continue;
			}
			else
			{
				low=(1<<k)-1;
				high=1<<cnt;
				ansflag=0;
				//printf("low=%lld high=%lld\n",low,high);
				for(i=low;i<high;i++)
				{
					sumsum.clear();
					val=i;
					cnt=0;
					while(val!=0)
					{
						if(val%2==1)
						{
							sumsum.pb(summatch[cnt]);
						}
						cnt++;
						val/=2;
					}
					if(cnt!=k)
						continue;
					rep(j,n)
						vis[j]=0;
					szak=sumsum.size();
					fnd=1;
					rep(j,szak)
					{
						val=sumsum[j];
						cnt=0;
						while(val!=0)
						{
							if(val%2==1)
							{
								if(vis[cnt]==1)
								{
									fnd=0;
									break;
								}
								vis[cnt]=1;
							}
							cnt++;
							val/=2;
						}
						if(fnd==0)
						{
							break;
						}
					}
					flgit=0;
					if(fnd)
					{
						for(i=0;i<n;i++)
						{
							if(!vis[i])
							{
								flgit=1;
								break;
							}
						}
					}
					if(flgit==0)
					{
						ansflag=1;
						printf("yes\n");
						break;
					}
				}
				if(ansflag==0)
				{
					printf("no\n");
				}
			}
			//pln(ans);
		}
		else
			printf("no\n");
	}
	return 0;
}






