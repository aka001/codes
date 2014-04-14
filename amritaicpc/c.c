#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define pd(a) printf("%d",a)
#define pdn(a) printf("%d\n",a)
#define pld(a) printf("%lld",a)
#define pldn(a) printf("%lld\n",a)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define rep(i,n) FOR(i,0,n)
char tp;
char a[200][200];
int m,n;
int isit(int i,int j)
{
	if(a[i][j]=='F')
	{
		return 1;
	}
	int ctr=0;
	int count=a[i][j]-'0';
	if(i>0 && j>0 && a[i-1][j-1]=='F')
		ctr++;
	if(i>0 && a[i-1][j]=='F')
		ctr++;
	if(j>0 && a[i][j-1]=='F')
		ctr++;
	if(i<m-1 && j<n-1 && a[i+1][j+1]=='F')
		ctr++;
	if(i<m-1 && a[i+1][j]=='F')
		ctr++;
	if(j<n-1 && a[i][j+1]=='F')
		ctr++;
	if(i>0 && j<n-1 && a[i-1][j+1]=='F')
		ctr++;
	if(i<m-1 && j>0 && a[i+1][j-1]=='F')
		ctr++;
	if(ctr==count)
		return 1;
	else
	{
		printf("%d %d %d %c\n",ctr,i+1,j-1,a[i+1][j-1]);
		return 0;
	}
}


int main()
{
	int i,j,k;
	int t;
	sd(t);
	tp=getchar();
	int flag;
	while(t--)
	{
		flag=0;
		sd(m);
		sd(n);
		tp=getchar();
		k=0;
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				tp=getchar();
				a[i][j]=tp;
			}
			tp=getchar();
		}
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
		i=1;j=1;
		flag=0;
		FOR(i,1,m+1)
		{
			FOR(j,1,n+1)
			{
				if(!isit(i,j))
				{
					printf("%d %d\n",i,j);
					flag=1;
					break;
				}

			}
		}
		if(flag)
			printf("Please sweep the mine again!\n");
		else
			printf("Well done Clark!\n");
	}
	return 0;
}
