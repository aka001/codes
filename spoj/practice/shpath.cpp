/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


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
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
inline ll hashit(char ch[100006])
{
	ll i,sz=strlen(ch),calc=0;
	rep(i,sz)
	{
		calc+=modpow(26,i,mod)*ch[i];
		if(calc>mod)
			calc%=mod;
	}
	return calc;
}
int D[1000006];
pair<int,int> val,calcit;
string ch,ch1;
struct comparator
{
	bool compare(pair<int,int> a, pair<int,int> b)
	{
		if(a.F==b.F)
			return a.S-b.S;
		return a.F-b.F;
	}
};
int main()
{
	std::ios_base::sync_with_stdio( false );
	int n,p,s,i,j,val1,sz,st,end,v,v1,v2,calc1,calc2,val2,r;
	cin>>s;
	//si(s);
	while(s--)
	{
		vector<pair<int,int> > arr[10005];
		map<string,int> mapit;
		cin>>n;
		rep(i,n)
		{
			cin>>ch;
			//v=hashit(ch);
			mapit.insert(pair<string,int>(ch,i+1));
			//mapit[ch]=i+1;
			//printf("ch=%s mapit=%d\n",ch,mapit[ch]);
			//mapit.insert(pair<char*,int>(ch,i+1));
			cin>>p;
			rep(j,p)
			{
				cin>>val1>>val2;
				arr[i+1].pb(mp(val1,val2));
			}
		}
		/*for(map<char*,int>::iterator it=mapit.begin(); it!=mapit.end(); ++it)
			printf("%s %d\n",it->first,it->second);*/
		cin>>r;
		//si(r);
		while(r--)
		{
			priority_queue<pair<int,int>, vector<pair<int,int> >, std::greater<pair<int,int> > > Q;
			//set<pair<int,int> > Q;
			FOR(i,1,n+1)
				D[i]=mod;
			cin>>ch>>ch1;
			//ss(ch);
			//ss(ch1);
			//v1=hashit(ch);
			//v2=hashit(ch1);
			st=mapit[ch];
			end=mapit[ch1];
			//printf("st=%d end=%d\n",mapit[ch],mapit[ch1]);
			v=arr[st].size();
			if(v==0)
			{
				printf("0\n");
				continue;
			}
			Q.push(mp(st,0));
			D[st]=0;
			while(!(Q.empty()))
			{
				val=Q.top();
				Q.pop();
				//printf("hie\n");
				v1=val.F;
				v2=val.S;
				sz=arr[v1].size();
				//printf("v1=%d\n",v1);
				rep(i,sz)
				{
					calcit=arr[v1][i];
					calc1=calcit.F;
					calc2=calcit.S;
					if(D[calc1]>D[v1]+calc2)
					{
						//printf("calc1=%d v1=%d D[v1]=%d + calc2=%d\n",calc1,v1,D[v1],calc2);
						//if(Q.find(mp(calc1,D[calc1]))!=Q.end())
						//	Q.erase(Q.find(mp(calc1,D[calc1])));
						D[calc1]=D[v1]+calc2;
						Q.push(mp(calc1,D[calc1]));
					}
				}
				if(D[end]==1)
					break;
			}
			printf("%d\n",D[end]);
		}
	}
	return 0;
}


















