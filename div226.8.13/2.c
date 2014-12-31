#include<stdio.h>
int main()
{
	int g,g1,n,m;
	long long int calc;
	scanf("%d %d",&n,&m);
	scanf("%d",&g);
	calc=g-1;
	m--;
	while(m--)
	{
		scanf("%d",&g1);
		if(g1>=g)
			calc+=g1-g;
		else
			calc+=n-g+g1;
		g=g1;
	}
	printf("%lld\n",calc);
	return 0;
}
