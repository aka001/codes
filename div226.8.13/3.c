#include<stdio.h>
#include<string.h>
int b[1000000];
int main()
{
	int flag1=0,i,len,m,tr1,tr2,a[20],p=0,cnt=0,flag=1;
	long long int s1=0,s2=0;
	char ch[15];
	for(cnt=0;cnt<=11;cnt++)
		a[cnt]=0;
	cnt=1;
	scanf("%s",ch);
	scanf("%d",&m);
	len=strlen(ch);
	for(i=0;i<len;i++)
	{
		if(ch[i]=='1')
			a[i+1]=1;
	}
	/*for(i=1;i<=10;i++)
		if(a[i]==1)
			printf("%d\n",i);*/
	m--;
	cnt=1;
	while(a[cnt]==0 && cnt<=10)
		cnt++;
	if(cnt==11)
	{
		printf("NO\n");
		return 0;
	}
	s1=tr1=b[0]=cnt;
	//printf("%d\n",s1);
	for(i=1;i<=m;i++)
	{
		cnt=1;flag=1;
		while(cnt<=10)
		{
			if(i&01==1)
			{
				if(a[cnt]==1 && s2+cnt>s1 && cnt!=tr1)
				{
					tr2=cnt;
					s2+=cnt;
					b[i]=cnt;
					flag=0;
					break;
				}
			}
			else
			{
				if(a[cnt]==1 && s1+cnt>s2 && cnt!=tr2)
				{
					tr1=cnt;
					s1+=cnt;
					b[i]=cnt;
					flag=0;
					break;
				}
			}
			cnt++;
		}
		printf("%lld %lld\n",s1,s2);
		printf("%d %d\n\n",tr1,tr2);
		//printf("%d\n",flag);
		if(flag==1)
		{
			printf("NO\n");
			flag1=1;
			break;
		}
	}
	if(!(flag1))
	{
		printf("YES\n");
		for(i=0;i<=m;i++)
		{
			printf("%d",b[i]);
			if(i==m)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
