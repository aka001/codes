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
#include<assert.h>
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
pair<ll,ll> Q[3000006],Q1[3000006];
ll sz,dist[3002][3002];
inline double findslope(double x1, double y1, double x2, double y2)
{
	if(x1==x2)
		return mod;
	else
		return (y2-y1)/((x2-x1)*1.0);
}
int searchit(pair<ll,ll> sv)
{
	ll lb=-1,hb=-1,low,high,mid,p=sv.F,q=sv.S;
	low=0;
	high=sz-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(Q[mid].F==p && (mid==sz-1 || Q[mid+1].F>p))
		{
			hb=mid;
			break;
		}
		else if(p>=Q[mid].F)
			low=mid+1;
		else
			high=mid-1;
	}
	if(hb==-1)
		return -1;
	low=0;
	high=sz-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(Q[mid].F==p && (mid==0 || Q[mid-1].F<p))
		{
			lb=mid;
			break;
		}
		else if(p>Q[mid].F)
			low=mid+1;
		else
			high=mid-1;
	}
	if(lb==-1)
		return -1;
	low=lb;
	high=hb;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(Q[mid].S==q)
		{
			return mid+1;
		}
		else if(q>Q[mid].S)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
bool compare(pair<ll,ll> p, pair<ll,ll> q)
{
	if(p.F==q.F)
		return p.S<q.S;
	return p.F<q.F;
}
int main()
{
	double m,m1,x1,x2,y1,y2,xit,yit,calc,d,calc1,calc2,x1it,y1it,x2it,y2it;
	ll i,j,ans,val,val1,n;
	sl(n);
	rep(i,n)
	{
		sl(val);
		sl(val1);
		Q1[i]=mp(val,val1);
	}
	sort(Q1,Q1+n,compare);
	sz=0;
	rep(i,n)
	{
		if(i==n-1 || (Q1[i].F!=Q1[i+1].F || Q1[i].S!=Q1[i+1].S))
		{
			Q[sz++]=Q1[i];
			//Q.pb(mp(Q1[i].F,Q1[i].S));
		}
	}
	sort(Q,Q+sz,compare);
	if(sz==0)
		ans=4;
	else if(sz==1)
		ans=3;
	else
		ans=2;
	pair<ll,ll> p,q;
	rep(i,sz)
	{
		p=Q1[i];
		FOR(j,i+1,sz)
		{
			q=Q1[j];
			d=(p.S-q.S)*(p.S-q.S)+(p.F-q.F)*(p.F-q.F);
			dist[i][j]=d;
		}
	}
	rep(i,sz)
	{
		FOR(j,i+1,sz)
		{
			p=Q1[i];
			q=Q1[j];
			m=findslope(p.F,p.S,q.F,q.S);
			d=dist[i][j];
			xit=(p.F+q.F)/2.0;
			yit=(p.S+q.S)/2.0;
			if(p.F==q.F && p.S==q.S)
				continue;
			if(m!=0)
			{
				if(m==mod)
					m1=0;
				else
					m1=-1/(m*1.0);
				calc=(d)/(4*(m1*m1+1)*1.0);
				calc=sqrt(calc);
				x1=calc+xit;
				x2=-calc+xit;
				y1=m1*(x1-xit)+yit;
				y2=m1*(x2-xit)+yit;
			}
			else
			{
				x1=xit;
				x2=xit;
				calc=d/(4*1.0);
				calc=sqrt(calc);
				y1=(double)(yit+calc);
				y2=(double)(yit-calc);
			}
			x1it=(double)((ll)x1);
			y1it=(double)((ll)y1);
			x2it=(double)((ll)x2);
			y2it=(double)((ll)y2);
			if(!(x1it==x1 && y1it==y1 && x2it==x2 && y2it==y2))
				continue;
			if(x1==x2 && y1==y2)
			{
				continue;
			}
			calc1=searchit(mp(x1,y1));
			calc2=searchit(mp(x2,y2));
			//printf("%lld %lld %lld %lld  xit=%.1f yit=%.1f %.1f %.1f %.0f %.0f calc=%.2f m1=%.0f d=%.0f\n",p.F,p.S,q.F,q.S,xit,yit,x1,y1,x2,y2,calc,m1,d);
			if(calc1!=-1 || calc2!=-1)
			{
				//printf("Hie\n");
				ans=min(ans,1);
				if(calc1!=-1 && calc2!=-1)
				{
					//printf("%lld %lld %lld %lld  %.0f %.0f %.0f %.0f calc=%.0f m1=%.0f d=%.0f\n",p.F,p.S,q.F,q.S,x1,y1,x2,y2,calc,m1,d);
					//printf("calc1=%lld calc2=%lld\n",calc1,calc2);
					ans=0;
					break;
				}
			}
		}
		if(ans==0)
			break;
	}
	pln(ans);
	return 0;
}












