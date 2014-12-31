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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int arr[1000006],sz;
char ch[1000006];
vector<int> fin;
int segment_tree(int node,int a,int b)
{
	if(a==b)
	{
		arr[node]=a;
		return a;
	}
	else
	{
		int val1,val2;
		val1=segment_tree(2*node,a,(a+b)/2);
		val2=segment_tree(2*node+1,(a+b)/2+1,b);
		if(ch[val1]>ch[val2])
			arr[node]=val1;
		else if(ch[val2]>ch[val1])
			arr[node]=val2;
		else
			arr[node]=min(val1,val2);
		return arr[node];
		//printf("p=%d q=%d node=%d val=%d val1=%d val2=%d\n",a,b,node,arr[node],val1,val2);
	}
}
int query(int node,int p,int q,int a,int b)
{
	if(p>=a && q<=b)
	{
		//printf("p=%d q=%d val=%d\n",p,q,arr[node]);
		return arr[node];
	}
	else if(q<a || p>b || p>q)
		return -mod;
	else
	{
		int val1,val2;
		//printf("p=%d q=%d\n",p,q);
		val1=query(2*node,p,(p+q)/2,a,b);
		val2=query(2*node+1,(p+q)/2+1,q,a,b);
		if(val1<0)
			return val2;
		else if(val2<0)
			return val1;
		else if(ch[val1]>ch[val2])
			return val1;
		else if(ch[val1]<ch[val2])
			return val2;
		else
			return min(val1,val2);
	}
}
void recursion(int l,int h,int kit,int count)
{
	int val,left,right,i,calc;
	if(kit==0 || l>h || l<0 || h>=sz)
		return;
	val=query(1,0,sz-1,l,h);
	//printf("l=%d h=%d val=%d\n",l,h,val);
	left=val-l;
	right=h-val;
	calc=h-l+1;
	if(kit==calc)
	{
		//printf("cond 1\n");
		//printf("left=%d right=%d calc=%d kit=%d\n",l,h,calc,kit);
		for(i=l;i<=h;i++)
			fin.pb(i);
		return;
	}
	if(kit>=left)
	{
		//printf("cond 2 left=%d\n",left);
		for(i=l;i<val;i++)
			fin.pb(i);
		if(val<sz-1)
		{
			//printf("kit modified=%d\n",kit-left);
			recursion(val+1,h,kit-left,count+1);
		}
	}
	else
	{
		//printf("cond 3\n");
		if(val>0)
			recursion(l,val-1,kit,count+1);
	}
}
int main()
{
	int t,i,k,low,endit;
	si(t);
	while(t--)
	{
		fin.clear();
		ss(ch);
		si(k);
		sz=strlen(ch);
		if(sz==k)
		{
			cout<<endl;
			continue;
		}
		segment_tree(1,0,sz-1);
		//printf("1 3 %d\n",query(1,0,3,1,3));
		/*printf("0 1 %d\n",query(1,0,3,0,1));
		printf("2 3 %d\n",query(1,0,3,2,3));*/
		//printf("hie\n");
		recursion(0,sz-1,k,0);
		//printf("hie again\n");
		/*sz=fin.size();
		rep(i,sz)
			printf("%d ",fin[i]);
		printf("\n");*/
		sort(fin.begin(),fin.end());
		endit=fin.size();
		rep(i,sz)
		{
			low=lower_bound(fin.begin(),fin.end(),i)-fin.begin();
			//printf("low=%d\n",low);
			if(!(low!=endit && fin[low]==i))
				printf("%c",ch[i]);
		}
		printf("\n");
	}
	return 0;
}











