#include<stdio.h>
#include<stdlib.h>
typedef struct doit
{
	int x,y;
}doit;
doit *a;
int compare(const void *p, const void *q)
{
	const doit *x1=p,*y1=q;
	//x1=(doit)p;y1=(doit)q;
	int v=-x1->x*y1->y+x1->y*y1->x;
	if(v<0)
		v*=-1;
	return v;
}
int main()
{
	int i,n,x,y;
	scanf("%d",&n);
	a=malloc(sizeof(doit)*301);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		a[i].x=x;a[i].y=y;
	}
	qsort(a, n, sizeof(doit), compare);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].x,a[i].y);
	}
	return 0;
}
