#include<stdio.h>
int a[10000000];
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	int i,j,calc,t,c,d,e,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&c,&d);
		e=gcd(c,d);
		e=(c*d)/e;
		n=e/c;
		for(i=0;i<=e && i<=1000000;i+=c)
		{
			//calc=i;
			for(j=0;i+j<=e && i+j<=1000000;j+=d)
			{
				a[i+j]=1;
			}
		}
		for(i=e;i>=0;i--)
		{
			if(a[i]==0)
			{
				ans=i;
				break;
			}
			if(a[i]==1)
				a[i]==0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
