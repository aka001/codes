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
#define lli		long long int
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

int getint()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!=' ')
	{
		s=s<<1 + s<<3 + ch-'0';
		ch=getchar();
	}
	return s;
}
vector <long long int> arr;
int main()
{
	long long int n,calc,x,asum,val,n1,diff,diff1;
	int flag=1,flag1=1,flag2=1,flag3=1;
	sl(n);
	n1=n;
	while(n--)
	{
		sl(val);
		if(flag2==1)
		{
			x=val;
			flag2=0;
		}
		else
		{
			if(val!=x)
			{
				flag3=0;
			}
		}
		arr.pb(val);
	}
	if(n1==1)
	{
		printf("-1\n");
		return 0;
	}
	if(flag3)
	{
		printf("1\n%lld\n",arr[0]);
		return 0;
	}
	sort(arr.begin(),arr.end());
	FOR(i,1,n1)
	{
		calc=arr[i]-arr[i-1];
		if(flag==1)
		{
			diff=calc;
			flag=0;
		}
		else
		{
			if(calc==diff && flag1==1)
			{}
			else if(calc!=diff)
			{
				diff1=calc;
				flag1=0;
			}
			else if(calc!=diff1)
			{
				printf("0\n");
				return 0;
			}
		}
	}
	if(flag1==1)
	{
		if(diff%2==0 && n1==2)
		{
			printf("3\n%lld %lld %lld\n",arr[0]-diff,(arr[0]+arr[1])/2,arr[n1-1]+diff);
			return 0;
		}
		else
		{
			printf("2\n%lld %lld\n",arr[0]-diff,arr[n1-1]+diff);
			return 0;
		}
	}
	else
	{
		if(!((diff1/2==diff && diff1%2==0) || (diff/2==diff1 && diff%2==0)))
		{
			printf("0\n");
			return 0;
		}
	}
	asum=diff;
	if(diff1/2==diff)
		asum=diff1;
	FOR(i,1,n1)
	{
		calc=arr[i]-arr[i-1];
		if(calc==asum)
		{
			printf("1\n%lld\n",(arr[i]+arr[i-1])/2);
			return 0;
		}
	}
	return 0;
}









