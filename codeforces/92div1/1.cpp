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
int val[MAX], isprime[MAX], freq[MAX], fit[MAX];
char allocate[MAX], disp[MAX];
vector<int> primeit;
set<pair<int,int> > stit;
void seive()
{
	ll i,j;
	isprime[0]=isprime[1]=1;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
			primeit.pb(i);
	}
}
int main()
{
	int i,sz,cnt,calc,cit=0,aka,a1,a2,mxit,sit,j;
	char iiit;
	seive();
	ss(ch);
	sz=strlen(ch);
	i=0;
	while(primeit[i]<=sz)
	{
		cit++;
		calc=primeit[i];
		cnt=1;
		aka=0;
		while(calc*cnt<=sz)
		{
			if(val[calc*cnt]!=0)
			{
				aka=val[calc*cnt];
				break;
			}
			else
				val[calc*cnt]=cit;
			cnt++;
		}
		if(aka!=0)
		{
			calc=primeit[i];
			cnt=1;
			while(calc*cnt<=sz)
			{
				val[calc*cnt]=aka;
				cnt++;
			}
			cit--;
		}
		i++;
	}
	FOR(i,1,sz+1)
	{
		fit[ch[i-1]]++;
		if(val[i]==0)
			continue;
		if(stit.find(mp(freq[val[i]], val[i]))!=stit.end())
		{
			stit.erase(stit.find(mp(freq[val[i]], val[i])));
		}
		freq[val[i]]++;
		stit.insert(mp(freq[val[i]], val[i]));
		sit=stit.size();
	}
	pair<int,int> aaa;
	while(!(stit.empty()))
	{
		aaa=*(stit.rbegin());
		stit.erase(stit.find(*stit.rbegin()));
		a1=aaa.F;
		a2=aaa.S;
		mxit= -1;
		FOR(i,97,123)
		{
			if(fit[i]>mxit)
			{
				mxit=fit[i];
				iiit=i;
			}
		}
		if(mxit<a1)
		{
			printf("NO\n");
			return 0;
		}
		allocate[a2]=iiit;
		fit[iiit]-=a1;
	}
	string str="";
	FOR(i,'a','z'+1)
	{
		if(fit[i]!=0)
			str+=i;
	}
	FOR(i,1,sz+1)
	{
		FOR(j,1,sz+1)
		{
			if(val[j]==i)
				disp[j]=allocate[val[j]];
		}
	}
	cnt=0;
	FOR(i,1,sz+1)
	{
		if(val[i]==0)
			disp[i]=str[cnt++];
	}
	printf("YES\n");
	FOR(i,1,sz+1)
		cout<<disp[i];
	cout<<endl;
	return 0;
}













