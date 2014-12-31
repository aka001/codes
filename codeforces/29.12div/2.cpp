/*Author : Akash Agrawall
 Institution: IIIT Hyderabad*/

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
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef struct node
{
	int v,a,b,t;
}node;
int compare(const void *a, const void *b)
{
	node *x=(node*)a;
	node *y=(node*)b;
	return x->v-y->v;
}
node *arr;
int arr1[1000000],arr2[1000000],n,cnt;
int search(int num, int team)
{
	int x,val,mid,l=0,h=cnt-1;
	while(l<=h)
	{
		mid=(l+h)/2;
		val=arr[mid].v;
		if(num<val)
			h=mid-1;
		else if(num>val)
			l=mid+1;
		else
		{
			break;
		}
	}
	if(team==1)
		x=arr[mid].a;
	else
		x=arr[mid].b;
//	printf("%d %d %d\n",num, mid,x);
	if(mid<n || x<=n/2)
		return 1;
	else
		return 0;
}
char one[1000000],two[1000000];
int main()
{
	arr=(node*)malloc(sizeof(node)*1000000);
	int x,y,a;
	cnt=0;
	si(n);
	rep(i,n)
	{
		si(x);
		si(y);
		arr1[i]=x;
		arr[cnt].v=x;
		arr[cnt].t=1;
		cnt++;
		arr2[i]=y;
		arr[cnt].v=y;
		arr[cnt].t=2;
		cnt++;
	}
	qsort(arr,cnt,sizeof(arr[0]),compare);
	//rep(i,cnt)
	//	pil(arr[i].v);
	if(arr[0].t==1)
		arr[0].a=1;
	else
		arr[0].b=1;
	FOR(i,1,cnt)
	{
		if(arr[i].t==1)
		{
			arr[i].a=arr[i-1].a+1;
			arr[i].b=arr[i-1].b;
		}
		else
		{
			arr[i].a=arr[i-1].a;
			arr[i].b=arr[i-1].b+1;
		}
	}
	rep(i,cnt)
	{
		//printf("%d %d %d\n",arr[i].v,arr[i].a,arr[i].b);
	}
	rep(i,n)
	{
		one[i]=(char)(48+search(arr1[i],1));
		two[i]=(char)(48+search(arr2[i],2));
	}
	printf("%s\n",one);
	printf("%s\n",two);
	return 0;
}







