#include<cstdio>
#include<cstdlib>
#define zxc 300000
using namespace std;
int n,m,u[zxc],v[zxc],next[zxc],head[zxc],a[zxc],b[zxc],c[zxc],ans;
bool bo[zxc];
void make(int x,int y)
{u[++m]=x; v[m]=y; next[m]=head[x]; head[x]=m;}
void dfs(int x,int y,int z)
{
	int i;
	bo[x]=true;
	if((a[x]^y)!=b[x])
	{
		c[++ans]=x;
		y=1-y; 
	}
	for(i=head[x];i;i=next[i]) if(bo[v[i]]==false) dfs(v[i],z,y);
	return ;
}
int main()
{
	int i,r1,r2;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&r1,&r2);
		make(r1,r2);
		make(r2,r1);
	}
	for(i=1;i<=n;i++) scanf("%d",&a[i]); for(i=1;i<=n;i++) scanf("%d",&b[i]);
	dfs(1,0,0);
	printf("%d\n",ans); 
	for(i=1;i<=ans;i++) printf("%d\n",c[i]);
	return 0;
}
