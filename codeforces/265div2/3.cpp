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
char ch[MAX];
int arr[MAX],n,p;
vector<int> temp;
int transform(int pos,int flag)
{
	int i,j,cnt=0;
	for(i=pos;i<n;i++)
		temp.pb(arr[i]);
	for(i=pos;i<n;i++)
	{
		for(j=1;j<=p;j++)
		{
			//trace4(i,j);
			if((j!=arr[i-1] || i-1<0) && (j!=arr[i-2] || i-2<0))
			{
				arr[i]=j;
				cnt++;
				break;
			}
		}
	}
	if(flag)
	for(i=pos;i<n;i++)
	{
		arr[i]=temp[i-pos];
	}
	if(cnt==n-pos)
		return 1;
	return 0;
}
int main()
{
	int sz,i,val,j,temp,vit;
	val=0;
	si(n);
	si(p);
	//trace2(n,p);
	ss(ch);
	sz=strlen(ch);
	rep(i,sz)
	{
		arr[i]=ch[i]-'a'+1;
		//trace2(i,arr[i]);
	}
	for(i=sz-1;i>=0;i--)
	//for(i=2;i>=2;i--)
	{
		temp=arr[i];
		vit=arr[i];
		for(j=vit+1;j<=p;j++)
		{
			//trace4(i,j,arr[i-1],arr[i-2]);
			if((j!=arr[i-1] || i-1<0) && (j!=arr[i-2] || i-2<0))
			{
				arr[i]=j;
				val=transform(i+1,1);
				//trace3(i,j,val);
				if(val==1)
				{
					break;
				}
			}
		}
		if(val==1)
		{
			arr[i]=j;
			val=transform(i+1, 0);
			break;
		}
		arr[i]=vit;
	}
	if(val)
	{
		rep(i,n)
		{
			printf("%c",96+arr[i]);
			//trace2(i,arr[i]);
		}
		cout<<endl;
	}
	else
		cout<<"NO\n";
	return 0;
}













