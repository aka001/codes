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
vector<pair<int,int> > qit;
map<int,int> mpit,pmit,trck;
int sg[1000006],sz,st[200009];
//Initializing the segment tree
void initialize(int node,int b, int e)
{
	if(b==e)
	{
		sg[node]=0;
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,(b+e)/2+1,e);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Updating the segment tree for the values which are to be deleted/inserted
inline void update(int node, int b, int e, int ch, int val)
{
	if(b==e && b==ch)
		sg[node]=val;
	else if(b!=e)
	{
		update(2*node, b, (b+e)/2, ch, val);
		update(2*node+1, (b+e)/2+1, e, ch, val);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Finding the count of the numbers lesser than a given number
inline int sumit(int node, int b, int e, int x, int y)
{
	if(b>y || e<x)
		return 0;
	else if(b>=x && e<=y)
		return sg[node];
	else
	{
		int p1,p2;
		p1=sumit(2*node, b, (b+e)/2, x, y);
		p2=sumit(2*node+1, (b+e)/2+1, e, x, y);
		return p1+p2;
	}
}
//Counting the kth smallest number using binary search.
//FYI It also uses the sumit function.
inline int binary(int val)
{
	int low=0,high=sz-1,mid,cl,cl1,mid1;
	while(low<=high)
	{
		mid=(low+high)/2;
		mid1=mid-1;
		cl=sumit(1,0,sz-1,0,mid);
		if(mid!=0)
			cl1=sumit(1,0,sz-1,0,mid-1);
		else
			cl1=-1;
		if(cl==val && cl1!=val)
		{
			return mid;
		}
		else if(val>cl)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
}
//Using fast input.
int inpit()
{
	char ch;
	int val=0,flit=0;
	cin>>ch;
	while(ch!='\n' && ch!='\0')
	{
		if(ch=='-')
		{
			flit=1;
			cin>>ch;
			continue;
		}
		else if(ch==' ')
		{
			cin>>ch;
			cin>>ch;
			continue;
		}
		val=val*10+ch-'0';
		printf("ch=%c\n",ch);
		cin>>ch;
	}
	if(flit==1)
		val=-val;
	return val;
}
int main()
{
	//For fast output using cout
	std::ios_base::sync_with_stdio( false );
	cin.sync_with_stdio(false);
	int q,val,val1,ans,i,cnt;
	char ch[10],ch1;
	cin>>q;
	sz=0;
	rep(i,q)
	{
		cin>>ch1;
		if(ch1=='I')
			val=1;
		else if(ch1=='D')
			val=2;
		else if(ch1=='K')
			val=3;
		else if(ch1=='C')
			val=4;
		cin>>val1;
		qit.pb(mp(val,val1));
		if(val==1 || val==2 || val==4)
		{
			//Storing all distinct values for coordinate compression
			if(trck[val1]==0)
			{
				st[sz++]=val1;
				trck[val1]=1;
			}
		}
	}
	sort(st,st+sz);
	initialize(1,0,sz-1);
	cnt=0;
	for(i=0;i<sz;i++)
	{
		//Co-ordinate compression
		//Mapping the values
		mpit[st[i]]=i;
		//Reverse mapping the values
		pmit[i]=st[i];
		cnt++;
	}
	rep(i,q)
	{
		val=qit[i].F;
		val1=qit[i].S;
		if(val==1)
		{
			//Inserting the value
			update(1,0,sz-1,mpit[val1],1);
		}
		else if(val==2)
		{
			//Deleting the value
			update(1,0,sz-1,mpit[val1],0);
		}
		else if(val==3)
		{
			//Counting kth smallest value
			ans=binary(val1);
			if(ans==-1)
			{
				cout<<"invalid\n";
				continue;
			}
			ans=pmit[ans];
			cout<<ans<<"\n";
		}
		else if(val==4)
		{
			//Counting all numbers smaller than a given value
			if(mpit[val1]==0)
				ans=0;
			else
				ans=sumit(1,0,sz-1,0,mpit[val1]-1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}



