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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
char ch[MAX];
int arr[MAX];
set<pair<int,int> > pit;
int main()
{
	int t,i,j,sz,flag,ans,sit,cnt,i1,j1,szit;
	string s,s1;
	si(t);
	while(t--)
	{
		pit.clear();
		ss(ch);
		s="";
		ans=0;cnt=0;
		sz=strlen(ch);
		rep(i,27)
			arr[i]=0;
		rep(i,sz)
			arr[ch[i]-'a']++;
		rep(i,26)
		{
			if(arr[i]!=0)
				pit.insert(mp(arr[i],i));
		}
		szit=pit.size();
		sit=0;
		while(!(pit.empty()))
		{
			i=*(pit.begin());
			if(arr[i]!=0)
			{
				s+=('a'+i);
				arr[i]--;
				while(arr[i]!=0)
				{
					flag=1;
					FOR(j1,i1+1,szit)
					{
						j=pit[j1].S;
						if(arr[j]!=0)
						{
							s+=('a'+j);
							flag=0;
							arr[j]--;
							break;
						}
					}
					if(flag)
					{
						if(s[0]-'a'!=i)
						{
							s1=s;
							sz=s1.size();
							s="";
							s+=('a'+i);
							rep(j,sz)
							{
								s+=s1[j];
							}
							arr[i]--;
							continue;
						}
						ans=-1;
						break;
					}
					s+=('a'+i);
					arr[i]--;
				}
				//trace5(cnt,i,s,sit,s[sit-1]);
			}
		}
		if(ans==-1)
			cout<<ans<<endl;
		else
		{
			cout<<s<<endl;
		}
	}
	return 0;
}













