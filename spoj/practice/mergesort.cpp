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
int temp[1000006],arr[1000006];
int merge(int l, int mid,int r)
{
	int i=l,j=mid+1,k=0;
	while(i<=mid && j<=r)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
			temp[k++]=arr[j++];
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=r)
		temp[k++]=arr[j++];
	k=0;
	for(i=l;i<=r;i++)
	{
		arr[i]=temp[k++];
	}
}
void mergesort(int l, int r)
{
	if(l<r)
	{
		int mid;
		mid=(l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
int main()
{
	int calc,n=0,i;
	char ch;
	ch='1';
	while(ch!=EOF && ch!='\0')
	{
		ch=getchar();
		calc=0;
		while(ch!=10 && ch!=EOF && ch!='\0' && ch!=' ')
		{
			calc=calc*10+ch-'0';
			//printf("ch=%c\n",ch);
			ch=getchar();
		}
		arr[n++]=calc;
		if(ch==10)
			break;
	}
	mergesort(0,n-1);
	//printf("hie\n");
	rep(i,n)
	{
		printf("%d",arr[i]);
		if(i!=n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}








