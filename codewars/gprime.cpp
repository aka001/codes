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

#define fork(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	fork(i,0,n)
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
int l;
string ans;
long long int b[10000005],c[10000005],a[10000005];
int getit()
{
	char ch;
	int ans=0;
	ch=getchar();
	while(ch!=' ' && ch!='\n')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
int main()
{
	long long int i,j,k;
	int n,t,num,x;
	for(i=0;i<=1000000;i++)
		a[i]=i;
	c[0]=0;c[1]=0;c[2]=3;b[0]=0;b[1]=0;
	for(i=2;i<=3162;i++)
	{
		if(b[i]==0)
		{
			a[i]=i-1;
			a[i*i]=(a[i*i]*(i-1))/i;
			for(j=i*(i+1);j<=10000000;j+=i)
			{
				a[j]=(a[j]*(i-1))/i;
				//if(j!=i*i)
				a[j]=(a[j]*(j/i-1))/(j/i);
				b[j]=1;
			}
		}
		c[i]=a[i-1]*2+c[i-1];
	}
	/*rep(i,10000000)
	{
		if(b[i]==1)
			a[i]=i-1;
	}*/
	/*for(i=2;i<=50;i++)
	{
		printf("%lld %lld\n",i,a[i]);
	}*/
	
	x=3162;
	t=getit();
	while(t--)
	{
		n=getit();
		if(n<x)
			printf("%lld\n",c[n]);
		else
		{
			fork(i,x,n)
				c[i]=a[i-1]*2+c[i-1];
			printf("%lld\n",c[n]);
			x=n-1;
		}
	}
	return 0;
}




