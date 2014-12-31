/**Author: Akash Agrawall
Institution: IIIT Hyderabad **/
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

#define FOR(i,a,b) 	for(i= (int )a ; i < (int )b ; ++i)
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
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l,a[1000000];
string ans;
long long int maxSubArraySum(int a[], int size)
{
	long long int max_so_far = 0, max_ending_here = 0;
	int i;
	for(i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if(max_ending_here < 0)
			max_ending_here = 0;
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
} 
int main()
{
	int t,n,i,j,flag=0,oi,v;
	long long int min,sum,sum1;
	si(t);
	while(t--)
	{
		sum=sum1=flag=0;
		min=0;
		si(n);
		rep(i,n)
		{
			si(v);
			a[i]=-v;
			sum+=v;
		}
		min=maxSubArraySum(a,n);
		//printf("lo %lld %lld\n",sum,min);
		sum+=2*min;
		printf("%lld\n",sum);
	}
	return 0;
}












