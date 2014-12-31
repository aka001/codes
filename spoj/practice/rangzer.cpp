#include<bits/std++.h>
using namespace std;
int dp[15];
int count(int a)
{
	int buffer[15],i,sz=0,temp,ans=0;
	while(a!=0)
	{
		buffer[sz++]=a%10;
		a/=10;
	}
	for(i=0;i<sz/2;i++)
	{
		temp=buffer[i];
		buffer[i]=buffer[sz-i-1];
		buffer[sz-i-1]=temp;
	}
	for(i=0;i<sz;i++)
	{
		ans+=(buffer[i]-0)*dp[sz-i-1];
	}
	return ans;
}
int main()
{
	int t,a,b,i,calc,c1,c2;
	scanf("%d",&t);
	c1=10;
	c2=9;
	dp[0]=0;
	for(i=1;i<=9;i++)
	{
		val=c1-c2;
		dp[i]=val;
		c1*=10;
		c2*=9;
	}
	while(t--)
	{
		scanf("%d %d",&a,&b);
		calc=count(b)-count(a-1);
		printf("%d\n",calc);
	}
}
