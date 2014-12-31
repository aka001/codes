/**Author: Akash Agrawall
Institution: IIIT Hyderabad **/
#include<stdio.h>
#include<string.h>
#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
int main()
{
	char ch[10][100];
	char ch[0]={'-','-','-','-','-'};
	strcpy(ch[0],"-----");
	strcpy(ch[1],".----");
	strcpy(ch[2],"..---");
	strcpy(ch[3],"...--");
	strcpy(ch[4],"....-");
	strcpy(ch[5],".....");
	strcpy(ch[6],"-....");
	strcpy(ch[7],"--...");
	strcpy(ch[8],"---..");
	strcpy(ch[9],"----.");
	int t;
	char ch1;
	si(t);
	getchar();
	while(t--)
	{
		ch1=getchar();
		while(ch1!='\n' || ch1!='\0')
		{
			printf("%s",ch[ch1-'0']);
			ch1=getchar();
		}
		printf("\n");
		getchar();
	}
	return 0;
}








