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
#define F first
#define S second
#define mod (ll)(1e9 + 7)
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
ll arr[30][30],n,m,visited[30][30][30][30][3];
char ch[30];
ll fin=mod;
typedef struct node
{
	int ax, ay, gx, gy, flag,ans;
}node;
queue<node> Qit;
node make_node(int ax, int ay, int gx, int gy, int flag, int ans)
{
	node ndit;
	ndit.ax=ax;
	ndit.ay=ay;
	ndit.gx=gx;
	ndit.gy=gy;
	ndit.flag=flag;
	ndit.ans=ans;
	return ndit;
}
void compute()
{
	if(Qit.empty())
	{
		return;
	}
	node pit;
	pit = Qit.front();
	Qit.pop();
	int ax,ay,gx,gy,flag,ans;
	ax=pit.ax; ay=pit.ay; gx=pit.gx; gy=pit.gy; flag=pit.flag; ans=pit.ans;
	if(ax<=0 || ax>n || ay<=0 || ay>m || gx<=0 || gx>n || gy<=0 || gy>m || visited[ax][ay][gx][gy][flag] || (ax==gx && ay==gy))
	{
		compute();
	}
	else if(arr[ax][ay]==5 && (ax!=gx || ay!=gy) && flag==0)
	{
		fin=ans;
		return;
	}
	else if(flag==1)
	{
		visited[ax][ay][gx][gy][flag]=1;
		if(arr[gx][gy]==4)
			Qit.push(make_node(ax,ay,gx,gy,1-flag,ans));
		else if(gy<ay)
			Qit.push(make_node(ax,ay,gx,gy+1,1-flag,ans));
		else if(gy>ay)
			Qit.push(make_node(ax,ay,gx,gy-1,1-flag,ans));
		else if(gx>ax)
			Qit.push(make_node(ax,ay,gx-1,gy,1-flag,ans));
		else if(gx<ax)
			Qit.push(make_node(ax,ay,gx+1,gy,1-flag,ans));
		compute();
	}
	else if(flag==0)
	{
		visited[ax][ay][gx][gy][flag]=1;
		if(arr[ax][ay]!=4)
		{
			Qit.push(make_node(ax+1,ay,gx,gy,1-flag,1+ans));
			Qit.push(make_node(ax,ay+1,gx,gy,1-flag,1+ans));
			Qit.push(make_node(ax-1,ay,gx,gy,1-flag,1+ans));
			Qit.push(make_node(ax,ay-1,gx,gy,1-flag,1+ans));
		}
		compute();
	}
}
int main()
{
	ll i,j,ax,ay,gx,gy,ans;
	sl(n); sl(m);
	FOR(i,1,n+1)
	{
		ss(ch);
		FOR(j,1,m+1)
		{
			if(ch[j-1]=='A')
			{
				ax=i; ay=j;
				arr[i][j]=1;
			}
			else if(ch[j-1]=='G')
			{
				gx=i; gy=j;
				arr[i][j]==2;
			}
			else if(ch[j-1]=='.')
				arr[i][j]=3;
			else if(ch[j-1]=='X')
				arr[i][j]=4;
			else
				arr[i][j]=5;
		}
	}
	node str;
	str.ax=ax; str.ay=ay; str.gx=gx; str.gy=gy; str.flag=0; str.ans=0;
	Qit.push(str);
	compute();
	if(fin==mod)
		fin=-1;
	pln(fin);
	return 0;
}













