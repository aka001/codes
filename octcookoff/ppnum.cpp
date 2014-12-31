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
long long int a[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
long long int ans1[]={45,9810,1483650,197982000,749774832,997279217,966074507,362800007,765000252,24570};
int digit(long long int n)
{
	int c=0;
	while(n!=0)
	{
		c+=1;
		n/=10;
	}
	return c;
}
long long int calc(long long int ar, long long int b)
{
	int n;
	long long int ans=0;
	ans=((b-ar+1)*(ar+b))/2;
	return ans%1000000007;
}
long long int doit(long long int ar, long long int num)
{
	long long int ans;
	ans=((a[num]-ar)*(ar+a[num]-1))/2;
	ans%=1000000007;
	ans*=num;
	ans%=1000000007;
	return ans;
}
long long int doit1(long long int ar, long long int num)
{
	long long int ans;
	ans=((ar-a[num-1]+1)*(ar+a[num-1]))/2;
	ans%=1000000007;
	ans*=num;
	ans%=1000000007;
	return ans;
}
long long int doit2(long long int x, long long int y, int num)
{
	long long int ans;
	ans=((y-x+1)*(x+y))/2;
	ans%=1000000007;
	ans*=num;
	ans%=1000000007;
	return ans;
}
int main()
{
	int t,d1,d2,i;
	long long int x,y,an;
	si(t);
	while(t--)
	{
		an=0;
		sl(x);sl(y);
		d1=digit(x);
		d2=digit(y);
		if(d1==d2)
			printf("%lld\n",doit2(x,y,d1));
		else
		{
			an+=doit(x,d1);
			for(i=d1+1;i<d2;i++)
			{
				an=an+ans1[i-1];
				an%=1000000007;
			}
			an+=doit1(y,d2);
			//printf("check=%lld",doit1(y,d2));
			an%=1000000007;
			printf("%lld\n",an);
		}
	}
	return 0;
}














