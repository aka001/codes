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


int arr[1000006],flagit[1000006];
int main()
{
	int t,n,i,j,sizeit,curr,val,cnt,sz,value,maxit;
	si(t);
	while(t--)
	{
		queue<int> queit;
		si(n);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		rep(i,n)
		{
			si(arr[i]);
		}
		sort(arr,arr+n);
		val=arr[0];
		i=0;
		while(i<n)
		{
			if(arr[i]==val)
			{
				//printf("arr=%d\n",arr[i]);
				queit.push(arr[i]);
			}
			else
				break;
			i++;
		}
		if(i==n)
		{
			printf("1\n");
			continue;
		}
		curr=arr[i-1];
		curr++;
		//printf("i=%d n=%d arr[i]=%d curr=%d\n",i,n,arr[i],curr);
		maxit=mod;
		while(i<n)
		{
			//printf("curr=%d arr[i]=%d\n",curr,arr[i]);
			if(arr[i]==curr)
			{
				//printf("curr=%d arr[i]=%d\n",curr,arr[i]);
				cnt=0;
				while(i<n)
				{
					if(arr[i]!=curr)
						break;
					else
					{
						//printf("i=%d arr[i]=%d curr=%d\n",i,arr[i],curr);
						cnt++;
					}
					i++;
				}
				sz=queit.size();
				if(cnt<sz)
				{
					cnt=sz-cnt;
					rep(j,cnt)
					{
						value=queit.front();
						//printf("i=%d curr-value=%d cnt=%d\n",i,curr-value,cnt);
						maxit=min(maxit,curr-value);
						queit.pop();
					}
				}
				else
				{
					//printf("curr=%d arr[i]=%d cnt=%d sz=%d\n",curr,arr[i],cnt,sz);
					cnt=cnt-sz;
					rep(j,cnt)
					{
						//printf("pushit arr=%d\n",arr[i]);
						queit.push(curr);
					}
				}
				curr++;
			}
			else
			{
				//printf("not equal curr=%d arr[i]=%d\n",curr,arr[i]);
				while(!(queit.empty()))
				{
					value=queit.front();
					//printf("curr-value=%d\n",curr-value);
					maxit=min(maxit,curr-value);
					queit.pop();
				}
				curr=arr[i];
				while(i<n)
				{
					if(arr[i]==curr)
						queit.push(arr[i]);
					else 
						break;
					i++;
				}
				curr++;
			}
			//printf("i=%d\n",i);
		}
		while(!(queit.empty()))
		{
			value=queit.front();
			//printf("curr-value=%d\n",curr-value);
			//printf("value=%d curr=%d\n",value,curr);
			if(curr==value)
				curr++;
			maxit=min(maxit,curr-value);
			queit.pop();
		}
		printf("%d\n",maxit);
	}
	return 0;
}











