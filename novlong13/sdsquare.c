/**Author: Akash Agrawall
  Institution: IIIT Hyderabad **/
#include<stdio.h>
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
int check(long long int n)
{
	int flag=1;
	long long int x;
	while(n!=0)
	{
		x=n%10;
		if(x!=0 && x!=1 && x!=4 && x!=9)
		{
			flag=0;
			return 0;
		}
		n/=10;
	}
	return flag;
}
long long int ar[]={1,4,9,49,100,144,400,441,900,1444,4900,9409,10000,10404,11449,14400,19044,40000,40401,44100,44944,90000,144400,419904,490000,491401,904401,940900,994009,1000000,1004004,1014049,1040400,1100401,1144900,1440000,1904400,1940449,4000000,4004001,4040100,4410000,4494400,9000000,9909904,9941409,11909401,14010049,14040009,14440000,19909444,40411449,41990400,49000000,49014001,49140100,49999041,90440100,94090000,94109401,99400900,99940009,100000000,100040004,100140049,100400400,101404900,101949409,104040000,104919049,110040100,111049444,114041041,114490000,144000000,190440000,194044900,400000000,400040001,400400100,404010000,404090404,409941009,414000409,414041104,441000000,449440000,490091044,900000000,990990400,991494144,994140900,1190940100,1401004900,1404000900,1409101444,1444000000,1449401041,1490114404,1990944400,4014109449,4019940409,4041144900,4199040000,4900000000,4900140001,4901400100,4914010000,4914991449,4941949401,4999904100,9044010000,9409000000,9409194001,9410940100,9900449001,9940090000,9994000900,9999400009,10000000000};
int len=sizeof(ar)/sizeof(ar[0]);
int br[1000000];
int main()
{
	int t;
	long long int cnt=0,e,a,b,c,i,d,s=0;
	/*for(i=1;i<=100000;i++)
	{
		e=i*i;
		if(check(e))
		{
			printf("%lld,",e);
			cnt++;
		}
	}*/
	si(t);
	while(t--)
	{
		cnt=0;
		sl(a);sl(b);
		//pill(c);pill(d);
		//printf("%d %d\n",br[c],br[d]);
		i=0;
		while(i<len)
		{
			e=ar[i];
			if(e>b)
				break;
			if(e>=a && e<=b)
				cnt++;
			i++;
		}
		pill(cnt);
	}
	return 0;
}














