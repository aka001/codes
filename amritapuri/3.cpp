/**Author: Akash Agrawall
  Institution: IIIT Hyderabad **/
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
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l,m,n;
string ans;
char a[100][100];



int funct(int x, int y, int c, int d)
{
	int i,j;
	int breaker[1000];
	int broke[1000];
	int breakctr=0;
	int flag=0;
	int spc_flag=0;
	int count=1,ox=x,oy=y,oc=c,od=d;
	while(1)
	{
		if(x>=n || c>=n)//agar x waala galat nikla to ho gaya dekhna
		{
			break;
		}
		if(a[x][y]==a[c][d])
			flag++;
		else//break pyaar se
		{
			if(spc_flag==1)
				break;
			if(flag==0)
				break;
			broke[breakctr]=x;
			breaker[breakctr++]=y-1;
			y=oy;
			x++;
			c++;
			d=od;
			spc_flag++;
			if(x>=n || c>=n)//agar x waala galat nikla to ho gaya dekhna
			{
				break;
			}
			continue;
			/*x=++ox;
			y=oy;
			c=++oc;
			d=od;
			continue;*/

		}
		//overflow ho raha hai
		if(y==m-1 || d==m-1)
		{
			//printf("inerting %d %d\n",x,y);
			broke[breakctr]=x;
			breaker[breakctr++]=y;
			y=oy;
			x++;
			c++;
			d=od;
		}
		else//har baar yeh hona hai agar koi exception nahi hai
		{
			++y;
			++d;
		}
		/*//overflow ho raha hai
		if(d==m-1)
		{
			d=od;
			c++;
		}
		else
			++d;
		*/
	}
	int tmp_ctr=-1;
	int tmpo;
	int wo_flag=0;
	for(i=0;i<breakctr-1;i++)
	{
		if(breaker[i]<breaker[i+1])
		{
			wo_flag=1;
			break;
		}
	}
	if(breakctr>0)
//		printf("break count %d\n",breakctr);
	if(!wo_flag)
	{
	for(i=0;i<breakctr;i++)
	{
		
			//calculate the max thing
		int idx;
		/*if(((broke[j]-ox)*(breaker[j]-oy))<=((broke[i]-ox)*(breaker[i]-oy)))
			{
				idx=j;
			}
			else
			{
				idx=i;
			}*/
		idx=i;
//		printf("broke %d %d\n",broke[i],breaker[i]);
		tmpo = (broke[idx]-ox+1)*(breaker[idx]-oy+1);
		if(tmpo>tmp_ctr)
			tmp_ctr=tmpo;

		
	}
	}
	else 
	{
		if(breakctr>0)
		{
		tmpo = (broke[0]-ox+1)*(breaker[0]-oy+1);
		if(tmpo>tmp_ctr)
			tmp_ctr=tmpo;
		}

	}
	return tmp_ctr;
}
int main()
{
	int t,e,f,max,i,doit,j;
	si(t);
	getchar();
	while(t--)
	{
		doit=-1;
		max=-1;
		si(n);si(m);
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				a[i][j]=getchar();
			getchar();
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
		printf("\n");*/
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				e=i;f=j+1;
				for(;e<n;e++)
				{
					if(i==e)
					{
						f=j+1;
					}
					else
					{
						f=0;
					}
					for(;f<m;f++)
					{
						doit=funct(i,j,e,f);
						if(doit!=-1)
						{//printf("%d %d %d %d\n",i,j,e,f);
						//printf("%d %d\n",doit, max);
						}
						if(doit>max)
							max=doit;
					}
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}








