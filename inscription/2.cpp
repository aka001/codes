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
#define pill(n)         printf("%lld\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int main()
{
	int a,b,c,calc,max,min,mid,t,sum;
	si(t);
	while(t--)
	{
		si(a);
		si(b);
		si(c);
		max=a;
		min=a;
		if(b>max)
			max=b;
		if(c>max)
			max=c;
		if(b<min)
			min=b;
		if(c<min)
			min=c;
		mid=a+b+c-max-min;
		if(max>min+mid)
			printf("Alice\n");
		else
		{
			sum=min+mid+max;
			if(sum%2==1)
				printf("Alice\n");
			else
				printf("Bob\n");
		}
		//printf("%d\n",calc);
		//printf("%d\n",calc);
		/*if(min==mid && mid==max)
		{
			if(min%2==1)
				printf("Alice\n");
			else
				printf("Bob\n");
		}
		else if(min==mid && mid!=max)
		{
			if((min%2==0 && max%2==0)||(min%2==1 && max%2==1))
				printf("Bob\n");
			else
				printf("Alice\n");
		}
		else
		{
			printf("Alice\n");
		}*/
	}
	return 0;
}











