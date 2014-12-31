#include<stdio.h>
int a[10005],b[10005];
int main()
{
	int t,u,l,temp,i,j,cnt=0,s=0,calc;
	a[0]=1;a[1]=1;
	for(i=2;i<=100;i++)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<=10000;j+=i)
			{
				a[j]=1;
			}
		}
	}
	for(j=1;j<=10000;j++)
	{
		temp=j;
		s=0;
		while(temp!=0)
		{
			calc=temp%10;
			s+=calc;
			temp/=10;
		}
		if(a[s]==0)
			cnt++;
		//if(j<=20)
		//	printf("%d %d %d\n",j,s,cnt);
		b[j]=cnt;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&u);
		printf("%d\n",b[u]-b[l-1]);
	}
	return 0;
}
