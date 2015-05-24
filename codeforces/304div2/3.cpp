/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define MAX 1000006
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
queue<int> arr,brr;
//int arr[MAX],brr[MAX];
map<pair<int,int>, int > mapit;
int main()
{
	int n,k1,k2,i,cnt=0,l1,u1,l2,u2,c1,c2,calc,j,ans,s1,s2,mit,val;
	mit=modpow(10,6,mod);
	si(n);
	si(k1);
	c1=0;
	calc=1;
	rep(i,k1)
	{
		si(val);
		c1=c1+val*calc;
		calc<<=1;
		arr.push(val);
		//si(arr[i]);
	}
	c2=0;
	calc=1;
	si(k2);
	rep(i,k2)
	{
		si(val);
		c2=c2+val*calc;
		calc<<=1;
		brr.push(val);
		//si(brr[i]);
	}
	l1=0;u1=k1;
	l2=0;u2=k2;
	while(1)
	{
		calc=1;

	/*	for(it=arr.begin();it!=arr.end();it++)
		{
			c1=c1+(*it)*calc;
			calc<<=1;
		}*/
		/*FOR(j,l1,u1)
		{
			calc<<=1;
		}*/
		/*calc=1;
		for(it=brr.begin();it!=brr.end();it++)
		{
			c2=c2+(*it)*calc;
			calc<<=1;
		}*/
		s1=arr.size();
		s2=brr.size();
		if(s1==0 || s2==0)
		{
			if(s1==0)
				ans=2;
			else
				ans=1;
			break;
		}
		if(mapit.find(mp(c1,c2))!=mapit.end())
		{
			ans=-1;
			break;
		}
		//trace2(c1,c2);
		mapit[mp(c1,c2)]=1;
		//trace2(c1,c2);
		c1-=arr.front();c1/=2;
		c2-=brr.front();c2/=2;
		if(arr.front()<brr.front())
		{
			calc=brr.size();
			brr.pb(arr.front());
			brr.pb(brr.front());
			c2+=(1<<calc)*arr.front();
			calc++;
			c2+=(1<<calc)*brr.front();
			arr.pop();
			brr.pop();
		}
		else
		{
			calc=arr.size();
			arr.pb(brr.front());
			arr.pb(arr.front());
			c1+=(1<<calc)*brr.front();
			calc++;
			c1+=(1<<calc)*arr.front();
			arr.pop();
			brr.pop();
		}
		cnt++;
	}
	if(ans==-1)
		pin(ans);
	else
	{
		printf("%d %d\n",cnt,ans);
	}
	return 0;
}













