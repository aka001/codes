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
	while(ch!=' ' && ch!='\n')
	{
		s=s*10 + ch-'0';
		ch=getchar();
	}
	return s;
}
long long int getlongint()
{
	char ch;
	long long int s=0;
	ch=getchar();
	while(ch!=' ' && ch!='\n')
	{
		s=s*10 + ch-'0';
		ch=getchar();
	}
	return s;
}
inline unsigned long long int power(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int s=a,ans=1,ans1,b1=b;
	double p,p1;
	//unsigned long long int mega=10000000000000000;
	while(b!=0)
	{
		if(b&01==1)
		{
			ans1=ans;
			ans*=s;
			if(ans/s != ans1)
			{
				//	printf("here1\n");
				return -1;
			}
		}
		b>>=1;
		ans1=s;
		if(b==0)
			return ans;
		s=s*s;
		if(s/ans1!=ans1)
			return -1;
	}
	return ans;
}
int a[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main()
{
	int t,flag;
	long long int p1,l,h,mid,n,x,p;
	double z,y;
	t=getint();
	l=sizeof(a)/sizeof(a[0]);
	while(t--)
	{
		flag=0;
		n=getlongint();
		//printf("%lld\n",p);
		FOR(i,0,15)
		{
			p1=a[i];
			l=2;
			h=sqrt(n);
			while(l<=h)
			{
				mid=l+(h-l)/2;
				x=power(mid,p1);
				//if(p1==23)
				//	printf("%lld %lld %lld %lld %lld\n",l,h,mid,p1,x);
				if(x==n)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(x>n || x<0)
					h=mid-1;
				else
					l=mid+1;
			}
			if(flag)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

