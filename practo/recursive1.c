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
int a[1001][1001];
/*int function(int x, int y)
  {
  if(x==0)
  return y+1;
  else if(x>0 && y==0)
  {
  if(x<=1001)
  return a[x-1][1];
  else
  function(x-1,1);
  }
  else
  {
  if(x<=1000 && y<=1001)
  {
  return a[x-1][a[x][y-1]];
  }
  else
  {
  function(x-1,function(x,y-1));
  }
  }
  }*/
int function(int x, int y)
{
	if(x==0)
		return y+1;
	else if(x>0 && y==0)
	{
		function(x-1,1);
	}
	else
	{
		function(x-1,function(x,y-1));
	}
}

int main()
{
	int i,j,ans;
	for(i=0;i<=1000;i++)
		a[0][i]=i+1;
	for(i=1;i<=1000;i++)
	{
		for(j=0;j<=1000;j++)
		{
			if(j==0)
				a[i][j]=a[i-1][1];
			else
				a[i][j]=a[i-1][a[i][j-1]];
		}
	}
	int x,y;
	si(x);si(y);
	if(x>1000 || y>1000)
	{
		ans=function(x,y);
		printf("%d\n",ans%1000);
	}
	else
		printf("%d\n",a[x][y]%1000);
	return 0;
}









