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
ll arr[50];
vector<ll> comb;
void combinationUtil(ll arr[], ll data[], ll start, ll end, ll index, ll r)
{
	// Current combination is ready to be printed, print iti
	ll i;
	if (index == r)
	{
		ll vit=1,j;
		for (j=0; j<r; j++)
		{
			vit*=data[j];
		}
		comb.pb(vit);
		return;
	}

	// replace index with all possible elements. The condition
	// "end-i+1 >= r-index" makes sure that including one element
	// at index will make a combination with remaining elements
	// at remaining positions
	for (i=start; i<=end && end-i+1 >= r-index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1, r);
	}
}
void printCombination(ll arr[], ll n, ll r)
{
	// A temporary array to store all combination one by one
	ll data[r];

	// Print all combination using temprary array 'data[]'
	combinationUtil(arr, data, 0, n-1, 0, r);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */

int main()
{
	arr[0]=2;
	arr[1]=3;
	arr[2]=5;
	arr[3]=7;
	arr[4]=11;
	arr[5]=13;
	arr[6]=17;
	arr[7]=19;
	arr[8]=23;
	arr[9]=29;
	arr[10]=31;
	arr[11]=37;
	arr[12]=41;
	arr[13]=43;
	arr[14]=47;
	ll t,l,r,n,val,ans,lit,rit,calc,i,j,sz,flag;
	sl(t);
	while(t--)
	{
		flag=0;
		ans=0;
		sl(val);
		sl(l);
		sl(r);
		rep(i,15)
		{
			if(arr[i]>val)
				break;
		}
		n=i;
		for(i=1;i<=n;i++)
		{
			comb.clear();
			printCombination(arr,n,i);
			sz=comb.size();
			//printf("i=%lld sz=%lld\n",i,sz);
			//pln(sz);
			calc=0;
			rep(j,sz)
			{
				val=comb[j];
				if(l%val==0)
					lit=l;
				else
					lit=((l/val)+1)*val;
				rit=(r/val)*val;
				if(lit>r || rit<l)
				{
					continue;
				}
				//printf("i=%lld %lld  %lld\n",i,comb[j],(rit-lit)/val+1);
				calc+=(rit-lit)/val+1;
			}
			if(i%2==0)
				calc*=-1;
			ans+=calc;
			if(flag)
				break;
		}
		pln(ans);
	}
	return 0;
}














