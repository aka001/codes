#include<stdio.h>
int a[1000000];
int compare(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int i,n,m,calc,calc1;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,m,sizeof(int),compare);
	calc=a[n-1]-a[0];
	for(i=1;i<=m-n;i++)
	{
		calc1=a[i+n-1]-a[i];
		if(calc1<calc)
			calc=calc1;
	}
	printf("%d\n",calc);
	return 0;
}
