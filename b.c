#include<stdio.h>
#include<string.h>
char a[100000][1000];
char b[1000000];
int main()
{
	int i,n,p=0,flag,flag1,flag2,cnt,len;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	scanf("%s",b);
	len=strlen(b);
	for(i=0;i<len;)
	{
		flag1=flag2=flag=0;
		if(b[i]=='<' || b[i]=='>' || (b[i]>='0' && b[i]<='9'))
		{
			//printf("i=%d\n",i);
			while((b[i]=='<' || b[i]=='>' || (b[i]>='0' && b[i]<='9') && i<len))
			{
				if(b[i]=='<')
					flag1=1;
				if(b[i]=='3')
					flag2=1;
				i++;
			}
			if(flag1==1 && flag2==1)
			{
				if(i==len)
				{
					if(p!=n)
					{
						flag=1;
						break;
					}
					else
						break;
				}
				cnt=0;
				char check[100001];
				while((b[i]>='a' && b[i]<='z') && i<len)
				{
					check[cnt++]=b[i];
					i++;
				}
				check[cnt]='\0';
				if(strcmp(check,a[p++])!=0)
				{
					//printf("idhar %s %d\n",check,i);
					flag=1;
					break;
				}
			}
			else
			{
				//printf("%d\n",i);
				flag=1;
				break;
			}
		}
		else
		{
			//printf("%d\n",i);
			flag=1;
			break;
		}
		//printf("i=%d\n",i);
	}
	if(!(flag) && p==n)
		printf("yes\n");
	else
		printf("no\n");
}











