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
#define pb push_back
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
int ch[333][777], cnt[333], arr[MAX];
int main()
{
	int n,i,j,val,vit,sz,x,vit1,k,flag,mit=700,vin;
	si(n);
	FOR(i,1,n+1)
		si(arr[i]);
	arr[0]=0; cnt[0]=0;
	FOR(i,1,n+1)
	{
		vit=arr[i];
		sz=arr[i-1];
		rep(j,sz)
			ch[i][j]=ch[i-1][j];
		rep(j,mit)
		{
			vit1=vit; val=0;
			rep(k,mit)
				ch[i][k]=ch[i-1][k];
			if(ch[i][j]==9)
				continue;
			ch[i][j]++;
			rep(k,j)
				ch[i][k]=0;
			rep(k,mit)
				val+=ch[i][k];
			vit1-=val;
			if(vit1<0)
				continue;
			rep(k,mit)
			{
				vin=ch[i][k];
				ch[i][k]=max(ch[i][k], min(9, ch[i][k]+vit1));
				vit1-=min(9-vin, ch[i][k]-vin);
				if(vit1<=0)
					break;
			}
			if(vit1==0)
			{
				cnt[i]=k;
				break;
			}
			else
				continue;
		}
	}
	FOR(i,1,n+1)
	{
		flag=0;
		for(j=mit; j>=0; j--)
		{
			if(ch[i][j]!=0)
				flag=1;
			if(flag)
				printf("%d",ch[i][j]);
		}
		printf("\n");
	}
	return 0;
}













